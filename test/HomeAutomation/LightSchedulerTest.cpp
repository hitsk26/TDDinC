#include "CppUTest/TestHarness.h"

extern "C" {
#include "FakeTimeService.h"
#include "LightControllerSpy.h"
#include "LightScheduler.h"
#include "TimeService.h"
}

TEST_GROUP(LightScheduler) {
	void setup() {
		/*LightScheduler_Create();
		LightController_Create();
		*/
	}
	void teardown() {
		/*LightScheduler_Destroy();
		LightController_Destroy();
		*/
	}
};

/*
TEST(LightScheduler,ScheduleOnEveryDayNotTimeYet)
{
	LightScheduler_SchedulerTurnOn(3,MONDAY,1200);
	FakeTimeService_SetDay(MONDAY);
	FakeTimeService_SetMinute(1199);
	LightScheduler_Wakeup();

	LONGS_EQUAL(LIGHT_ID_UNKNOWN,LightControllerSpy_GetLastId());
	LONGS_EQUAL(LIGHT_STATE_UNKNOWN,LightControllerSpy_GetLastState());

}*/

/*
TEST(LightScheduler,NoChnageToLightsDuringInitialization)
{
	LONGS_EQUAL(LIGHT_ID_UNKNOWN,LightControllerSpy_GetLastId());
	LONGS_EQUAL(LIGHT_STATE_UNKNOWN,LightControllerSpy_GetLastState());

}*/

