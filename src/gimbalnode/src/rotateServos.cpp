#pragma once
#include "rotateServos.h"
#include "ToEuler.h"
#include "gimbalFunc.h"


//Note, why do we need a quaternion output if it's a void function!?

void move(Euler input) {
//put the "move motors" calculations and all that here. 
}

Euler chunker(Euler input1, Euler input2) {
   //breaks the distance moved into a more managable chunk
}



void RotateServos(Quaternion input, Quaternion output) {
// input is quatCurrent and output is quatDesired
   Euler iAngles;
   Euler oAngles;
   Euler transform;   
   iAngles = ToEulerAngles(input);
   oAngles = ToEulerAngles(output);
   
   transform = chunker(iAngles, oAngles);   
   move(transform);
// 

}
//should we have it so that it only moves a certain amount before ending?
