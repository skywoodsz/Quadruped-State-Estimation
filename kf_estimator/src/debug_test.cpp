//
// Created by skywoodsz on 22-10-26.
//

#include <iostream>
#include <ros/ros.h>
#include <kf_estimator/robot_math.h>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "debug_test");
    ros::NodeHandle nh;

    Eigen::Quaterniond q(0.6427876, 0, 0, 0.7660444);
    Eigen::Matrix3d R = quaternionToRotationMatrix(q);
    std::cout<<"Rq: "<<"\n"<<R<<std::endl;

    Eigen::Matrix3d rotation_matrix;
    rotation_matrix = q.toRotationMatrix();
    std::cout<<"Reigen: "<<"\n"<<rotation_matrix<<std::endl;

    return 0;
}
