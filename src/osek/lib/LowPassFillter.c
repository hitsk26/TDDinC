#include "LowPassFillter.h"


void LowPassFillter_init(LowPassFillter *self,float gain){
	self->gain = gain;
	self->buf = 0.5;
}
float LowPassFilter_get_filltered_value(LowPassFillter *self,float mesured_value){
	float filltered_value = 0;

	filltered_value = self->gain* mesured_value + (1-self->gain)*self->buf ;
	self->buf = filltered_value ;

	return filltered_value;
}
