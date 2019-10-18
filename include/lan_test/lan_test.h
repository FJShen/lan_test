//
// Created by nvidia on 10/17/19.
//

#ifndef SRC_LAN_TEST_H
#define SRC_LAN_TEST_H

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <string>

namespace Lan_Test {

    class Source {
    private:
        ros::NodeHandle n;
        ros::Publisher Pub;
        ros::Timer timer;
        void timerCallback(const ros::TimerEvent& event){
            static int count{0};
            std_msgs::String msg;
            msg.data = std::string("hello");
            msg.data += std::to_string(++count);
            std::cout<<"Published published: "<<msg.data<<"\n";
            Pub.publish(msg);
        }
    public:
        Source(){
            Pub = n.advertise<std_msgs::String>("message_over_lan", 1);
            timer = n.createTimer(ros::Duration(0.1), &Source::timerCallback, this);
        }
    };

    class Drain{
    private:
        ros::NodeHandle n;
        ros::Subscriber Sub;
        void messageCallback(const std_msgs::String& msg){
            std::cout<<"received: "<<msg.data<<"\n";
        }
    public:
        Drain(){
            Sub = n.subscribe("message_over_lan", 1, &Drain::messageCallback, this);
        }
    };

};

#endif //SRC_LAN_TEST_H
