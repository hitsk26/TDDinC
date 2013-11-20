#include "BrightnessEncoder.h"
#include "../Factory.h"

void BrightnessEncoder_init(BrightnessEncoder *self,char port_id,LowPassFillter *lowPassFillter)
{
	self->port_id = port_id;
	self->brightness=0;
	self->black_value = 0;
	self->white_value = 0;

	self->lowPassfFillter = lowPassFillter;

	LowPassFillter_init(self->lowPassfFillter,0.1);

}

int BrightnessEncoder_get_brightness(BrightnessEncoder *self)
{
	return LightSensor_get_light_sensor(self->port_id);
}

float BrightnessEncoder_get_brightness_normalize(BrightnessEncoder *self){

	return self->brightness;
}


void BrightnessEncoder_cal_normalized_brightness_(BrightnessEncoder *self){
	int brightness = LightSensor_get_light_sensor(self->port_id);
	float normalized_brightness = (float)(brightness - self->white_value)
		/(float)(self->black_value - self->white_value);

	float filltered_normalized_brightness = LowPassFilter_get_filltered_value(self->lowPassfFillter,normalized_brightness);

	self->brightness = filltered_normalized_brightness;

}

void BrightnessEncoder_set_black(BrightnessEncoder *self,int black){
	self->black_value = black;
}
void BrightnessEncoder_set_white(BrightnessEncoder *self,int white){
	self->white_value = white;
}

