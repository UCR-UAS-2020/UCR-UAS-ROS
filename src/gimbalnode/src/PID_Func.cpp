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

//might delete some of these functions later
void initPID(controlVars *ptr){
	
}

void setGains(ptr, kp, ki, kd){
	
}

double calculateOutput(controlVars *ptr, error){
	error =  
}

Quaternion initializeQuaternion(Quaternion desiredQuaternion){
	desiredQuaternion.x = 1 ;
	desiredQuaternion.y = 0 ;
	desiredQuaternion.z = 0 ;
	desiredQuaternion.w = 0 ;
	
	return desiredQuaternion ;
}

Quaternion calculateProportional(Quaternion errorQuaternion, double kp){
	proportional.x = kp * errorQuaternion.x ;
	proportional.y = kp * errorQuaternion.y ;
	proportional.z = kp * errorQuaternion.z ;
	proportional.w = kp * errorQuaternion.w ; 
	
	return proportional ;
}

Quaternion calculateError(Quaternion desiredQuaternion, Quaternion current){
	errorQuaternion.x = desiredQuaternion.x - current.x ;
	errorQuaternion.y = desiredQuaternion.y - current.y ;
	errorQuaternion.z = desiredQuaternion.z - current.z ;
	errorQuaternion.w = desiredQuaternion.w - current.w ;
	
	return errorQuaternion ;
}

Quaternion calculateIntegral(double ki, Quaternion kiPrior, Quaternion errorQuaternion, double iterationTime){
	integral.x = ki * (kiPrior.x + (errorQuaternion.x * iterationTime)) ;
	integral.y = ki * (kiPrior.y + (errorQuaternion.y * iterationTime)) ;
	integral.z = ki * (kiPrior.z + (errorQuaternion.z * iterationTime)) ;
	integral.w = ki * (kiPrior.w + (errorQuaternion.w * iterationTime)) ;
	
	return integral ;
}

Quaternion storeIntegral(Quaternion integral){
	kiPrior.x = integral.x ;
	kiPrior.y = integral.y ;
	kiPrior.z = integral.z ;
	kiPrior.w = integral.w ;
	
	return kiPrior ;
}

Quaternion calculateDerivative(Quaternion errorQuaternion, Quaternion errorPrior, double iterationTime, double kd){
	derivative.x = kd * ((errorQuaternion.x - errorPrior.x)/iterationTime) ;
	derivative.y = kd * ((errorQuaternion.y - errorPrior.y)/iterationTime) ;
	derivative.z = kd * ((errorQuaternion.z - errorPrior.z)/iterationTime) ;
	derivative.w = kd * ((errorQuaternion.w - errorPrior.w)/iterationTime) ;
	
	return derivative ;
}

Quaternion storeError(Quaternion errorQuaternion){
	errorPrior.x = errorQuaternion.x ;
	errorPrior.y = errorQuaternion.y ;
	errorPrior.z = errorQuaternion.z ;
	errorPrior.w = errorQuaternion.w ;
	
	return errorPrior ;
}

Quaternion calculateQuaternion(Quaternion proportional, Quaternion integral, Quaternion derivative, double bias){
	outputQuaternion.x = proportional.x + integral.x + derivative.x + bias ;
	outputQuaternion.y = proportional.y + integral.y + derivative.y + bias ;
	outputQuaternion.z = proportional.z + integral.z + derivative.z + bias ;
	outputQuaternion.w = proportional.w + integral.w + derivative.w + bias ;
	
	return outputQuaternion ;
}

