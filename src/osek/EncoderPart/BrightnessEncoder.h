#ifndef Brightness_Encoder
#define Brightness_Encoder

#include "../HardwareWrapper/LightSensor.h"
#include "../lib/LowPassFillter.h"


typedef struct {
	char port_id;
	float brightness;
	int black_value;
	int white_value;
	LowPassFillter *lowPassfFillter;
}BrightnessEncoder;


void BrightnessEncoder_init(BrightnessEncoder *self,char port_id,LowPassFillter *lowPassfFillter);
int BrightnessEncoder_get_brightness(BrightnessEncoder *self);
float BrightnessEncoder_get_brightness_normalize(BrightnessEncoder *self);
void BrightnessEncoder_cal_normalized_brightness_(BrightnessEncoder *self);
void BrightnessEncoder_set_black(BrightnessEncoder *self,int black);
void BrightnessEncoder_set_white(BrightnessEncoder *self,int white);

#endif
