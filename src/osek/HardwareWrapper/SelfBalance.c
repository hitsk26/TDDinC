#include "SelfBalance.h"
#include "balancer.h"

void SelfBalance_init()
{
	balance_init();
}

void SelfBalance_control( float forward ,float  turn, float inclination,float gyro_offset,float count_left,float count_right,float volt,S8 *pwm_l,S8 *pwm_r)
{
	balance_control(
				(F32)forward,
				(F32)turn,
				(F32)inclination,
				(F32)gyro_offset,
				(F32)count_left,
				(F32)count_right,
				(F32)volt,
				pwm_l,
				pwm_r);
}

