#ifndef __TOEULER_CPP_INCLUDED__
#define __TOEULER_CPP_INCLUDED__
#define _USE_MATH_DEFINES

#include "ToEuler.h"
#include "gimbalFunc.h"
#include <cmath>

//FIXME ??? The process might be wrong. If it's wrong, then change the calculations only. 
Euler ToEulerAngles (Quaternion qInput) {
    
    Euler output;
    // roll (x-axis rotation)
    double sinr_cosp = 2 * (qInput.w * qInput.x + qInput.y * qInput.z);
    double cosr_cosp = 1 - 2 * (qInput.x * qInput.x + qInput.y * qInput.y);
    output.roll = std::atan2(sinr_cosp, cosr_cosp);

    // pitch (y-axis rotation)
    double sinp = 2 * (qInput.w * qInput.y - qInput.z * qInput.x);
    if (std::abs(sinp) >= 1)
        output.pitch = copysign(M_PI / 2, sinp); // use 90 degrees if out of range
    else
        output.pitch = std::asin(sinp);

    // yaw (z-axis rotation)
    double siny_cosp = 2 * (qInput.w * qInput.z + qInput.x * qInput.y);
    double cosy_cosp = 1 - 2 * (qInput.y * qInput.y + qInput.z * qInput.z);
    output.yaw = std::atan2(siny_cosp, cosy_cosp);

    return output;
}
//From https://en.wikipedia.org/wiki/Conversion_between_quaternions_and_Euler_angles


#endif
