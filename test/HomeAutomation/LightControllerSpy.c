#include "LightControllerSpy.h"

static int lastID;
static int lastState;


void LightController_Create(void)
{
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

void LightController_On(int id)
{
	lastID = id;
	lastState = LIGHT_ON;
}