#include "LightControllerSpy.h"

enum {
	MAX_LEDS = 31
};
static int lastID;
static int lastState;
static int lights[MAX_LEDS];

void LightController_Create(void)
{
	int i=0;
	for(i=0;i<MAX_LEDS;i++){
		lights[i]= LIGHT_OFF;
	}
	lastID = LIGHT_ID_UNKNOWN;
	lastState = LIGHT_STATE_UNKNOWN;


}

void LightController_Destroy(void)
{

}

int LightControllerSpy_GetLastId()
{
	return lastID;

}
int LightControllerSpy_GetLastState()
{
	return lastState;
}
int LightControllerSpy_GetLightState(int id){

	return lights[id];
}
void LightController_On(int id)
{
	lastID = id;
	lastState = LIGHT_ON;
	lights[id] = LIGHT_ON;
}
void LightController_Off(int id)
{
	lastID = id;
	lastState = LIGHT_OFF;
	lights[id] = LIGHT_OFF;
}
