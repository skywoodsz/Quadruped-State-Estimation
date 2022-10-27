//
// Created by skywoodsz on 2022/9/12.
//

#include "aliengo_control/aliengo_control.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "aliengo_control_node");
    ros::NodeHandle nh;
    ros::NodeHandle nh_private("~");

    AliengoControl aliengo_control(nh, nh_private);

    ros::spin();
    return 0;
}