#ifndef gimbalFunc
#define gimbalFunc

struct Quaternion {
  double x;
  double y;
  double z;
  double w;
};

struct eulerAngles{	//made this struct in case of using it to compare servo vals
	double roll ;
	double pitch ;
	double yaw ;
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
Quaternion firstServo ;				//used to get vals from servo motors
Quaternion secondServo ;
Quaternion storeFirstServo ;
Quaternion storeSecondServo ;

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

void storeServoVals(firstServo, secondServo) ;
void rotateQuaternion(Quaternion desiredQuaternion) ;
//void rotateAboutX(Quaternion current) ;
void rotateAboutY(Quaternion desiredQuaternion) ;
void rotateAboutZ(Quaternion desiredQuaternion) ;
void quaternionToRPY(Quaternion currentQuaternion) ;
void eulerCallback(const tf2_geometry_msgs::tf2_geometry_msgs::ConstPtr& msg) ;
void maestroCallback(const std_msgs::String::ConstPtr& msg) ;
void initMaestro() ;
Quaternion compareServoVals(Quaternion current, Quaternion ) ;

#endif
