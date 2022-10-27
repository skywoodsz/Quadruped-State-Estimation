//
// Created by skywoodsz on 22-10-25.
//

#include <kf_estimator/kf_estimator.h>
#include <kf_estimator/robot_math.h>

KF_ESTIMATOR::KF_ESTIMATOR(const ros::NodeHandle &node_handle,
                           const ros::NodeHandle &private_node_handle) :
nh_(node_handle),
pnh_(private_node_handle)
{
    if (pin_model_ == nullptr && pin_data_ == nullptr)
    {
        // Get the URDF on param server, then build model and data
        std::string urdf_string;
        nh_.getParam("/robot_description", urdf_string);
        if (urdf_string.empty())
           ROS_ERROR("Can't find urdf_string");
        pin_model_ = std::make_shared<pinocchio::Model>();
        urdf_ = urdf::parseURDF(urdf_string);
        pinocchio::urdf::buildModel(urdf_, pinocchio::JointModelFreeFlyer(), *pin_model_);
        pin_data_ = std::make_shared<pinocchio::Data>(*pin_model_);
    }

    Reset();

    state_pub_ =
            std::make_shared<realtime_tools::RealtimePublisher<cheetah_msgs::LegsState>>(nh_, "/leg_states", 100);;

    linear_estimate_ = std::make_shared<LinearKFPosVelEstimator>(nh_);

    // 0. get joint
    motor_sub_ = nh_.subscribe<cheetah_msgs::MotorState>("/dog/motor_data", 1, &KF_ESTIMATOR::MotorCallBack, this);

    // 1. get imu data
    initial_yaw_ = 0.;
    imu_sub_ = nh_.subscribe<sensor_msgs::Imu>("/dog/imu_data", 1, &KF_ESTIMATOR::ImuCallBack, this);

    // 2. contact data
    contact_sub_ = nh_.subscribe<cheetah_msgs::LegContact>("/dog/leg_contact", 1, &KF_ESTIMATOR::LegContactCallBack, this);

    timer_ = pnh_.createTimer(ros::Duration(1.0 / 500.0), &KF_ESTIMATOR::update, this);
}

void KF_ESTIMATOR::Reset() {

    imu_flag_ = false; motor_flag_ = false; contact_flag_ = false;

    robot_state_.pos_.setZero();
    robot_state_.linear_vel_.setZero();

    for (int j = 0; j < 4; ++j) {
        robot_state_.foot_pos_[j].setZero();
        robot_state_.foot_vel_[j].setZero();
        robot_state_.bfoot_pos_[j].setZero();
        robot_state_.bfoot_vel_[j].setZero();
    }

}
/**
 * state estimate update
 * @param event
 */
void KF_ESTIMATOR::update(const ros::TimerEvent &event) {
    if(imu_flag_ & motor_flag_ & contact_flag_)
    {
        if (linear_estimate_ != nullptr)
            linear_estimate_->update(robot_state_);
        pinocchioKine();
        publishState();
    }
}

/**
 * flating base forward kinematics
 */
void KF_ESTIMATOR::pinocchioKine() {
    Eigen::VectorXd q(pin_model_->nq), v(pin_model_->nv);

    // world frame
    for (int leg = 0; leg < 4; ++leg)
        for (int joint = 0; joint < 3; ++joint)
        {
            q(7 + leg * 3 + joint) = leg_joints_[leg].joints_[joint].pos;
            v(6 + leg * 3 + joint) = leg_joints_[leg].joints_[joint].vel;
        }

    q.head(7) << robot_state_.pos_, robot_state_.quat_.coeffs();
    v.head(6) << robot_state_.linear_vel_, robot_state_.angular_vel_;

    pinocchio::forwardKinematics(*pin_model_, *pin_data_, q, v);
    pinocchio::computeJointJacobians(*pin_model_, *pin_data_);
    pinocchio::updateFramePlacements(*pin_model_, *pin_data_);

    for (int leg = 0; leg < 4; ++leg)
    {
        pinocchio::FrameIndex frame_id = pin_model_->getFrameId(LEG_PREFIX[leg] + "_foot");
        robot_state_.foot_pos_[leg] = pin_data_->oMf[frame_id].translation();
        robot_state_.foot_vel_[leg] =
                pinocchio::getFrameVelocity(*pin_model_, *pin_data_, frame_id, pinocchio::ReferenceFrame::LOCAL_WORLD_ALIGNED)
                        .linear();
        // body frame
        robot_state_.bfoot_pos_[leg] = robot_state_.foot_pos_[leg] - robot_state_.pos_;
        robot_state_.bfoot_vel_[leg] =
                pinocchio::getFrameVelocity(*pin_model_, *pin_data_, frame_id, pinocchio::ReferenceFrame::LOCAL)
                        .linear();
    }
}

