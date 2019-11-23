#pragma once
#include "rotateServos.h"
#include "ToEuler.h"
#include "gimbalFunc.h"
#include <string>
#include "ros/ros.h"
#include "std_msgs/String.h"

//Note, why do we need a quaternion output if it's a void function!?

const double PI_CONSTANT = 3.14159265358979323846;

string MoveCalculation(double angleInput) {
//put the "move motors" calculations and all that here
//converts translation into proper string msg
  //something like "go to this location" of the four character string
  /*assume from 0-pi in radians since the program already uses radians
   *Assume neutral position (12 o'clock) is 1500us
   *assume 3 oclock is 2000us (would be 8000quarterus)
   *assume 6 oclock is 1000us (would be 4000 quarter us
  */
  //pulse width in quarter-microseconds. If we want 1500us, multiply by four
  //NOTE: Will drop the decimal because rosMaestro only accept integer strings
  //FIXME: BE SURE TO CHANGE TARGET OVERBOUND IN THE MAESTRO CPP!!!
  
  int output;
  output = angleInput*1000/pi;
  return std::to_string(output);

}

Euler Chunker (Euler original, Euler desired) {
//does it so that the euler transformation is chunked. First finds the difference betwen the desired and current angles.
//Takes the difference and divides it by (INSERT DESIRED PARTITION!!!). It then adds that movement to the current angle
//and creates the new angle/position the servos will go to
  const double CONST_PARTITION = 0.1; //Currently one tenth
  desired.roll = (desired.roll - original.roll) * CONST_PARTITION;
  desired.pitch = (desired.pitch - original.pitch) * CONST_PARTITION;
  desired.yaw = (desired.yaw - original.yaw) * CONST_PARTITION;
 
  desired.roll = desired.roll + original.roll;
  desired.pitch = desired.pitch + original.pitch;
  desired.yaw = desired.yaw + original.yaw;

}

void RotateServos(Quaternion input, Quaternion output) {
// input is quatCurrent and output is quatDesired
   Euler iAngles;
   Euler oAngles;
   Euler transform; 
   string maestroRoll;
   string maestroPitch; //produce string to publish on the node

   std_msgs::String maestroOutput;
   iAngles = ToEulerAngles(input);
   oAngles = ToEulerAngles(output);
   
   transform = Chunker(iAngles, oAngles);   
   maestroRoll = MoveCalculation(transform.roll);
   maestroPitch = MoveCalculation(trasnform.pitch);

   maestroRoll = "02" + maestroRoll;   //Adds the first two identifying digits of the package.
   maestroPitch = "03" + maestroPitch; //FIXME: BE SURE TO CHANGE THE NUMBERS TO APPROPRIATE CHANNEL!!!
 
   maestro_command.publish(maestroRoll);
   meastro_command.publish(maestroPitch); 
// There might be an issue here... If somehow the message is not published, it'll end up going through the entire
// gauntlet once again... Have that happen millions of times and we have a problem :/

}
//should we have it so that it only moves a certain amount before ending?
