#ifndef _WheelActuator_H_
#define _WheelActuator_H_



#include "WheelMotor.h"
#include "../HardwareWrapper/SelfBalance.h"



typedef struct{
	float forward;
	float turn;
	int self_balancing_requirment;
}WheelActuator;



extern void WheelActuator_init(WheelActuator *self);
extern void WheelActuator_balance_running(WheelActuator *self,int *pwm_l,int *pwm_r);
extern void WheelActuator_set_forward(WheelActuator *self , float forward);
extern void WheelActuator_set_turn(WheelActuator *self , float turn);
extern void WheelActuator_tail_running(WheelActuator *self,int *pwm_l,int *pwm_r);
extern void WheelActuator_dirve_motors(WheelActuator *self);
void WheelActuator_set_self_balancing_requirement(WheelActuator *self,int self_balancing_requirment);

#endif

