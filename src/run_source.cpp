//
// Created by nvidia on 10/17/19.
//

#include <ros/ros.h>
#include <iostream>
#include <lan_test/lan_test.h>

int main(int argc, char **argv){
    std::cout<<"im born\n";
    ros::init(argc, argv, "Source_node_on_LAN");

    Lan_Test::Source s;

    ros::spin();

    return 0;
}
