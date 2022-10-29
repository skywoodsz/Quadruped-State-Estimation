//
// Created by skywoodsz on 22-10-25.
//

#include "kf_estimator/state_estimate.h"

StateEstimateBase::StateEstimateBase(ros::NodeHandle& nh)
{
    odom_pub_ = std::make_shared<realtime_tools::RealtimePublisher<nav_msgs::Odometry>>(nh, "/odom", 100);
    path_pub_ = std::make_shared<realtime_tools::RealtimePublisher<nav_msgs::Path>>(nh, "/dog/legged_path", 100);
}

void StateEstimateBase::update(RobotState& state)
{
    ros::Time time = ros::Time::now();
    if (time < ros::Time(0.01))  // When simulate time reset
        last_publish_ = time;
    if (time - last_publish_ > ros::Duration(0.01))  // 100Hz
    {
        last_publish_ = time;
        if (odom_pub_->trylock())
        {
            odom_pub_->msg_.header.stamp = time;
            odom_pub_->msg_.pose.pose.orientation.x = state.quat_.x();
            odom_pub_->msg_.pose.pose.orientation.y = state.quat_.y();
            odom_pub_->msg_.pose.pose.orientation.z = state.quat_.z();
            odom_pub_->msg_.pose.pose.orientation.w = state.quat_.w();
            odom_pub_->msg_.pose.pose.position.x = state.pos_[0];
            odom_pub_->msg_.pose.pose.position.y = state.pos_[1];
            odom_pub_->msg_.pose.pose.position.z = state.pos_[2];
            odom_pub_->msg_.twist.twist.angular.x = state.angular_vel_[0];
            odom_pub_->msg_.twist.twist.angular.y = state.angular_vel_[1];
            odom_pub_->msg_.twist.twist.angular.z = state.angular_vel_[2];
            odom_pub_->msg_.twist.twist.linear.x = state.linear_vel_[0];
            odom_pub_->msg_.twist.twist.linear.y = state.linear_vel_[1];
            odom_pub_->msg_.twist.twist.linear.z = state.linear_vel_[2];
            odom_pub_->unlockAndPublish();
        }

        // tf
        geometry_msgs::TransformStamped transform_stamped;
        transform_stamped.header.stamp = time;
        transform_stamped.header.frame_id = "odom";
        transform_stamped.child_frame_id = "base_link";
        transform_stamped.transform.translation.x = state.pos_[0];
        transform_stamped.transform.translation.y = state.pos_[1];
        transform_stamped.transform.translation.z = state.pos_[2];
        transform_stamped.transform.rotation.x = state.quat_.x();
        transform_stamped.transform.rotation.y = state.quat_.y();
        transform_stamped.transform.rotation.z = state.quat_.z();
        transform_stamped.transform.rotation.w = state.quat_.w();
        tf_br_.sendTransform(transform_stamped);

        // path
        Eigen::Vector3d current_position = Eigen::Vector3d(state.pos_[0],
                                                           state.pos_[1],
                                                           state.pos_[2]);
        if((last_position_ - current_position).norm() > 0.1)
        {
            if (path_pub_->trylock()) {
                geometry_msgs::PoseStamped legged_pose;
                legged_pose.header.stamp = time;
                legged_pose.header.frame_id = "odom";
                legged_pose.pose.position.x = state.pos_[0];
                legged_pose.pose.position.y = state.pos_[1];
                legged_pose.pose.position.z = state.pos_[2];

                legged_pose.pose.orientation.x = state.quat_.x();
                legged_pose.pose.orientation.y = state.quat_.y();
                legged_pose.pose.orientation.z = state.quat_.z();
                legged_pose.pose.orientation.w = state.quat_.w();

                path_pub_->msg_.header.stamp = ros::Time::now();
                path_pub_->msg_.header.frame_id = "odom";
                path_pub_->msg_.poses.push_back(legged_pose);

                path_pub_->unlockAndPublish();
            }
        }
    }
}

