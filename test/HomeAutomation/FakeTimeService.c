#include "FakeTimeService.h"


Time time_;

	int minuteOfDay;
	int dayOfWeek;

void TimeService_Create(void)
{
	time_.minuteOfDay = TIME_UNKNOWN;
	time_.dayOfWeek = TIME_UNKNOWN;
}

void TimeService_Destroy(void)
{

}


int TimeService_GetTime(Time *time){
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
