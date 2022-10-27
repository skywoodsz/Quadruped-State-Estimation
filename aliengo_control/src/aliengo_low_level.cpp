//
// Created by skywoodsz on 2022/9/12.
//

#include <aliengo_control/aliengo_low_level.h>

AliengoControl::AliengoControl(const ros::NodeHandle &node_handle, const ros::NodeHandle &private_node_handle) :
nh_(node_handle),
pnh_(private_node_handle)
{
    InitEnvironment();
    // init udp
    udp_ = std::make_shared<UNITREE_LEGGED_SDK::UDP>(UNITREE_LEGGED_SDK::LOWLEVEL);
    udp_->InitCmdData(low_cmd_);

    ROS_INFO("\033[1;32m----> UDP Init!\033[0m");

    udp_->SetSend(low_cmd_);
    udp_->Send();

    contact_threshold_ = 10;

    imu_pub_ = 
        std::make_shared<realtime_tools::RealtimePublisher<sensor_msgs::Imu>>(nh_, "/dog/imu_data", 100);

    motor_pub_ = 
        std::make_shared<realtime_tools::RealtimePublisher<cheetah_msgs::MotorState>>(nh_, "/dog/motor_data", 100);

    leg_contact_pub_ =
        std::make_shared<realtime_tools::RealtimePublisher<cheetah_msgs::LegContact>>(nh_, "/dog/leg_contact", 100);

    reader_timer_ = pnh_.createTimer(ros::Duration(1.0 / 500.0), &AliengoControl::read, this);

}

/**
 * read high state of aliengo and publish the odom
 * @param event
 */
void AliengoControl::read(const ros::TimerEvent &event) {

    udp_->Recv();
    udp_->GetRecv(low_state_);

    // lcm_->Recv();
    // lcm_->Get(low_state_);

    for (int i = 0; i < 12; ++i)
    {
        joint_data_[i].pos_ = low_state_.motorState[i].q;
        joint_data_[i].vel_ = low_state_.motorState[i].dq;
        joint_data_[i].tau_ = low_state_.motorState[i].tauEst;
    }

    imu_data_.ori[0] = low_state_.imu.quaternion[1];
    imu_data_.ori[1] = low_state_.imu.quaternion[2];
    imu_data_.ori[2] = low_state_.imu.quaternion[3];
    imu_data_.ori[3] = low_state_.imu.quaternion[0];
    imu_data_.angular_vel[0] = low_state_.imu.gyroscope[0];
    imu_data_.angular_vel[1] = low_state_.imu.gyroscope[1];
    imu_data_.angular_vel[2] = low_state_.imu.gyroscope[2];
    imu_data_.linear_acc[0] = low_state_.imu.accelerometer[0];
    imu_data_.linear_acc[1] = low_state_.imu.accelerometer[1];
    imu_data_.linear_acc[2] = low_state_.imu.accelerometer[2];


    contact_state_[0] = low_state_.footForce[UNITREE_LEGGED_SDK::FL_] > contact_threshold_;
    contact_state_[1] = low_state_.footForce[UNITREE_LEGGED_SDK::FR_] > contact_threshold_;
    contact_state_[2] = low_state_.footForce[UNITREE_LEGGED_SDK::RL_] > contact_threshold_;
    contact_state_[3] = low_state_.footForce[UNITREE_LEGGED_SDK::RR_] > contact_threshold_;

    // std::cout<<"low_state_.imu.quaternion[0]"<<low_state_.imu.quaternion[0]<<std::endl;


    publishState();

    // udp_->SetSend(low_cmd_);
    // udp_->Send();
}

/**
 * @brief 发布 IMU & joint
 * 
 */
void AliengoControl::publishState()
{
    if (imu_pub_->trylock()) {
        imu_pub_->msg_.header.stamp = ros::Time::now();
        imu_pub_->msg_.header.frame_id = "imu_link";

        imu_pub_->msg_.orientation.x = imu_data_.ori[0];
        imu_pub_->msg_.orientation.y = imu_data_.ori[1];
        imu_pub_->msg_.orientation.z = imu_data_.ori[2];
        imu_pub_->msg_.orientation.w = imu_data_.ori[3];

        imu_pub_->msg_.linear_acceleration.x = imu_data_.linear_acc[0];
        imu_pub_->msg_.linear_acceleration.y = imu_data_.linear_acc[1];
        imu_pub_->msg_.linear_acceleration.z = imu_data_.linear_acc[2];

        imu_pub_->msg_.angular_velocity.x = imu_data_.angular_vel[0];
        imu_pub_->msg_.angular_velocity.y = imu_data_.angular_vel[1];
        imu_pub_->msg_.angular_velocity.z = imu_data_.angular_vel[2];

        imu_pub_->unlockAndPublish();
    }

    if(motor_pub_->trylock())
    {
        cheetah_msgs::MotorState motor_state;
        motor_state.header.stamp = ros::Time::now();
        for (int i = 0; i < 20; ++i)
        {
            motor_state.q[i] = low_state_.motorState[i].q;
            motor_state.dq[i] = low_state_.motorState[i].dq;
            motor_state.tau[i] = low_state_.motorState[i].tauEst;
            motor_state.temperature[i] = low_state_.motorState[i].temperature;
        }
        motor_pub_->msg_ = motor_state;
        motor_pub_->unlockAndPublish();
    }

    if(leg_contact_pub_->trylock())
    {
        for (int i = 0; i < 4; ++i) {
            leg_contact_pub_->msg_.contact_state[i] = contact_state_[i];
        }
        leg_contact_pub_->unlockAndPublish();
    }

    last_publish_ = ros::Time::now();

}

