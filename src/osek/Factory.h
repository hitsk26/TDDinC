#ifndef _FACTORY_H_
#define _FACTORY_H_





#include "./DrivenPart/WheelMotor.h"

#include "./DrivenPart/WheelActuator.h"


WheelActuator wheelActuator;
WheelMotor rightWheelMotor;
WheelMotor leftWheelMotor;


void initialization(void);
void clear_objects(void);


#endif


