//
// Created by skywoodsz on 22-10-25.
//

#ifndef SRC_STATE_ESTIMATE_H
#define SRC_STATE_ESTIMATE_H

#include <kf_estimator/dog_type.h>
#include <kf_estimator/robot_math.h>

#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <nav_msgs/Path.h>
#include <realtime_tools/realtime_publisher.h>
#include <realtime_tools/realtime_buffer.h>
#include <tf2_ros/transform_broadcaster.h>


class StateEstimateBase
{
public:
    StateEstimateBase(ros::NodeHandle& nh);
    virtual ~StateEstimateBase(){};
    virtual void update(RobotState& state);

private:
    std::shared_ptr<realtime_tools::RealtimePublisher<nav_msgs::Odometry>> odom_pub_;
    std::shared_ptr<realtime_tools::RealtimePublisher<nav_msgs::Path>> path_pub_;

    ros::Time last_publish_;
    Eigen::Vector3d last_position_;
    tf2_ros::TransformBroadcaster tf_br_;
};

class LinearKFPosVelEstimator : public StateEstimateBase
{
public:
    LinearKFPosVelEstimator(ros::NodeHandle& nh);
    void update(RobotState& state);

private:
    Eigen::Matrix<double, 18, 1> x_hat_;
    Eigen::Matrix<double, 12, 1> ps_;
    Eigen::Matrix<double, 12, 1> vs_;
    Eigen::Matrix<double, 18, 18> a_;
    Eigen::Matrix<double, 18, 18> q_;
    Eigen::Matrix<double, 18, 18> p_;
    Eigen::Matrix<double, 28, 28> r_;
    Eigen::Matrix<double, 18, 3> b_;
    Eigen::Matrix<double, 28, 18> c_;
};





#endif //SRC_STATE_ESTIMATE_H
