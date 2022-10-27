//
// Created by skywoodsz on 22-10-27.
//

#ifndef SRC_TERRAIN_ESTIMATOR_H
#define SRC_TERRAIN_ESTIMATOR_H

#include <ros/ros.h>
#include <geometry_msgs/Vector3.h>
#include <nav_msgs/Odometry.h>
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>

#include <realtime_tools/realtime_publisher.h>

#include <kf_estimator/dog_type.h>

class TerrainEstimator
{
public:
    TerrainEstimator(ros::NodeHandle& nh);
    void update(const RobotState& state);
    void Reset();

private:
    void publish();
    void visPublish(const RobotState& state);
    void visArrayPublish(const RobotState& state, int id);

    ros::NodeHandle nh_;
    std::shared_ptr<realtime_tools::RealtimePublisher<geometry_msgs::Vector3>> norm_pub_;
    ros::Publisher marker_pub_;
    ros::Publisher marker_real_time_pub_;

    Eigen::Vector3d p_foot_[4];
    Eigen::Vector3d A_pla_;
    Eigen::Vector4d z_f_;
    Eigen::Vector3d terrain_norm_;

    int id_;
    visualization_msgs::MarkerArray marker_array_;

    ros::Time last_publish_;
    Eigen::Vector3d last_postion_;
};


#endif //SRC_TERRAIN_ESTIMATOR_H
