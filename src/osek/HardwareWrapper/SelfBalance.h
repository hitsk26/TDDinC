#ifndef __SelfBalance
#define __SelfBalance


void SelfBalance_init(void);
void SelfBalance_control( float forward ,float  turn, float inclination,float gyro_offset,float count_left,float count_right,float volt,int *pwm_l,int *pwm_r);

#endif

