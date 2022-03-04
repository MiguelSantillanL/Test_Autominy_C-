#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include "autominy_msgs/SpeedCommand.h"
#include "autominy_msgs/SteeringCommand.h"
 

int main(int argc, char **argv){
    ros::init(argc, argv, "test_autominy");
    ros::NodeHandle nh;

//ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);
    ros::Publisher pub = nh.advertise<autominy_msgs::SpeedCommand>("/actuators/speed", 1000);
    //ros::Publisher pub = nh.advertise<SteeringCommand::Twist>("/actuators/steering", 1000);

    srand(time(0));

    ros::Rate rate(1);
 
    autominy_msgs::SpeedCommand msg_Speed;
    //autominy_msgs::SteeringCommand msg_Steering;


    while (true)
    {
        ROS_INFO("STOP");
        msg_Speed.value = 0.0;
        //msg_Steering.value = 0.0;
        pub.publish(msg_Speed);
        rate.sleep();
        //pub.publish(msg_Steering);

        ROS_INFO("GO AHEAD");
        msg_Speed.value = 0.5;
        pub.publish(msg_Speed);
        rate.sleep();
    }
    

/*
while(ros::ok()){
    geometry_msgs::Twist msg;
    msg.linear.x = 2.0;

    msg.angular.z = 2.0;

    pub.publish(msg);

    ROS_INFO_STREAM("Sending velocity command:"<<" linear="<<msg.linear.x<<" angular="<<msg.angular.z);

    rate.sleep();
    } */
}