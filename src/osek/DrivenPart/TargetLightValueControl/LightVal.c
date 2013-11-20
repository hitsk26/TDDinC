#include "LightVal.h"
#include "../../Factory.h"

void LV_init(LightVal *this_LightVal){
	this_LightVal->targLightVal = 0.0;
}

float LV_getLightVal(LightVal *this_LightVal){
	float lightVal = BrightnessEncoder_get_brightness_normalize(&brightnessEncoder);


	return lightVal;
}
