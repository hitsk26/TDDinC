#include "CppUTest/TestHarness.h"

extern "C" {
#include "FakeTimeService.h"
#include "LightControllerSpy.h"
#include "LightScheduler.h"
#include "TimeService.h"
}


TEST_GROUP(LightScheduler) {
	void setup() {
		LightScheduler_Create();
		LightController_Create();

	}
	void teardown() {
		LightScheduler_Destroy();
		LightController_Destroy();

	}
	void setTimeTo(int day,int minuteOfDay){

		FakeTimeService_SetDay(day);
		FakeTimeService_SetMinute(minuteOfDay);

	}

	void checkLightState(int id,int level)
	{
		if(id == LIGHT_ID_UNKNOWN){
			LONGS_EQUAL(id,LightControllerSpy_GetLastId());
			LONGS_EQUAL(level,LightControllerSpy_GetLastState());
		}
		else {
			LONGS_EQUAL(level,LightControllerSpy_GetLightState(id));
		}
	}
};


TEST(LightScheduler,NoSchedlueNothingHappnes)
{
	setTimeTo(MONDAY,100);
	LightScheduler_Wakeup();
	checkLightState(LIGHT_ID_UNKNOWN,LIGHT_STATE_UNKNOWN);
}

TEST(LightScheduler,ScheduleOnEveryDayNotTimeYet)
{
	LightScheduler_ScheduleTurnOn(3,MONDAY,1200);
	setTimeTo(MONDAY,1199);
	LightScheduler_Wakeup();

	checkLightState(LIGHT_ID_UNKNOWN,LIGHT_STATE_UNKNOWN);

}

TEST(LightScheduler,ScheduleOnEverydayItsTime)
{
	LightScheduler_ScheduleTurnOn(3,EVERYDAY,1200);
	setTimeTo(MONDAY,1200);
	LightScheduler_Wakeup();

	checkLightState(3,LIGHT_ON);

}

TEST(LightScheduler,ScheduleOffEverydayItsTime)
{
	LightScheduler_ScheduleTurnOff(3,EVERYDAY,1200);
	setTimeTo(MONDAY,1200);
	LightScheduler_Wakeup();

	checkLightState(3,LIGHT_OFF);
}

TEST(LightScheduler,ScheduleTuesdayButItsMonday)
{
	LightScheduler_ScheduleTurnOn(3,TUESDAY,1200);
	setTimeTo(MONDAY,1200);
	LightScheduler_Wakeup();

	checkLightState(LIGHT_ID_UNKNOWN,LIGHT_STATE_UNKNOWN);

}

TEST(LightScheduler,ScheduleTuesdayAndtItsday)
{
	LightScheduler_ScheduleTurnOn(3,TUESDAY,1200);
	setTimeTo(TUESDAY,1200);
	LightScheduler_Wakeup();

	checkLightState(3,LIGHT_ON);

}

TEST(LightScheduler,ScheduleWeekEndItsFriday)
{
	LightScheduler_ScheduleTurnOn(3,WEEKEND,1200);
	setTimeTo(FRIDAY,1200);
	LightScheduler_Wakeup();
	checkLightState(LIGHT_ID_UNKNOWN,LIGHT_STATE_UNKNOWN);

}

TEST(LightScheduler,ScheduleWeekEndItsSaturday)
{
	LightScheduler_ScheduleTurnOn(3,WEEKEND,1200);
	setTimeTo(SATURDAY,1200);
	LightScheduler_Wakeup();
	checkLightState(3,LIGHT_ON);

}

TEST(LightScheduler,ScheduleWeekEndItsSunday)
{
	LightScheduler_ScheduleTurnOn(3,WEEKEND,1200);
	setTimeTo(SUNDAY,1200);
	LightScheduler_Wakeup();
	checkLightState(3,LIGHT_ON);
}
TEST(LightScheduler,ScheduleWeekEndItsMonday)
{
	LightScheduler_ScheduleTurnOn(3,WEEKEND,1200);
	setTimeTo(MONDAY,1200);
	LightScheduler_Wakeup();
	checkLightState(LIGHT_ID_UNKNOWN,LIGHT_STATE_UNKNOWN);
}


TEST(LightScheduler,ScheduleTwoEventsAtTheSameTime)
{
	LightScheduler_ScheduleTurnOn(3,SUNDAY,1200);
	LightScheduler_ScheduleTurnOn(12,SUNDAY,1200);

	setTimeTo(SUNDAY,1200);

	LightScheduler_Wakeup();

	checkLightState(3,LIGHT_ON);
	checkLightState(12,LIGHT_ON);
}


TEST_GROUP(LightSchedulerInitAndCleanUp)
{
};

TEST(LightSchedulerInitAndCleanUp,CreateStartsOneMinuteAlarm)
{
	LightScheduler_Create();
	POINTERS_EQUAL((void *)LightScheduler_Wakeup,
			(void*)FakeTimeService_GetAlarmCallback());

	LONGS_EQUAL(60,FakeTimeService_GetAlarmPeriod());
	LightScheduler_Destroy();
}

TEST(LightSchedulerInitAndCleanUp,DestoryCancelsOneMnuteAlarm)
{
	LightScheduler_Create();
	LightScheduler_Destroy();
	POINTERS_EQUAL(NULL,(void*)FakeTimeService_GetAlarmCallback());

}