LinearKFPosVelEstimator::LinearKFPosVelEstimator(ros::NodeHandle& nh) : StateEstimateBase(nh)
{
    double dt = 0.002; // shoud be feedback dt
    x_hat_.setZero(); // w_pcom, w_vcom, w_pfoot
    ps_.setZero();
    vs_.setZero();
    a_.setZero();
    a_.block(0, 0, 3, 3) = Eigen::Matrix<double, 3, 3>::Identity();
    a_.block(0, 3, 3, 3) = dt * Eigen::Matrix<double, 3, 3>::Identity();
    a_.block(3, 3, 3, 3) = Eigen::Matrix<double, 3, 3>::Identity();
    a_.block(6, 6, 12, 12) = Eigen::Matrix<double, 12, 12>::Identity();
    b_.setZero();
    b_.block(0, 0, 3, 3) = 0.5 * dt * dt * Eigen::Matrix<double, 3, 3>::Identity();
    b_.block(3, 0, 3, 3) = dt * Eigen::Matrix<double, 3, 3>::Identity();

    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> c1(3, 6);
    c1 << Eigen::Matrix<double, 3, 3>::Identity(), Eigen::Matrix<double, 3, 3>::Zero();
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> c2(3, 6);
    c2 << Eigen::Matrix<double, 3, 3>::Zero(), Eigen::Matrix<double, 3, 3>::Identity();
    c_.setZero();
    c_.block(0, 0, 3, 6) = c1;
    c_.block(3, 0, 3, 6) = c1;
    c_.block(6, 0, 3, 6) = c1;
    c_.block(9, 0, 3, 6) = c1;
    c_.block(0, 6, 12, 12) = - Eigen::Matrix<double, 12, 12>::Identity();
    c_.block(12, 0, 3, 6) = c2;
    c_.block(15, 0, 3, 6) = c2;
    c_.block(18, 0, 3, 6) = c2;
    c_.block(21, 0, 3, 6) = c2;
    c_(27, 17) = 1.0;
    c_(26, 14) = 1.0;
    c_(25, 11) = 1.0;
    c_(24, 8) = 1.0;
    p_.setIdentity();
    p_ = 100. * p_;
    q_.setIdentity();
    q_.block(0, 0, 3, 3) = (dt / 20.f) * Eigen::Matrix<double, 3, 3>::Identity();
    q_.block(3, 3, 3, 3) = (dt * 9.81f / 20.f) * Eigen::Matrix<double, 3, 3>::Identity();
    q_.block(6, 6, 12, 12) = dt * Eigen::Matrix<double, 12, 12>::Identity();
    r_.setIdentity();
}

