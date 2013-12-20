#include "TimeService.h"
#include "LightScheduler.h"
#include "LightController.h"

typedef struct
{
	int id;
	int minuteOfDay;
	int event;
}ScheduleLightEvent;

enum {
	TURN_OFF = 0,
	TURN_ON  = 1
};

static ScheduleLightEvent scheduledEvent;


void LightScheduler_Create(void)
{
	scheduledEvent.id = UNUSED;
}

void LightScheduler_Destroy(void)
{

}

void LightScheduler_Wakeup(void)
{
	Time time;
	TimeService_GetTime(&time);

	if(scheduledEvent.id == UNUSED){
		return;
	}
	if(time.minuteOfDay != scheduledEvent.minuteOfDay){
		return;
	}

	if(scheduledEvent.event == TURN_ON){
		LightController_On(scheduledEvent.id);
	}
	else if(scheduledEvent.event == TURN_OFF){
		LightController_Off(scheduledEvent.id);
	}


}
void LightScheduler_SchedulerTurnOn(int id,Day day,int minuteOfDay)
{
	scheduleEvent(id,day,minuteOfDay,TURN_ON);
}

void scheduleEvent(int id, Day day,int minuteOfDay,int event)
{
	scheduledEvent.id = id;
	scheduledEvent.event = event;
	scheduledEvent.minuteOfDay = minuteOfDay;

}

void LightScheduler_SchedulerTurnOff(int id,Day day,int minuteOfDay)
{
	scheduleEvent(id,day,minuteOfDay,TURN_OFF);
}

