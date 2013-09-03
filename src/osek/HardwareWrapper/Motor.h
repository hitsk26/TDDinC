#ifndef __Motor
#define __Motor

int Motor_get_count(unsigned int port_id);
void Motor_set_speed(unsigned int port_id, int pwm, int brake);


#endif

