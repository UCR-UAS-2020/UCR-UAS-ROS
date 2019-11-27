#ifndef PID_gimbal
#define PID_gimbal

struct controlPID{
	double kp, ki, kd, integrator, prevError, integratorLims, freq ;
	//kp - coefficient of proportion
	//ki - coefficient of integrator
	//kd - coefficient of derivative
} ;

/*
 * -----initialize the variables in PID-----
 * 		ki = kd = 0
 * 		kp = 1
 * 		integratorLims = ? (large number)
 * 		integrator = 0
 * 		freq = ? (not yet decided)
 * */

void initPID(controlVars *ptr) ;

// -----Declare vals of gains-----
void setGains(controlVars *ptr, int kp, int ki, int kd) ;
 
// -----Get vals of gains-----
void getGains(controlVars *ptr, int kp, int ki, int kd) ;

 // -----Get lims of integration-----
  
double getIntegrationLims(const controlVars *ptr) ;

 /*
  * -----Get output val-----
  * 	create doubles for vars: P, I, D, error, bias
  * 	(bias is to ensure output != 0)
  * 
  * 	error = wantedVal - measuredVal
  * 	P = kp * error
  * 	I = ki * integral(error * dt)
  * 	D = kd * ((error - priorError)/freq)
  * 	priorError = error ;
  * 	output = P + I + D + bias
  * */

double calculateOutput(controlVars *ptr, double error);

// -----Get vals of integration-----
double calculateIntegration(const controlVars *ptr) ;

// -----set new integration lim-----
double setIntegrationLim(controlVars *ptr) ;

// -----reset PID integrator-----
//reset the integrator to 0
void resetPID(controlVars *ptr) ;

// -----set frequency-----
void setFrequencyPID(controlVars *ptr, double frequency) ;

// -----get frequency-----
void getFrequencyPID(controlVars *ptr) ;

#endif
