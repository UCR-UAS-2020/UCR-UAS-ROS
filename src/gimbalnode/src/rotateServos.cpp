#pragma once
#include "rotateServos.h"
#include "ToEuler.h"
#include "gimbalFunc.h"
#include <string>
#include "ros/ros.h"
#include "std_msgs/String.h"

//Note, why do we need a quaternion output if it's a void function!?

string moveCalculation(Euler input) {
//put the "move motors" calculations and all that here
//converts translation into proper string msg 
}

Euler chunker(Euler input1, Euler input2) {
   //breaks the distance moved into a more managable chunk
}



void RotateServos(Quaternion input, Quaternion output) {
// input is quatCurrent and output is quatDesired
   Euler iAngles;
   Euler oAngles;
   Euler transform;   
   std_msgs::String maestroOutput;
   iAngles = ToEulerAngles(input);
   oAngles = ToEulerAngles(output);
   
   transform = chunker(iAngles, oAngles);   
   maestroOutput = moveCalculation(transform);
   maestro_command.publish(maestroOutput);
// 

}
//should we have it so that it only moves a certain amount before ending?
