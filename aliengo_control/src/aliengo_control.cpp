//
// Created by skywoodsz on 2022/9/12.
//

#include <aliengo_control/aliengo_control.h>

AliengoControl::AliengoControl(const ros::NodeHandle &node_handle, const ros::NodeHandle &private_node_handle) :
nh_(node_handle),
pnh_(private_node_handle)
{
    InitEnvironment();
    // init udp
    udp_ = std::make_shared<UNITREE_LEGGED_SDK::UDP>(LOCAL_PORT, TARGET_IP,TARGET_PORT,
                                                     sizeof(UNITREE_LEGGED_SDK::HighCmd),
                                                     sizeof(UNITREE_LEGGED_SDK::HighState));
    udp_->InitCmdData(high_cmd_);

    ROS_INFO("\033[1;32m----> UDP Init!\033[0m");

    HighLevelCmdInit();

    odom_pub_ =
            std::make_shared<realtime_tools::RealtimePublisher<nav_msgs::Odometry>>(nh_, "odom", 100);

    joy_sub_ = nh_.subscribe<cheetah_msgs::JoyCmd>("/joy_cmd", 1, &AliengoControl::joyCmdCallback, this);

    reader_timer_ = pnh_.createTimer(ros::Duration(1.0 / 500.0), &AliengoControl::read, this);
    writer_timer_ = pnh_.createTimer(ros::Duration(1.0 / 500.0), &AliengoControl::write, this);
}
/**
 * read high state of aliengo and publish the odom
 * @param event
 */
void AliengoControl::read(const ros::TimerEvent &event) {

    udp_->Recv();
    udp_->GetRecv(high_state_);

    odom_data_.pos[0] = high_state_.position[0];
    odom_data_.pos[1] = high_state_.position[1];
    odom_data_.pos[2] = high_state_.position[2];

    odom_data_.linear_vel[0] = high_state_.velocity[0];
    odom_data_.linear_vel[1] = high_state_.velocity[1];
    odom_data_.linear_vel[2] = high_state_.velocity[2];

//    odom_data_.ori.w() = high_state_.imu.quaternion[0];
//    odom_data_.ori.x() = high_state_.imu.quaternion[1];
//    odom_data_.ori.y() = high_state_.imu.quaternion[2];
//    odom_data_.ori.z() = high_state_.imu.quaternion[3];

    odom_data_.ori.w() = high_state_.imu.quaternion[3];
    odom_data_.ori.x() = high_state_.imu.quaternion[0];
    odom_data_.ori.y() = high_state_.imu.quaternion[1];
    odom_data_.ori.z() = high_state_.imu.quaternion[2];

    odom_data_.angular_vel[0] = high_state_.imu.gyroscope[0];
    odom_data_.angular_vel[1] = high_state_.imu.gyroscope[1];
    odom_data_.angular_vel[2] = high_state_.yawSpeed;

    publishState();
}

void AliengoControl::write(const ros::TimerEvent &event) {

    _SetupCommand();

    udp_->SetSend(high_cmd_);
    udp_->Send();

}

/**
 * set cmd vel and gait
 * Notes: this is in the world frame
 */
void AliengoControl::_SetupCommand(){
    cheetah_msgs::JoyCmd cmd_msgs = *joy_cmd_buffer_.readFromRT();

    // gait
    std::string next_gait_name;
    int gaitType;
    switch (cmd_msgs.cmd_model) {
        case 0:
            next_gait_name = "force_hold";
            high_cmd_.mode = 1;
            gaitType = 1;
            break;
        case 1:
            next_gait_name = "force_tort";
            high_cmd_.mode = 2;
            gaitType = 2;
            break;
        default:
            next_gait_name = "force_hold";
            high_cmd_.mode = 1;
            gaitType = 1;
    }

    if (current_gait_name!= next_gait_name)
    {
        std::cout << "[GAIT] Transitioning gait from " << current_gait_name
                  << " to "<< next_gait_name<< std::endl;
        current_gait_name = next_gait_name;
    }

    // convert joy
    double x_vel_cmd, y_vel_cmd;
    double yaw_rate_cmd;

    Eigen::Quaterniond q_w2b = Eigen::Quaterniond(high_state_.imu.quaternion[3],
                                                  high_state_.imu.quaternion[0],
                                                  high_state_.imu.quaternion[1],
                                                  high_state_.imu.quaternion[2]);
    Eigen::Matrix3d R_w2b = q_w2b.toRotationMatrix();

    Eigen::Vector3d body_vel(cmd_msgs.velDes[3], cmd_msgs.velDes[4], cmd_msgs.velDes[5]);
    Eigen::Vector3d world_vel = R_w2b.transpose() * body_vel;

    x_vel_cmd = world_vel[0];
    y_vel_cmd = world_vel[1];

    yaw_rate_cmd = cmd_msgs.velDes[2];

    if(gaitType == 2)
    {
        high_cmd_.velocity[0] = x_vel_cmd;
        high_cmd_.velocity[1] = y_vel_cmd;

        high_cmd_.yawSpeed = yaw_rate_cmd;
    }
    else
    {
        high_cmd_.velocity[0] = 0.;
        high_cmd_.velocity[1] = 0.;

        high_cmd_.rpy[0] = 0.;
        high_cmd_.rpy[1] = 0.;

        high_cmd_.yawSpeed = 0.;
        // ROS_INFO("!!!");
    }

//    std::cout<<"body_vel x: "<<body_vel(0)<<std::endl;
//    std::cout<<"body_vel y: "<<high_cmd_.velocity[1]<<std::endl;
//    std::cout<<"yaw_rate y: "<<high_cmd_.yawSpeed<<std::endl;

}


