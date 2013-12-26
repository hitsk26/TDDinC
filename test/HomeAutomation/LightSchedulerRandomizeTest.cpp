#include "CppUTest/TestHarness.h"

extern "C"{
#include "../../src/HomeAutomation/RandomMinute.h"
#include "FakeRadomMinute.h"
#include "../../src/HomeAutomation/LightController.h"
#include "../../src/HomeAutomation/LightScheduler.h"
#include "FakeTimeService.h"
#include "LightControllerSpy.h"
}
//TODO　LightControllerSpy_GetLightState(int id)を実装する必要あり


TEST_GROUP(LightSchedulerRandomize)
{
	int (*savedRandomMinute_Get)();

	void setup(){
		LightController_Create();
		LightScheduler_Create();
		savedRandomMinute_Get = RandomMinute_Get;
		RandomMinute_Get = FakeRandomMinute_Get;

	}

	void teardown(){
		LightScheduler_Destroy();
		LightController_Destroy();
		RandomMinute_Get = savedRandomMinute_Get;
	}
	void setTimeTo(int day,int minute){
		FakeTimeService_SetDay(day);
		FakeTimeService_SetMinute(minute);
	}
	void checkLightState(int id,int level){
		if(id == LIGHT_ID_UNKNOWN){
			LONGS_EQUAL(id,LightControllerSpy_GetLastId());
			LONGS_EQUAL(level,LightControllerSpy_GetLastState());
		}
		else {
			/*LONGS_EQUAL(level,LightControllerSpy_GetLightState(id);*/
		}
	}

};


TEST(LightSchedulerRandomize, TurnOnEarly)
{
  FakeRandom_Minute_SetFirstAndIncrement(-10 , 5);
  LightScheduler_SchedulerTurnOn(4, EVERYDAY, 600);
  LightScheduler_Randomize(4, EVERYDAY, 600);  //600 – 10になるはず
  setTimeTo(MONDAY, 600-10);
  LightScheduler_Wakeup();
  checkLightState(4, LIGHT_ON);
}
