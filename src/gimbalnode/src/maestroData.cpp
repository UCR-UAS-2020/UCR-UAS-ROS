/*
 * maestroData.cpp
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
#include <fcntl.h>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <termios.h>					//modified from _WIN32 ... look @ the pololu github for further details

#include "gimbalFunc.h"
#include "ros/ros.h"
#include "std_msgs/String.h"

using namespace std ;

int fd ;

//(2) motors are being read, therefore use (2) 2x1 unsigned char arrays to store position
//uses the form: 0xYYYY
//first element of array are last 8 bits from read value
//second element of array are leading 8 bits from read value
//ex: 2564 --> 0x0A07 --> [maestro conversion] --> [0x07; 0x0A] (inside 2x1 u.c. array]

//function to get maestro vals
int getGyroData(int port, int channel){
	//from maestro user guide, serial servo commands:
	//channel number: 0x90
	//maximum [us] is ~4000 --> maximum [s] is 0.004		change iteration time in PID_Func?
	unsigned char command[2] ;								//use (2) u.c. 
	command[0] = 0x90 ;										//command to get position
	command[1] = channel ;
										//holds servo value
	if(write(port, command, sizeof(commands) == -1){
		perror("error in writing") ;
		return -1 ;
	}
	
	unsigned char response[2] ;
	if(read(port, response, 2) != 2){
		perror("error in reading") ;
		return -1 ;
	}
	
	return response[0] + 256 * response[1] ;
}

void maestroCallback(const std_msgs::String::ConstPtr& msg) {
	//also from github
	std::string temp = msg->data ;
	//substr has arguments of (position, length) for string
	//can also have (position) where length is npos
	std::string channel = temp.substr(0, 2) ;		//should be within [0,5]
	std::string target = temp.substr(2) ;			//should be [1100, 1900]
	
	//convert string to integer vals
	int channelRead = stoi(channel) ;
	int targetRead = stoi(target) ;
	
	if(!(channelRead >= 0 && channelRead <= 5)){
		ROS_ERROR("Not within channels 0-5 ... channel read: %d", channelRead) ;
	}
	//following values can be modified for motor
	else if(!(targetRead >= 1100 && targetRead <= 1900)){
		ROS_ERROR("Not within bounds ... target read: %d", targetRead) ;
	}
	else{
		int gyroDataVal ;
		gyroDataVal = getGyroData(fd, 5) ;
		ROS_INFO("Current position is: %d", gyroDataVal) ;
	}
}

void initMaestro(){
	struct termios options ;
	tcgetattr(fd, &options);
	options.c_iflag &= ~(INLCR | IGNCR | ICRNL | IXON | IXOFF);
	options.c_oflag &= ~(ONLCR | OCRNL);
	options.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
	tcsetattr(fd, TCSANOW, &options);
}

int main(int argc, char **argv) {
	const char * device = "/dev/ttyACM0" ;		//used for Maestro port on Linux
	
	fd = open(device, O_RDWR | O_NOCTTY) ;		//O_NOCTTY is included inside of termios.h
	if(fd == -1){
		perror(device) ;
		return -1 ;
	}
	
	initMaestro() ;							//moved commands into a function
											//check maestro github for further details
	
	ros::init(argc, argv, "maestroData") ;
	ros::Nodehandle n_maestro ;
	ros::Subscriber subMaestro = n_maestro.subscribe("commandingMaestro", 10, maestroCallback) ;
	ros::spin() ;
	
	return 0;
}
