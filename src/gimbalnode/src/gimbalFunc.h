#ifndef __GIMBALNODE_H_INCLUDED__
#define __GIMBALNODE_H_INCLUDED__

struct Quaternion {
    double x;
    double y;
    double z;
    double w;
  };
 

void RotateServos(Quaternion input, Quaternion output);

Quaternion PredictQuaternion(Quaternion current, Quaternion past);

Quaternion RecieveQuaternionIMU();

#endif
