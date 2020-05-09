#include "ros/ros.h"
#include "std_msgs/String.h"
#include "gimbalFunc.h"

#include <sstream>

int main(int argc, char **argv){
	ros::init(argc, argv, "publishMaestro") ;
	ros::Nodehandle n ;
	
	ros::Publisher publishToMaestro = n.advertise<std_msgs::String>("commandingMaestro", 10) ;
	
	ros::Rate loop_rate(10) ;
	
	while(ros::ok()){
		std_msgs::String msg ;
		
		std::stringstream ss ;
		
		//temporary work-around for reading motor val and position
		//using motor 1, position 1500
		std::stringstream maestroVals ;
		maestroVals = "011500" ; 
		
		//string contains motor and position
		ss << maestroVals ;
		msg.data = ss.str() ;
		
		publishToMaestro.publish(msg) ;
		ros::spinOnce() ;
		loop_rate.sleep() ;
	}
	
	return 0 ;
}
