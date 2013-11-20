#include "LightSensor.h"
#include "ecrobot_interface.h"

unsigned int  LightSensor_get_light_sensor(char port_id)
{
	return ecrobot_get_light_sensor(port_id);
}
