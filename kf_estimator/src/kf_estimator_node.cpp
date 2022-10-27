//
// Created by skywoodsz on 22-10-26.
//

#include <kf_estimator/kf_estimator.h>
#include <ros/ros.h>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "kf_estimator");
    ros::NodeHandle nh;
    ros::NodeHandle nh_private("~");

    KF_ESTIMATOR kf_estimator(nh, nh_private);

    ros::spin();
    return 0;
}