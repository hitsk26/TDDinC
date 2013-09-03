#include "WheelMotor.h"


void WheelMotor_init(WheelMotor *this_WheelMotor,unsigned int port_id){
	this_WheelMotor->port_id = port_id;
}

int WheelMotor_get_count(WheelMotor *this_WheelMotor)
{
	return Motor_get_count(this_WheelMotor->port_id);
}

void WheelMotor_drive_motor(WheelMotor *this_WheelMotor, int pwm)
{
Motor_set_speed(this_WheelMotor->port_id,pwm,1); 

}
