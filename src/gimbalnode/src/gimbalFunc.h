#ifndef gimbalFunc
#define gimbalFunc

struct Quaternion {
  double x;
  double y;
  double z;
  double w;
};

void RotateServos(Quaternion input, Quaternion output);

//listing all quaternions that will be used
Quaternion current ;
Quaternion desiredQuaternion ;
Quaternion errorQuaternion ;
Quaternion proportional ;
Quaternion integral ;
Quaternion kiPrior ;
Quaternion derivative ;
Quaternion errorPrior ;
Quaternion outputQuaternion ;

//list functions
Quaternion initializeQuaternion(Quaternion desiredQuaternion) ;
Quaternion calculateError(Quaternion desiredQuaternion, Quaternion current) ;
Quaternion calculateProportional(Quaternion errorQuaternion, double kp) ;
Quaternion calculateIntegral(double ki, Quaternion kiPrior, Quaternion errorQuaternion, double iterationTime) ;
Quaternion storeIntegral(Quaternion integral) ;
Quaternion calculateDerivative(Quaternion errorQuaternion, Quaternion errorPrior, double iterationTime, double kd) ;
Quaternion storeError(Quaternion errorQuaternion) ;
Quaternion calculateQuaternion(Quaternion proportional, Quaternion integral, Quaternion derivative, double bias) ;

Quaternion PredictQuaternion(Quaternion current, Quaternion past);

Quaternion RecieveQuaternionIMU();

#endif
