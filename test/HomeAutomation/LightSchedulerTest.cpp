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
		LONGS_EQUAL(id,LightControllerSpy_GetLastId());
		LONGS_EQUAL(level,LightControllerSpy_GetLastState());

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
	LightScheduler_SchedulerTurnOn(3,MONDAY,1200);
	setTimeTo(MONDAY,1199);
	LightScheduler_Wakeup();

	checkLightState(LIGHT_ID_UNKNOWN,LIGHT_STATE_UNKNOWN);

}

TEST(LightScheduler,ScheduleOnEverydayItsTime)
{
	LightScheduler_SchedulerTurnOn(3,EVERYDAY,1200);
	setTimeTo(MONDAY,1200);
	LightScheduler_Wakeup();

	checkLightState(3,LIGHT_ON);

}

TEST(LightScheduler,ScheduleOffEverydayItsTime)
{
	LightScheduler_SchedulerTurnOff(3,EVERYDAY,1200);
	setTimeTo(MONDAY,1200);
	LightScheduler_Wakeup();

	checkLightState(3,LIGHT_OFF);
}

TEST(LightScheduler,ScheduleTuesdayButItsMonday)
{
	LightScheduler_SchedulerTurnOn(3,TUESDAY,1200);
	setTimeTo(MONDAY,1200);
	LightScheduler_Wakeup();

	checkLightState(LIGHT_ID_UNKNOWN,LIGHT_STATE_UNKNOWN);

}

TEST(LightScheduler,ScheduleTuesdayAndtItsday)
{
	LightScheduler_SchedulerTurnOn(3,TUESDAY,1200);
	setTimeTo(TUESDAY,1200);
	LightScheduler_Wakeup();

	checkLightState(3,LIGHT_ON);

}

TEST(LightScheduler,ScheduleWeekEndItsFriday)
{
	LightScheduler_SchedulerTurnOn(3,WEEKEND,1200);
	setTimeTo(FRIDAY,1200);
	LightScheduler_Wakeup();
	checkLightState(LIGHT_ID_UNKNOWN,LIGHT_STATE_UNKNOWN);

}

TEST(LightScheduler,ScheduleWeekEndItsSaturday)
{
	LightScheduler_SchedulerTurnOn(3,WEEKEND,1200);
	setTimeTo(SATURDAY,1200);
	LightScheduler_Wakeup();
	checkLightState(3,LIGHT_ON);

}

TEST(LightScheduler,ScheduleWeekEndItsSunday)
{
	LightScheduler_SchedulerTurnOn(3,WEEKEND,1200);
	setTimeTo(SUNDAY,1200);
	LightScheduler_Wakeup();
	checkLightState(3,LIGHT_ON);
}
TEST(LightScheduler,ScheduleWeekEndItsMonday)
{
	LightScheduler_SchedulerTurnOn(3,WEEKEND,1200);
	setTimeTo(MONDAY,1200);
	LightScheduler_Wakeup();
	checkLightState(LIGHT_ID_UNKNOWN,LIGHT_STATE_UNKNOWN);
}

/*
TEST(LightScheduler,NoChnageToLightsDuringInitialization)
{
	LONGS_EQUAL(LIGHT_ID_UNKNOWN,LightControllerSpy_GetLastId());
	LONGS_EQUAL(LIGHT_STATE_UNKNOWN,LightControllerSpy_GetLastState());

}*/

