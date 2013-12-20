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
static void scheduleEvent(int id, Day day,int minuteOfDay,int event);
static void processEventDueNow(Time *time,ScheduleLightEvent *lightEvent);
static void operateLight(ScheduleLightEvent* lightEvent);

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

	processEventDueNow(&time,&scheduledEvent);

}

static void operateLight(ScheduleLightEvent* lightEvent) {

	if (lightEvent->event == TURN_ON) {
		LightController_On(lightEvent->id);
	} else if (lightEvent->event == TURN_OFF) {
		LightController_Off(lightEvent->id);
	}
}

static void processEventDueNow(Time *time,ScheduleLightEvent *lightEvent)
{
	if(lightEvent->id == UNUSED){
			return;
		}
	if(lightEvent->minuteOfDay != time->minuteOfDay){
			return;
	}

	operateLight(&scheduledEvent);

}


void LightScheduler_SchedulerTurnOn(int id,Day day,int minuteOfDay)
{
	scheduleEvent(id,day,minuteOfDay,TURN_ON);
}

static void scheduleEvent(int id, Day day,int minuteOfDay,int event)
{
	scheduledEvent.id = id;
	scheduledEvent.event = event;
	scheduledEvent.minuteOfDay = minuteOfDay;

}

void LightScheduler_SchedulerTurnOff(int id,Day day,int minuteOfDay)
{
	scheduleEvent(id,day,minuteOfDay,TURN_OFF);
}

