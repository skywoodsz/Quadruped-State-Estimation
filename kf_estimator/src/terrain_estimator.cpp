//
// Created by skywoodsz on 22-10-27.
//

#include <kf_estimator/terrain_estimator.h>

TerrainEstimator::TerrainEstimator(ros::NodeHandle &nh) :
nh_(nh)
{
    norm_pub_ =
            std::make_shared<realtime_tools::RealtimePublisher<geometry_msgs::Vector3>>(nh_, "/dog/terrain_norm", 100);

    marker_pub_ = nh_.advertise<visualization_msgs::MarkerArray>("/dog/terrain_norm_vis", 1);

    marker_real_time_pub_ = nh_.advertise<visualization_msgs::Marker>("/dog/terrain_norm_vis_debug", 1);

    Reset();
}

void TerrainEstimator::Reset() {
    for (int leg = 0; leg < 4; ++leg) {
        p_foot_[leg].setZero();
    }
    z_f_.setZero();
    A_pla_.setZero();

    last_postion_.setZero();
    last_publish_ = ros::Time::now();

    // for vis
    id_ = 0;
    marker_array_.markers.clear();

}

void TerrainEstimator::update(const RobotState &state) {
    ros::Time time = ros::Time::now();
    if (time - last_publish_ > ros::Duration(0.02))  // 50Hz
    {
            for (int leg = 0; leg < 4; ++leg) {
                if(state.contact_state_[leg])
                {
                    p_foot_[leg] = state.foot_pos_[leg];
                }
                z_f_[leg] = p_foot_[leg][2];
            }

            Eigen::Matrix<double, 4, 3> Wpla;
            Eigen::Vector4d w1 = Eigen::Vector4d::Ones();
            Eigen::Vector4d w2 = Eigen::Vector4d(p_foot_[0][0],  p_foot_[1][0],  p_foot_[2][0],  p_foot_[3][0]);
            Eigen::Vector4d w3 = Eigen::Vector4d(p_foot_[1][1],  p_foot_[1][1],  p_foot_[2][1],  p_foot_[3][1]);

            Wpla.block<4, 1>(0, 0) = w1;
            Wpla.block<4, 1>(0, 1) = w2;
            Wpla.block<4, 1>(0, 2) = w3;

            Eigen::Vector3d A_pla_temp;
            A_pla_temp =Wpla.colPivHouseholderQr().solve(z_f_);

            double alpha = 0.2;
            A_pla_ = alpha * A_pla_temp + (1 - alpha) * A_pla_;

            terrain_norm_ = Eigen::Vector3d(-A_pla_[1], -A_pla_[2], 1);
            terrain_norm_.normalize();

            publish();
            visPublish(state);
            if((last_postion_ - state.pos_).norm() > 0.1)
            {
                visArrayPublish(state, id_);
                id_++;
                last_postion_ = state.pos_;
            }
        last_publish_ = time;
    }
    //    std::cout<<"terrain_norm_: "<<"\n"<<terrain_norm_<<std::endl;
    //    std::cout<<"Wpla: "<<"\n"<<Wpla.colPivHouseholderQr().solve(z_f_)<<std::endl;
}

void TerrainEstimator::publish() {
    if(norm_pub_->trylock())
    {
        norm_pub_->msg_.x = terrain_norm_[0];
        norm_pub_->msg_.y = terrain_norm_[1];
        norm_pub_->msg_.z = terrain_norm_[2];
        norm_pub_->unlockAndPublish();
    }
}

void TerrainEstimator::visPublish(const RobotState& state) {

    visualization_msgs::Marker marker;
    marker.header.frame_id = "odom";
    marker.header.stamp = ros::Time::now();
    marker.ns = "terrain";
    marker.id = 0;
    marker.type = visualization_msgs::Marker::ARROW;
    marker.action = visualization_msgs::Marker::ADD;
    marker.points.resize(2);
    marker.points[0].x = state.pos_.x();
    marker.points[0].y = state.pos_.y();
    marker.points[0].z = 0.;
    marker.points[1].x = state.pos_.x() + terrain_norm_(0);
    marker.points[1].y = state.pos_.y() + terrain_norm_(1);
    marker.points[1].z = terrain_norm_(2);
    marker.scale.x = 0.01;
    marker.scale.y = 0.01;
    marker.scale.z = 0.01;
    marker.color.a = 1.0; // Don't forget to set the alpha!
    marker.color.r = 0.0;
    marker.color.g = 1.0;
    marker.color.b = 0.0;

    marker_real_time_pub_.publish(marker);
}

void TerrainEstimator::visArrayPublish(const RobotState &state, int id) {
    visualization_msgs::Marker marker;
    marker.header.frame_id = "odom";
    marker.header.stamp = ros::Time::now();
    marker.ns = "terrain";
    marker.id = id;
    marker.type = visualization_msgs::Marker::ARROW;
    marker.action = visualization_msgs::Marker::ADD;
    marker.points.resize(2);
    marker.points[0].x = state.pos_.x();
    marker.points[0].y = state.pos_.y();
    marker.points[0].z = 0.;
    marker.points[1].x = state.pos_.x() + terrain_norm_(0) / 10.;
    marker.points[1].y = state.pos_.y() + terrain_norm_(1) / 10.;
    marker.points[1].z = terrain_norm_(2) / 10.;
    marker.scale.x = 0.01;
    marker.scale.y = 0.01;
    marker.scale.z = 0.01;
    marker.color.a = 1.0; // Don't forget to set the alpha!
    marker.color.r = 1.0;
    marker.color.g = 0.0;
    marker.color.b = 0.0;

    marker_array_.markers.push_back(marker);
    marker_pub_.publish(marker_array_);
}











