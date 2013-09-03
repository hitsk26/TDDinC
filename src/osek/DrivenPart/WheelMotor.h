#ifndef __WheelMotor
#define __WheelMotor

#include "../HardwareWrapper/Motor.h"

typedef struct{
	unsigned int port_id;
}WheelMotor;

void WheelMotor_init(WheelMotor *this_WheelMotor,unsigned int port_id);
int WheelMotor_get_count(WheelMotor *this_WheelMotor);
void WheelMotor_drive_motor(WheelMotor *this_WheelMotor, int pwm);

#endif