/**
 * cmd init
 */
void AliengoControl::HighLevelCmdInit() {
    high_cmd_.mode = 0;
    high_cmd_.rpy[0] = 0.;
    high_cmd_.rpy[1] = 0.;
    high_cmd_.rpy[2] = 0.;
    high_cmd_.gaitType = 0;
    high_cmd_.dBodyHeight = 0.;
    high_cmd_.dFootRaiseHeight = 0.;

    for (int i = 0; i < 1000; ++i) {
        udp_->SetSend(high_cmd_);
        udp_->Send();
        usleep(2000);
    }

    current_gait_name = "Idle";

    ROS_INFO("\033[1;32m----> Cmd Init!\033[0m");
}

/**
 * publish the odom and build thw tf tree
 */
void AliengoControl::publishState() {
    if(last_publish_ + ros::Duration(1.0 / 100.0) < ros::Time::now())
    {
        if (odom_pub_->trylock()) {
            odom_pub_->msg_.header.stamp = ros::Time::now();
            odom_pub_->msg_.pose.pose.orientation.x = odom_data_.ori.x();
            odom_pub_->msg_.pose.pose.orientation.y = odom_data_.ori.y();
            odom_pub_->msg_.pose.pose.orientation.z = odom_data_.ori.z();
            odom_pub_->msg_.pose.pose.orientation.w = odom_data_.ori.w();

            odom_pub_->msg_.pose.pose.position.x = odom_data_.pos[0];
            odom_pub_->msg_.pose.pose.position.y = odom_data_.pos[1];
            odom_pub_->msg_.pose.pose.position.z = odom_data_.pos[2];

            odom_pub_->msg_.twist.twist.angular.x = odom_data_.linear_vel[0];
            odom_pub_->msg_.twist.twist.angular.y = odom_data_.linear_vel[1];
            odom_pub_->msg_.twist.twist.angular.z = odom_data_.linear_vel[2];

            odom_pub_->msg_.twist.twist.linear.x = odom_data_.angular_vel[0];
            odom_pub_->msg_.twist.twist.linear.y = odom_data_.angular_vel[1];
            odom_pub_->msg_.twist.twist.linear.z = odom_data_.angular_vel[2];

            odom_pub_->unlockAndPublish();
        }

        geometry_msgs::TransformStamped transform_stamped;
        transform_stamped.header.stamp = ros::Time::now();
        transform_stamped.header.frame_id = "odom";
        transform_stamped.child_frame_id = "base_link";
        transform_stamped.transform.translation.x = odom_data_.pos[0];
        transform_stamped.transform.translation.y = odom_data_.pos[1];
        transform_stamped.transform.translation.z = odom_data_.pos[2];
        transform_stamped.transform.rotation.x = odom_data_.ori.x();
        transform_stamped.transform.rotation.y = odom_data_.ori.y();
        transform_stamped.transform.rotation.z = odom_data_.ori.z();
        transform_stamped.transform.rotation.w = odom_data_.ori.w();
        tf_br_.sendTransform(transform_stamped);

        last_publish_ = ros::Time::now();
    }

}

/**
 * get the joy cmd
 * @param msg
 */
void AliengoControl::joyCmdCallback(const cheetah_msgs::JoyCmd::ConstPtr &msg) {
    joy_cmd_buffer_.writeFromNonRT(*msg);
}
