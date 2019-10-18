//
// Created by nvidia on 10/17/19.
//


#include <ros/ros.h>
#include <iostream>
#include <lan_test/lan_test.h>

int main(int argc, char **argv){
    std::cout<<"im born\n";
    ros::init(argc, argv, "Drain_node_on_LAN");

    Lan_Test::Drain d;

    ros::spin();

    return 0;
}