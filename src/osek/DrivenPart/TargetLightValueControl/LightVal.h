#ifndef _LIGHT_VAL_H
#define _LIGHT_VAL_H

#include "../../EncoderPart/BrightnessEncoder.h"

typedef struct{
	float targLightVal;
}LightVal;


extern void LV_init(LightVal *this_LightVal);

#endif
