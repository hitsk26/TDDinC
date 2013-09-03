#include "../HardWareWrapper/SelfBalance.h"
#include "stdio.h"

void SelfBalance_init()
{
	/*balance_init();*/
}

void SelfBalance_control( float forward ,float  turn, float inclination,float gyro_offset,float count_left,float count_right,float volt,int *pwm_l,int *pwm_r)
{
	
	float hoge= (float)forward+ (float)turn+(float)inclination+(float)gyro_offset+(float)count_left+(float)count_right+(float)volt+(float)*pwm_l+(float)*pwm_r;
	printf("%f",hoge);
	
}

