#pragma once
#include "gimbalFunc.h"


struct Euler {
   double pitch;
   double yaw;
   double roll;
};

Euler ToEulerAngles (Quaternion qInput);

#include "ToEuler.cpp"
//Don't putt the ToEuler.cpp header to the top. It WILL produce Euler not defined errors in the ToEuler.cpp
//If you're a CS major, you'll understand after looking at the code a little bit. If not, too bad. DON'T MOVE IT
