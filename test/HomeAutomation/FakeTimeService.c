#include "FakeTimeService.h"


Time time_;


static WakeupCallback callback;
static int period;

void TimeService_Create(void)
{
	time_.minuteOfDay = TIME_UNKNOWN;
	time_.dayOfWeek = TIME_UNKNOWN;
}

void TimeService_Destroy(void)
{

}
void TimeService_SetPeriodicAlarmInSeconds(int seconds,WakeupCallback cb)
{
	callback = cb;
	period = seconds;
}
WakeupCallback FakeTimeService_GetAlarmCallback(void)
{
    return callback;
}
void TimeService_CancelPeriodicAlarmInSeconds(int seconds,WakeupCallback cb)
{
	if(cb == callback && period == seconds)
	{
		callback = NULL;
		period = 0;
	}

}

int FakeTimeService_GetAlarmPeriod(void){

	return period;
}


void TimeService_GetTime(Time *time){

	time->dayOfWeek = time_.dayOfWeek;
	time->minuteOfDay =time_.minuteOfDay;
}

void FakeTimeService_SetMinute(int minuteOfDay)
{
	time_.minuteOfDay = minuteOfDay;

}
void FakeTimeService_SetDay(int day)
{
	time_.dayOfWeek = day;
}

