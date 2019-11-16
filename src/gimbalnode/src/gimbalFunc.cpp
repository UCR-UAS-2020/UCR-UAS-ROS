//Add in the euler converter to the thingy. Question: will the servos move incrementally? How will they adjust path if the quaternions begin to shift drastically?
//FIXME error: undefined reference to 'ToEulerAngles(Quaternion, Euler)' AND ld returned 1 exit status

#include "gimbalFunc.h"
#include "ToEuler.h"
#include "rotateServos.h"

#include "ros/ros.h"
#include "geometry_msgs/Quaternion.h"
#include "std_msgs/String.h"

#include <sstream>

const int LOOP_RATE_GIMBAL = 10;

Quaternion quatDesired = {
  0,
  0,
  0,
  1
};

Quaternion quatCurrent;
Euler eulerAngles;

void quaternionMessage(const geometry_msgs::Quaternion& msg) {
  quatCurrent.x = msg.x;
  quatCurrent.y = msg.y;
  quatCurrent.z = msg.z;
  quatCurrent.w = msg.w;   
  ///*
  ROS_INFO("I heard: [%f]", quatCurrent.x);
  ROS_INFO("I heard: [%f]", quatCurrent.y);
  ROS_INFO("I heard: [%f]", quatCurrent.z);
  ROS_INFO("I heard: [%f]", quatCurrent.w);
  //*/ // Comment out during actual flights
} 

int main(int argc, char** argv) {
  ros::init(argc, argv, "gimbalNode");
  
  ros::NodeHandle n;
  //The subscription should be towards wherever the subscribed node is.
  ros::Subscriber sub = n.subscribe("chatter", 1000, quaternionMessage);
  //will ros::spin() be necessary? 
 
  ros::Rate loop_rate(LOOP_RATE_GIMBAL);
  
  
  while(ros::ok) {
    //ros::spinOnce();
    
    ROS_INFO("gimbalNode is running %d",LOOP_RATE_GIMBAL);
    quatCurrent = RecieveQuaternionIMU();
    eulerAngles = ToEulerAngles(quatCurrent);
    ROS_INFO("%f", eulerAngles.roll);
    ROS_INFO("%f", eulerAngles.pitch);
    ROS_INFO("%f", eulerAngles.yaw);

    //quatDesired = PredictQuaternion(quatCurrent, 
    
   // RotateServos(quatCurrent, quatDesired); FIXME Put back in later.

    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}

/*
void RotateServos(Quaternion input, Quaternion output) {
  //nothing
}
*///Decided that it might be better if we separate RotateServos from main function and create a separate function

Quaternion PredictQuaternion(Quaternion current, Quaternion past) {
  Quaternion dummyQuaternion = {0, 0, 0, 1};
  return dummyQuaternion;
}

Quaternion RecieveQuaternionIMU() {
  Quaternion dummyQuaternion = {-.002, -0.801, 0.267, 0.536};
  return dummyQuaternion;
}
//en.wikipedia.org/wiki/Conversion_between_quaternions_and_Euler_anglesendif
