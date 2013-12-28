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
}ScheduledLightEvent;

enum {
	TURN_OFF = 0,
	TURN_ON  = 1
};
enum {
	MAX_EVENTS = 128
};

static void scheduleEvent(int id, Day day,int minuteOfDay,int event);
static void processEventDueNow(Time *time,ScheduledLightEvent *lightEvent);
static void operateLight(ScheduledLightEvent* lightEvent);

static ScheduledLightEvent scheduledEvents[MAX_EVENTS];

void LightScheduler_Create(void)
{
	int i=0;
	for(i = 0;i< MAX_EVENTS;i++){
		scheduledEvents[i].id = UNUSED;
	}
	TimeService_SetPeriodicAlarmInSeconds(60,LightScheduler_Wakeup);

}

void LightScheduler_Destroy(void)
{
	TimeService_CancelPeriodicAlarmInSeconds(60,LightScheduler_Wakeup);
}

void LightScheduler_Wakeup(void)
{
	int i=0;
	Time time;
	TimeService_GetTime(&time);

	for(i=0;i< MAX_EVENTS;i++){
		processEventDueNow(&time,&scheduledEvents[i]);
	}
}

static void operateLight(ScheduledLightEvent* lightEvent) {

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

static void processEventDueNow(Time *time,ScheduledLightEvent *lightEvent)
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

	operateLight(lightEvent);

}


void LightScheduler_ScheduleTurnOn(int id,Day day,int minuteOfDay)
{
	scheduleEvent(id,day,minuteOfDay,TURN_ON);
}

void LightScheduler_ScheduleTurnOff(int id,Day day,int minuteOfDay)
{
	scheduleEvent(id,day,minuteOfDay,TURN_OFF);
}

static void scheduleEvent(int id, Day day,int minuteOfDay,int event)
{
	int i=0;

	for(i=0;i < MAX_EVENTS;i++){
		if(scheduledEvents[i].id == UNUSED){
			scheduledEvents[i].day = day;
			scheduledEvents[i].event = event;
			scheduledEvents[i].minuteOfDay = minuteOfDay;
			scheduledEvents[i].id = id;
			break;
		}
	}
}
void LightScheduler_Randomize(int id,Day day,int minuteOfDay)
{


}

