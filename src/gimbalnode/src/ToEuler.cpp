#define _USE_MATH_DEFINES

#include "ToEuler.h"
#include "gimbalFunc.h"
#include <cmath>

void ToEulerAngles (Quaternion qInput, Euler& eInput) {

    // roll (x-axis rotation)
    double sinr_cosp = 2 * (qInput.w * qInput.x + qInput.y * qInput.z);
    double cosr_cosp = 1 - 2 * (qInput.x * qInput.x + qInput.y * qInput.y);
    eInput.roll = std::atan2(sinr_cosp, cosr_cosp);

    // pitch (y-axis rotation)
    double sinp = 2 * (qInput.w * qInput.y - qInput.z * qInput.x);
    if (std::abs(sinp) >= 1)
        eInput.pitch = std::copysign(M_PI / 2, sinp); // use 90 degrees if out of range
    else
        eInput.pitch = std::asin(sinp);

    // yaw (z-axis rotation)
    double siny_cosp = 2 * (qInput.w * qInput.z + qInput.x * qInput.y);
    double cosy_cosp = 1 - 2 * (qInput.y * qInput.y + qInput.z * qInput.z);
    eInput.yaw = std::atan2(siny_cosp, cosy_cosp);
}
