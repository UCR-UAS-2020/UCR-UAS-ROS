#include "gimbalFunc.h"

#include "ros/ros.h"
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

int main(int argc, char** argv) {
  ros::init(argc, argv, "gimbalNode");
  
  ros::Rate loop_rate(LOOP_RATE_GIMBAL);
  
  
  while(ros::ok) {
    ros::spinOnce();
    
    ROS_INFO("gimbalNode is running");
    quatCurrent = RecieveQuaternionIMU();
    
    //quatDesired = PredictQuaternion(quatCurrent, 
    
    RotateServos(quatCurrent, quatDesired);


    loop_rate.sleep();
  }
  return 0;
}


void RotateServos(Quaternion input, Quaternion output) {
  //nothing
}

Quaternion PredictQuaternion(Quaternion current, Quaternion past) {
  Quaternion dummyQuaternion = {0, 0, 0, 1};
  return dummyQuaternion;
}

Quaternion RecieveQuaternionIMU() {
  Quaternion dummyQuaternion = {0, 0, 0, 1};
  return dummyQuaternion;
}

