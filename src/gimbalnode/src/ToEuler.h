#include "gimbalFunc.h"

struct Euler {
   double pitch;
   double yaw;
   double roll;
};

void ToEulerAngles (Quaternion qInput, Euler& eInput);