/**
 * publish the leg states
 */
void KF_ESTIMATOR::publishState() {
    ros::Time time = ros::Time::now();
    if (time < ros::Time(0.01))  // When simulate time reset
        last_publish_ = time;
    if (time - last_publish_ > ros::Duration(0.01))  // 100Hz
    {
        last_publish_ = time;
        if (state_pub_->trylock())
        {
            state_pub_->msg_.header.stamp = time;
            for (int leg = 0; leg < 4; ++leg)
            {
                state_pub_->msg_.foot_pos[leg].x = robot_state_.foot_pos_[leg].x();
                state_pub_->msg_.foot_pos[leg].y = robot_state_.foot_pos_[leg].y();
                state_pub_->msg_.foot_pos[leg].z = robot_state_.foot_pos_[leg].z();
                state_pub_->msg_.foot_vel[leg].x = robot_state_.foot_vel_[leg].x();
                state_pub_->msg_.foot_vel[leg].y = robot_state_.foot_vel_[leg].y();
                state_pub_->msg_.foot_vel[leg].z = robot_state_.foot_vel_[leg].z();

                state_pub_->msg_.bfoot_pos[leg].x = robot_state_.bfoot_pos_[leg].x();
                state_pub_->msg_.bfoot_pos[leg].y = robot_state_.bfoot_pos_[leg].y();
                state_pub_->msg_.bfoot_pos[leg].z = robot_state_.bfoot_pos_[leg].z();
                state_pub_->msg_.bfoot_vel[leg].x = robot_state_.bfoot_vel_[leg].x();
                state_pub_->msg_.bfoot_vel[leg].y = robot_state_.bfoot_vel_[leg].y();
                state_pub_->msg_.bfoot_vel[leg].z = robot_state_.bfoot_vel_[leg].z();

            }
            state_pub_->unlockAndPublish();
        }
    }

}

/**
 * get leg contact
 * @param msg
 */
void KF_ESTIMATOR::LegContactCallBack(const cheetah_msgs::LegContact::ConstPtr &msg) {
    cheetah_msgs::LegContact contact_state = *msg;

    for (int j = 0; j < 4; ++j) {
        robot_state_.contact_state_[j] = contact_state.contact_state[j];
    }

    contact_flag_ = true;
}

/**
 * get motor joint data
 * @param msg
 */
void KF_ESTIMATOR::MotorCallBack(const cheetah_msgs::MotorState::ConstPtr &msg) {
    cheetah_msgs::MotorState motor_data = *msg;

    // Notes: Unitree is different from MIT
    // unitree: FR = 0, FL, RR, RL
    // MIT: FL = 0, FR, RL, RR
    // from any leg-joint order to MIT leg-joint order

    // FR
    for (int joint = 0; joint < 3; ++joint) {
        leg_joints_[1].joints_[joint].pos = motor_data.q[joint];
        leg_joints_[1].joints_[joint].vel = motor_data.dq[joint];
    }

    // FL
    for (int joint = 0; joint < 3; ++joint) {
        leg_joints_[0].joints_[joint].pos = motor_data.q[3 + joint];
        leg_joints_[0].joints_[joint].vel = motor_data.dq[3 + joint];
    }

    // RR
    for (int joint = 0; joint < 3; ++joint) {
        leg_joints_[3].joints_[joint].pos = motor_data.q[6 + joint];
        leg_joints_[3].joints_[joint].vel = motor_data.dq[6 + joint];
    }

    // RL
    for (int joint = 0; joint < 3; ++joint) {
        leg_joints_[2].joints_[joint].pos = motor_data.q[9 + joint];
        leg_joints_[2].joints_[joint].vel = motor_data.dq[9 + joint];
    }

    motor_flag_ = true;
}

/**
 * get imu data
 * @param msg
 */
void KF_ESTIMATOR::ImuCallBack(const sensor_msgs::Imu_<std::allocator<void>>::ConstPtr &msg) {
    sensor_msgs::Imu imu_ = *msg;

    Eigen::Quaterniond q(imu_.orientation.w, imu_.orientation.x, imu_.orientation.y, imu_.orientation.z);
    robot_state_.quat_ = q;

    if (initial_yaw_ == 0)
        initial_yaw_ = quatToRPY(robot_state_.quat_)(2);

    Eigen::Quaternion<double> yaw = RpyToQuat(Vec3<double>(0., 0., -initial_yaw_));

    robot_state_.quat_ *= yaw;
    robot_state_.angular_vel_ << imu_.angular_velocity.x, imu_.angular_velocity.y, imu_.angular_velocity.z;
    robot_state_.accel_ << imu_.linear_acceleration.x, imu_.linear_acceleration.y, imu_.linear_acceleration.z;

    imu_flag_ = true;
}



