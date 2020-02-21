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
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <termios.h>					//modified from _WIN32

#include "gimbalFunc.h"

using namespace std ;

//function to get maestro vals
int getGyroData(int port, int servo){
	//from maestro user guide, serial servo commands:
	//channel number: 0x90
	//maximum [us] is ~4000 --> maximum [s] is 0.004		change iteration time in PID_Func?
	unsigned char command[2] ;						//use (2) u.c. 
	command[1] = 0x90 ;								//command to get position
	command[2] = servo ;							//holds servo value
	
	return 1 ;										//place holder value until function is finished
}

int main(int argc, char **argv) {
	const char * device = "/dev/ttyACM0" ;		//used for Maestro port on Linux
	
	int fd = open(device, O_RDWR, O_NOCTTY) ;	//O_NOCTTY is included inside of termios.h
	if(fd == -1){
		perror(device) ;
		return -1 ;
	}
	
	
	return 0;
}

