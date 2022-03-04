#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"

 
int main(int argc, char **argv){
ros::init(argc, argv, "publish_velocity_turtle1");
ros::NodeHandle nh;

ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);

srand(time(0));

ros::Rate rate(2);
while(ros::ok()){
    geometry_msgs::Twist msg;
    msg.linear.x = 2.0;

    msg.angular.z = 2.0;

    pub.publish(msg);

    ROS_INFO_STREAM("Sending velocity command:"<<" linear="<<msg.linear.x<<" angular="<<msg.angular.z);

    rate.sleep();
    }
}