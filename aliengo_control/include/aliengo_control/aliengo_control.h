//
// Created by skywoodsz on 2022/9/12.
//

#ifndef SRC_ALIENGO_CONTROL_H
#define SRC_ALIENGO_CONTROL_H

#include <math.h>
#include <iostream>
#include <unistd.h>
#include <string.h>

#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <realtime_tools/realtime_publisher.h>
#include <realtime_tools/realtime_buffer.h>
#include <tf2_ros/transform_broadcaster.h>

#include "cheetah_msgs/JoyCmd.h"

#include <unitree_legged_sdk/unitree_legged_sdk.h>

#include <Eigen/Core>
#include <Eigen/Dense>

using namespace UNITREE_LEGGED_SDK;

// high cmd
constexpr uint16_t TARGET_PORT = 8082;
constexpr uint16_t LOCAL_PORT = 8081;
constexpr char TARGET_IP[] = "192.168.123.220";   // target IP address


//// low cmd
//constexpr uint16_t TARGET_PORT = 8007;
//constexpr uint16_t LOCAL_PORT = 8082;
//constexpr char TARGET_IP[] = "192.168.123.10";   // target IP address

struct UnitreeOdomData
{
    Eigen::Vector3d pos;
    Eigen::Quaterniond ori;
    Eigen::Vector3d linear_vel;
    Eigen::Vector3d angular_vel;
};

class AliengoControl{
public:
    AliengoControl(const ros::NodeHandle &node_handle, const ros::NodeHandle &private_node_handle);
    void read(const ros::TimerEvent& event);
    void write(const ros::TimerEvent& event);

    void HighLevelCmdInit();
private:
    void publishState();
    void joyCmdCallback(const cheetah_msgs::JoyCmd::ConstPtr &msg);
    void _SetupCommand();

    ros::NodeHandle nh_;
    ros::NodeHandle pnh_;

    ros::Timer reader_timer_;
    ros::Timer writer_timer_;

    ros::Subscriber joy_sub_;

    ros::Time last_publish_;
    tf2_ros::TransformBroadcaster tf_br_;

    std::shared_ptr<UNITREE_LEGGED_SDK::UDP> udp_;
    UNITREE_LEGGED_SDK::HighState high_state_{};
    UNITREE_LEGGED_SDK::HighCmd high_cmd_{};

    UnitreeOdomData odom_data_{};

    std::shared_ptr<realtime_tools::RealtimePublisher<nav_msgs::Odometry>> odom_pub_;
    realtime_tools::RealtimeBuffer<cheetah_msgs::JoyCmd> joy_cmd_buffer_;

    std::string current_gait_name;
};
#endif //SRC_ALIENGO_CONTROL_H
