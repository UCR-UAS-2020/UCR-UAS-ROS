/*
 * quaternionPID.cpp
 * 
 * Copyright 2020 CarlosPacheco <carlospacheco@carlospacheco-VirtualBox>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

// (1) function predicts euler angles
// store (2) servo vals from gimbal, compare current rotation value
// get IMU data (current rotation value)
// (1) PID usage from predicted vals

#include <iostream>
#include <cmath>
#include <sstream>
#include <sensor_msg/Imu.h>
#include <tf2/LinearMath/Quaternion.h>			//allows tf2 classes
#include <tf2_geometry_msgs/tf2_geometry_msgs>  //converts between msg and tf

#include "tf/transform_datatypes.h"				//used for tf
#include "gimbalFunc.h"
#include "ros/ros.h"
#include "std_msgs/String.h"

using namespace std ;

const double pi = 3.14159 ;						//used in rotation function

//function that predicts euler angles

//function applies quaternion rotation
void rotateQuaternion(Quaternion desiredQuaternion){
	//tf2::Quaternion q_orig, q_rot, q_new ;
	tf2::Quaternion q_rot, q_new ;
	double r = pi, p = 0, y = 0 ; 
	
	//get original orientation of 'command_pose'
	tf2::convert(command_pose.pose.orientation, q_orig) ;
	q_rot.setRPY(r, p, y) ;
	//calculate new quaternion
	q_new = q_rot * q_orig ;
	q_new.normalize() ;
	
	//convert into msg type
	tf2::convert(q_new, command_pose.pose.orientation) ;
}

//converts from quaternion to RPY
void quaternionToRPY(Quaternion currentQuaternion){
	tfScalar yaw, pitch, roll ;
	tf::Matrix3x3 mat(currentQuaternion) ;
	mat.getEulerYPR(&yaw, &pitch, &roll) ;
}

//function that stores servo vals
void storeServoVals(Quaternion firstServo, Quaternion secondServo){
	//get values from first servo
	storeFirstServo.x = firstServo.x ;
	storeFirstServo.y = firstServo.y ;
	storeFirstServo.z = firstServo.z ;
	storeFirstServo.w = firstServo.w ;
	
	//get values from second servo
	storeSecondServo.x = secondServo.x ;
	storeSecondServo.y = secondServo.y ;
	storeSecondServo.z = secondServo.z ;
	storeSecondServo.w = secondServo.w ;
}

//function that compares vals
Quaternion compareServoVals(Quaternion current, ) {
	
	return 
}

int main(int argc, char **argv) {
	
	ros::init(argc, argv, "quaternionPID") ;
	ros::NodeHandle p ;
	ros::Subscriber subscribePos ;
	subscribePos = p.subscribe(
	
	ros::spin() ;
	return 0;
}