Quaternion PredictQuaternion(Quaternion current, Quaternion &past){
	//Quaternion desiredQuaternion ;
	//accessing data member from struct
	//desiredQuaternion.x = 1 ;
	//desiredQuaternion.y = 0 ;
	//desiredQuaternion.z = 0 ;
	//desiredQuaternion.w = 0 ;
	
	//calculate error
	//Quaternion errorQuaternion ;
	////errorQuaternion now has the same values as Quaternion
	////reference gimbalFunc.h to see vals 
	//errorQuaternion.x = desiredQuaternion.x - current.x ;
	//errorQuaternion.y = desiredQuaternion.y - current.y ;
	//errorQuaternion.z = desiredQuaternion.z - current.z ;
	//errorQuaternion.w = desiredQuaternion.w - current.w ;
	
	//calculate P = kp * error
	//Quaternion proportional ;
	////assume kp is already chosen and tuned
	//proportional.x = kp * errorQuaternion.x ;
	//proportional.y = kp * errorQuaternion.y ;
	//proportional.z = kp * errorQuaternion.z ;
	//proportional.w = kp * errorQuaternion.w ; 
	
	//calculate I = ki * (integral + (error * iteration_time))
	//assuming integralVal is already declared
	//Quaternion integral ;
	
	//integral.x = ki * (integralVal + (errorQuaternion.x * dt)) ;
	//integral.y = ki * (integralVal + (errorQuaternion.y * dt)) ;
	//integral.z = ki * (integralVal + (errorQuaternion.z * dt)) ;
	//integral.w = ki * (integralVal + (errorQuaternion.w * dt)) ;
	
	//calculate D = kd * ((error - priorError)/iteration_time)
	//assuming kd and dt are already declared
	//Quaternion derivative ;
	
	//derivative.x = kd * ((errorQuaternion.x - past.x)/dt) ;
	//derivative.y = kd * ((errorQuaternion.y - past.y)/dt) ;
	//derivative.z = kd * ((errorQuaternion.z - past.z)/dt) ;
	//derivative.w = kd * ((errorQuaternion.w - past.w)/dt) ;
	
	////write current errors to past
	//past.x = errorQuaternion.x ;
	//past.y = errorQuaternion.y ;
	//past.z = errorQuaternion.z ;
	//past.w = errorQuaternion.w ;
	
	////Calculate output = P + I + D + bias
	////bias used to ensure output != 0
	//Quaternion outputQuaternion ;
	
	//outputQuaternion.x = proportional.x + integral.x + derivative.x + bias ;
	//outputQuaternion.y = proportional.y + integral.y + derivative.y + bias ;
	//outputQuaternion.z = proportional.z + integral.z + derivative.z + bias ;
	//outputQuaternion.w = proportional.w + integral.w + derivative.w + bias ;
}

int main(){
	
	//initialize variables needed for PID
	//the variables can be changed to tune the controller
	double bias = 0.10 ;
	double kp = 0.85 ;
	double ki = 0.12 ;
	double kd = 0.09 ;
	double iterationTime = 0.250 ;	//250 [ms] <--> 0.25 [s]
	
	//initialize error vals
	errorQuaternion.x = 0.00 ;
	errorQuaternion.y = 0.00 ;
	errorQuaternion.z = 0.00 ;
	errorQuaternion.w = 0.00 ;
	
	/*
	 * =========      TO DO:         ========
	 * ========= get current values =========
	 * == make while loop for calculations ==
	 * */
	 
	 //initialize the desired Quaternion
	 desiredQuaternion = initializeQuaternion(desiredQuaternion) ;
	 
	 //==========================
	 //begin while loop here
	 //calculate error value
	 errorQuaternion = calculateError(desiredQuaternion, current) ;
	 //calculate P
	 //P = kp * errorQuaternion
	 proportional = calculateProportional(errorQuaternion, kp) ;
	 //calculate I
	 //I = ki * (kiPrior + errorQuaternion * iterationTime)
	 integral = calculateIntegral(ki, kiPrior, errorQuaternion, iterationTime) ;
	 //store integral
	 kiPrior = storeIntegral(integral) ;
	 //calculate D
	 //D = kd * (error - errorPrior)/iterationTime
	 derivative = calculateDerivative(errorQuaternion, errorPrior, iterationTime, kd) ;
	 //store error
	 errorPrior = storeError(errorQuaternion) ;
	 //output = P + I + D + bias 
	 outputQuaternion = calculateQuaternion(proportional, integral, derivative, bias) ;
	
	return 0 ;
}
