#include "TimeService.h"
#include "LightScheduler.h"
#include "LightController.h"
#include <stdbool.h>

typedef struct
{
	int id;
	int minuteOfDay;
	int event;
	int day;
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
	TimeService_SetPeriodicAlarmInSeconds(60,LightScheduler_Wakeup);

}

void LightScheduler_Destroy(void)
{
	TimeService_CancelPeriodicAlarmInSeconds(60,LightScheduler_Wakeup);
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

static bool DoesLightRespondToday(Time *time,int reactionDay)
{
	int today = time->dayOfWeek;

	if(reactionDay == EVERYDAY){
		return true;
	}
	if(reactionDay == today){
		return true;
	}
	if(reactionDay == WEEKEND && (SATURDAY == today || SUNDAY == today)){
		return true;
	}
	if(reactionDay == WEEKDAY && today >= MONDAY && today <= FRIDAY){
		return true;
	}
	return false;
}

static void processEventDueNow(Time *time,ScheduleLightEvent *lightEvent)
{

	if(lightEvent->id == UNUSED){
			return;
	}
	if(lightEvent->minuteOfDay != time->minuteOfDay){
			return;
	}
	if(!DoesLightRespondToday(time,lightEvent->day)){
		return;
	}

	operateLight(&scheduledEvent);

}


void LightScheduler_SchedulerTurnOn(int id,Day day,int minuteOfDay)
{
	scheduleEvent(id,day,minuteOfDay,TURN_ON);
}

void LightScheduler_SchedulerTurnOff(int id,Day day,int minuteOfDay)
{
	scheduleEvent(id,day,minuteOfDay,TURN_OFF);
}

static void scheduleEvent(int id, Day day,int minuteOfDay,int event)
{
	scheduledEvent.id = id;
	scheduledEvent.event = event;
	scheduledEvent.minuteOfDay = minuteOfDay;
	scheduledEvent.day = day;

}
