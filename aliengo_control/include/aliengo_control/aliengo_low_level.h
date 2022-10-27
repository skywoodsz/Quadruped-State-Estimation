//
// Created by skywoodsz on 2022/10/25.
//

#ifndef SRC_ALIENGO_LOW_LEVEL_H
#define SRC_ALIENGO_LOW_LEVEL_H

#include <math.h>
#include <iostream>
#include <unistd.h>
#include <string.h>

#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <sensor_msgs/Imu.h>

#include <realtime_tools/realtime_publisher.h>
#include <realtime_tools/realtime_buffer.h>
#include <tf2_ros/transform_broadcaster.h>

#include <cheetah_msgs/MotorState.h>
#include <cheetah_msgs/LegContact.h>

#include <unitree_legged_sdk/unitree_legged_sdk.h>

#include <Eigen/Core>
#include <Eigen/Dense>

using namespace UNITREE_LEGGED_SDK;

// high cmd
// constexpr uint16_t TARGET_PORT = 8082;
// constexpr uint16_t LOCAL_PORT = 8081;
// constexpr char TARGET_IP[] = "192.168.123.220";   // target IP address


//// low cmd
constexpr uint16_t TARGET_PORT = 8007;
constexpr uint16_t LOCAL_PORT = 8082;
constexpr char TARGET_IP[] = "192.168.123.10";   // target IP address

struct UnitreeMotorData
{
  double pos_, vel_, tau_;                   // state
  double pos_des_, vel_des_, kp_, kd_, ff_;  // command
};

struct UnitreeImuData
{
  double ori[4];
  double ori_cov[9];
  double angular_vel[3];
  double angular_vel_cov[9];
  double linear_acc[3];
  double linear_acc_cov[9];
};

class AliengoControl{
public:
    AliengoControl(const ros::NodeHandle &node_handle, const ros::NodeHandle &private_node_handle);
    void read(const ros::TimerEvent& event);
    void write(const ros::TimerEvent& event);

    void LowLevelCmdInit();
private:
    void publishState();
    // void joyCmdCallback(const cheetah_msgs::JoyCmd::ConstPtr &msg);
    // void _SetupCommand();

    ros::NodeHandle nh_;
    ros::NodeHandle pnh_;

    ros::Timer reader_timer_;
    ros::Timer writer_timer_;

    ros::Subscriber joy_sub_;

    ros::Time last_publish_;
    tf2_ros::TransformBroadcaster tf_br_;

    std::shared_ptr<UNITREE_LEGGED_SDK::UDP> udp_;
    UNITREE_LEGGED_SDK::LowState low_state_{};
    UNITREE_LEGGED_SDK::LowCmd low_cmd_{};

    UnitreeMotorData joint_data_[12]{};
    UnitreeImuData imu_data_{};
    bool contact_state_[4]{};
    int contact_threshold_{};

    cheetah_msgs::LegContact leg_contact_;

    std::shared_ptr<realtime_tools::RealtimePublisher<sensor_msgs::Imu>> imu_pub_;
    std::shared_ptr<realtime_tools::RealtimePublisher<cheetah_msgs::MotorState>> motor_pub_;
    std::shared_ptr<realtime_tools::RealtimePublisher<cheetah_msgs::LegContact>> leg_contact_pub_;


    std::shared_ptr<UNITREE_LEGGED_SDK::LCM> lcm_;
};



#endif //SRC_ALIENGO_LOW_LEVEL_H