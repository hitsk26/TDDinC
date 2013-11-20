#ifndef __LowPassFillter
#define __LowPassFillter

typedef struct {
float gain;
float buf;
}LowPassFillter;

void LowPassFillter_init(LowPassFillter *self,float gain);
float LowPassFilter_get_filltered_value(LowPassFillter *self,float mesured_value);

#endif
