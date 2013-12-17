#include "TimeService.h"
#include "LightScheduler.h"
#include "LightController.h"

typedef struct 
{
	int id;
	int minuteOfDay;

}ScheduleLightEvent;

static ScheduleLightEvent scheduleLightEvent;


void LightScheduler_Create(void)
{
	scheduleLightEvent.id = UNUSED;
}

void LightScheduler_Destroy(void)
{

}

void LightScheduler_Wakeup(void)
{
	Time time;
	TimeService_GetTime(&time);

	if(scheduleLightEvent.id == UNUSED){
		return;
	}
	if(time.minuteOfDay != scheduleLightEvent.minuteOfDay){
		return;
	}

	LightController_On(scheduleLightEvent.id);

}
void LightScheduler_SchedulerTurnOn(int id,Day day,int minuteOfDay)
{
	scheduleLightEvent.id = id;
	scheduleLightEvent.minuteOfDay = minuteOfDay ;

}