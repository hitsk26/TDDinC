#include "FakeTimeService.h"



static int minute;
static int dayofweek;


void TimeService_Create(void)
{
	minute = TIME_UNKNOWN;
	dayofweek = TIME_UNKNOWN;
}

void TimeService_Destroy(void)
{


}


int TimeService_GetTime(Time *time){
	time->dayOfWeek = dayofweek;
	time->minuteOfDay = minute;
}

void FakeTimeService_SetMinute(int setting_minute)
{
	minute = setting_minute;

}
void FakeTimeService_SetDay(int setting_dayofweek)
{
	dayofweek = setting_dayofweek;
}
