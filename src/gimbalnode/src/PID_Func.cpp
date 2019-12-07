/*
 * PID_gimbal.cpp
 * 
 * Copyright 2019 CarlosPacheco <carlospacheco@carlospacheco-VirtualBox>
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


#include <iostream>
#include <cmath>
#include "PID_gimbal.h"				//header from local directory

using namespace std ;

void initPID(controlVars *ptr){
	
}

void setGains(ptr, kp, ki, kd){
	
}

double calculateOutput(controlVars *ptr, error){
	error =  
}

Quaternion PredictQuaternion(Quaternion current, Quaternion &past){
	Quaternion desiredQuaternion ;
	//accessing data member from struct
	desiredQuaternion.x = 1 ;
	desiredQuaternion.y = 0 ;
	desiredQuaternion.z = 0 ;
	desiredQuaternion.w = 0 ;
	
	//calculate error
	Quaternion errorQuaternion ;
	//errorQuaternion now has the same values as Quaternion
	//reference gimbalFunc.h to see vals 
	errorQuaternion.x = desiredQuaternion.x - current.x ;
	errorQuaternion.y = desiredQuaternion.y - current.y ;
	errorQuaternion.z = desiredQuaternion.z - current.z ;
	errorQuaternion.w = desiredQuaternion.w - current.w ;
	
	//calculate P = kp * error
	Quaternion proportional ;
	//assume kp is already chosen and tuned
	proportional.x = kp * errorQuaternion.x ;
	proportional.y = kp * errorQuaternion.y ;
	proportional.z = kp * errorQuaternion.z ;
	proportional.w = kp * errorQuaternion.w ; 
	
	//calculate I = ki * (integral + (error * iteration_time))
	//assuming integralVal is already declared
	Quaternion integral ;
	
	integral.x = ki * (integralVal + (errorQuaternion.x * dt)) ;
	integral.y = ki * (integralVal + (errorQuaternion.y * dt)) ;
	integral.z = ki * (integralVal + (errorQuaternion.z * dt)) ;
	integral.w = ki * (integralVal + (errorQuaternion.w * dt)) ;
	
	//calculate D = kd * ((error - priorError)/iteration_time)
	//assuming kd and dt are already declared
	Quaternion derivative ;
	
	derivative.x = kd * ((errorQuaternion.x - past.x)/dt) ;
	derivative.y = kd * ((errorQuaternion.y - past.y)/dt) ;
	derivative.z = kd * ((errorQuaternion.z - past.z)/dt) ;
	derivative.w = kd * ((errorQuaternion.w - past.w)/dt) ;
	
	//write current errors to past
	past.x = errorQuaternion.x ;
	past.y = errorQuaternion.y ;
	past.z = errorQuaternion.z ;
	past.w = errorQuaternion.w ;
	
	//Calculate output = P + I + D + bias
	//bias used to ensure output != 0
	Quaternion outputQuaternion ;
	
	outputQuaternion.x = proportional.x + integral.x + derivative.x + bias ;
	outputQuaternion.y = proportional.y + integral.y + derivative.y + bias ;
	outputQuaternion.z = proportional.z + integral.z + derivative.z + bias ;
	outputQuaternion.w = proportional.w + integral.w + derivative.w + bias ;
}
