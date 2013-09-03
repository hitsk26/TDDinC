#include "WheelActuator.h"
#include "../Factory.h"


void WheelActuator_init(WheelActuator *self){
	self->forward = 0;
	self->turn = 0;
	SelfBalance_init();
}

void WheelActuator_balance_running(WheelActuator *self,int *pwm_l,int *pwm_r){
	SelfBalance_control(self->forward ,self->turn,/*inclination*/600,/*gyro_offset*/600,0/*count_left*/,/*count_right*/0,/*vold*/8000,pwm_l,pwm_r);
}


void WheelActuator_set_forward(WheelActuator *self , float forward){
	self->forward = forward;
}

void WheelActuator_set_turn(WheelActuator *self , float turn){
	self->turn = turn;
}

void WheelActuator_tail_running(WheelActuator *self,int *pwm_l,int *pwm_r){
	*pwm_l = (int)(self->forward + 	self->turn);
	*pwm_r = (int)(self->forward - 	self->turn);
}

void WheelActuator_dirve_motors(WheelActuator *self){
	int pwm_l=0,pwm_r=0;
	if(self->self_balancing_requirment == 1){
		WheelActuator_balance_running(self,&pwm_l,&pwm_r);
	}
	else if(self->self_balancing_requirment==0){
		 WheelActuator_tail_running(self,&pwm_l,&pwm_r);
	}
	else {
	/*fetal error*/
	}

	WheelMotor_drive_motor(&leftWheelMotor,pwm_l);
	WheelMotor_drive_motor(&rightWheelMotor,pwm_r);
}


void WheelActuator_set_self_balancing_requirement(WheelActuator *self,int self_balancing_requirment){
	self->self_balancing_requirment= self_balancing_requirment;
}