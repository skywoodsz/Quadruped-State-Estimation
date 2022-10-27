//
// Created by skywoodsz on 2022/10/25.
//

#include "aliengo_control/aliengo_low_level.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "aliengo_low_level_node");
    ros::NodeHandle nh;
    ros::NodeHandle nh_private("~");

    AliengoControl aliengo_control(nh, nh_private);

    ros::spin();
    return 0;
}