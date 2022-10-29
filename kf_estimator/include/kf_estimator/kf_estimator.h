//
// Created by skywoodsz on 22-10-25.
//

#ifndef SRC_KF_ESTIMATOR_H
#define SRC_KF_ESTIMATOR_H

#include <pinocchio/fwd.hpp>
#include <pinocchio/parsers/urdf.hpp>
#include <urdf_parser/urdf_parser.h>
#include <pinocchio/algorithm/kinematics.hpp>
#include <pinocchio/algorithm/frames.hpp>
#include <pinocchio/algorithm/jacobian.hpp>

#include <Eigen/Core>
#include <Eigen/Dense>

#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <realtime_tools/realtime_publisher.h>
#include <realtime_tools/realtime_buffer.h>

#include <cheetah_msgs/MotorState.h>
#include <cheetah_msgs/LegContact.h>
#include <cheetah_msgs/LegsState.h>

#include <kf_estimator/dog_type.h>
#include <kf_estimator/state_estimate.h>
#include <kf_estimator/terrain_estimator.h>

class KF_ESTIMATOR{
public:
    KF_ESTIMATOR(const ros::NodeHandle &node_handle, const ros::NodeHandle &private_node_handle);
    void Reset();

    RobotState robot_state_;
private:
    void ImuCallBack(const sensor_msgs::Imu::ConstPtr& msg);
    void MotorCallBack(const cheetah_msgs::MotorState::ConstPtr& msg);
    void LegContactCallBack(const cheetah_msgs::LegContact::ConstPtr& msg);
    void BodyPinocchioKine();
    void PinocchioKine();
    void update(const ros::TimerEvent& event);
    void publishState();

    ros::NodeHandle nh_;
    ros::NodeHandle pnh_;

    ros::Time last_publish_;
    ros::Timer timer_;

    ros::Subscriber imu_sub_;
    ros::Subscriber motor_sub_;
    ros::Subscriber contact_sub_;

    bool imu_flag_, motor_flag_, contact_flag_;

    realtime_tools::RealtimeBuffer<sensor_msgs::Imu> imu_buffer_;

    double initial_yaw_;

    std::shared_ptr<urdf::ModelInterface> urdf_;
    std::shared_ptr<pinocchio::Model> pin_bmodel_, pin_model_;
    std::shared_ptr<pinocchio::Data> pin_bdata_, pin_data_;

    LegJoints leg_joints_[4];

    std::shared_ptr<StateEstimateBase> linear_estimate_;
    std::shared_ptr<TerrainEstimator> terrain_estimator_;

    std::shared_ptr<realtime_tools::RealtimePublisher<cheetah_msgs::LegsState>> state_pub_;
};

#endif //SRC_KF_ESTIMATOR_H