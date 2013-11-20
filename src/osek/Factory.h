#ifndef _FACTORY_H_
#define _FACTORY_H_





#include "./DrivenPart/WheelMotor.h"

#include "./DrivenPart/WheelActuator.h"

#include "EncoderPart/BrightnessEncoder.h"


WheelActuator wheelActuator;
WheelMotor rightWheelMotor;
WheelMotor leftWheelMotor;

BrightnessEncoder  brightnessEncoder;

/*DrivenPart/LightValueContrl*/


void initialization(void);
void clear_objects(void);


#endif