void LinearKFPosVelEstimator::update(RobotState& state)
{
    // predict
    double imu_process_noise_position = 0.02;
    double imu_process_noise_velocity = 0.02;
    double foot_process_noise_position = 0.002;
    // observer
    double foot_sensor_noise_position = 0.005; // 0.001
    double foot_sensor_noise_velocity = 0.1;
    double foot_height_sensor_noise = 0.001;

    Mat3<double> Rbod = quaternionToRotationMatrix(state.quat_);

    Eigen::Matrix<double, 18, 18> q = Eigen::Matrix<double, 18, 18>::Identity();
    q.block(0, 0, 3, 3) = q_.block(0, 0, 3, 3) * imu_process_noise_position;
    q.block(3, 3, 3, 3) = q_.block(3, 3, 3, 3) * imu_process_noise_velocity;
    q.block(6, 6, 12, 12) = q_.block(6, 6, 12, 12) * foot_process_noise_position;

    Eigen::Matrix<double, 28, 28> r = Eigen::Matrix<double, 28, 28>::Identity();
    r.block(0, 0, 12, 12) = r_.block(0, 0, 12, 12) * foot_sensor_noise_position;
    r.block(12, 12, 12, 12) = r_.block(12, 12, 12, 12) * foot_sensor_noise_velocity;
    r.block(24, 24, 4, 4) = r_.block(24, 24, 4, 4) * foot_height_sensor_noise;

    Vec4<double> pzs = Vec4<double>::Zero();

    for (int i = 0; i < 4; i++)
    {
        int i1 = 3 * i;

        int q_index = 6 + i1;
        int r_index1 = i1;
        int r_index2 = 12 + i1;
        int r_index3 = 24 + i;

        double high_suspect_number(100);
        q.block(q_index, q_index, 3, 3) =
                (state.contact_state_[i] ? 1. : high_suspect_number) * q.block(q_index, q_index, 3, 3);
        r.block(r_index1, r_index1, 3, 3) = 1. * r.block(r_index1, r_index1, 3, 3);
        r.block(r_index2, r_index2, 3, 3) =
                (state.contact_state_[i] ? 1. : high_suspect_number) * r.block(r_index2, r_index2, 3, 3);
        r(r_index3, r_index3) = (state.contact_state_[i] ? 1. : high_suspect_number) * r(r_index3, r_index3);

//        Vec3<double> p_rel = state.bfoot_pos_[i]; // b_pfoot
//        Vec3<double> dp_rel = state.bfoot_vel_[i]; // b_vfoot
//        Vec3<double> p_f = Rbod * p_rel;
//        Vec3<double> omegaBody = state.angular_vel_;
//        Vec3<double> dp_f = Rbod * (omegaBody.cross(p_rel) + dp_rel);

        Vec3<double> p_rel = state.bfoot_pos_[i]; // b_pfoot
        Vec3<double> dp_rel = state.bfoot_vel_[i]; // b_vfoot
        Vec3<double> p_f = Rbod * p_rel;
        Vec3<double> omegaBody = state.angular_vel_;
        Vec3<double> dp_f = Rbod * (omegaBody.cross(p_rel) + dp_rel);

        ps_.segment(i1, 3) = -p_f;
        vs_.segment(i1, 3) = -dp_f;

        // wrong!
//        ps_.segment(3 * i, 3) = state.pos_ - state.foot_pos_[i];
//        vs_.segment(3 * i, 3) = state.linear_vel_ - state.foot_vel_[i];
    }

    Vec3<double> g(0, 0, -9.81);
    Vec3<double> accel = Rbod * state.accel_ + g;

    Eigen::Matrix<double, 28, 1> y;
    y << ps_, vs_, pzs;
    x_hat_ = a_ * x_hat_ + b_ * accel;
    Eigen::Matrix<double, 18, 18> at = a_.transpose();
    Eigen::Matrix<double, 18, 18> pm = a_ * p_ * at + q;
    Eigen::Matrix<double, 18, 28> ct = c_.transpose();
    Eigen::Matrix<double, 28, 1> y_model = c_ * x_hat_;
    Eigen::Matrix<double, 28, 1> ey = y - y_model;
    Eigen::Matrix<double, 28, 28> s = c_ * pm * ct + r;

    Eigen::Matrix<double, 28, 1> s_ey = s.lu().solve(ey);
    x_hat_ += pm * ct * s_ey;

    Eigen::Matrix<double, 28, 18> s_c = s.lu().solve(c_);
    p_ = (Eigen::Matrix<double, 18, 18>::Identity() - pm * ct * s_c) * pm;

    Eigen::Matrix<double, 18, 18> pt = p_.transpose();
    p_ = (p_ + pt) / 2.0;

    if (p_.block(0, 0, 2, 2).determinant() > 0.000001)
    {
        p_.block(0, 2, 2, 16).setZero();
        p_.block(2, 0, 16, 2).setZero();
        p_.block(0, 0, 2, 2) /= 10.;
    }

    state.pos_ = x_hat_.block(0, 0, 3, 1);
    state.linear_vel_ = x_hat_.block(3, 0, 3, 1);

    StateEstimateBase::update(state);
}


