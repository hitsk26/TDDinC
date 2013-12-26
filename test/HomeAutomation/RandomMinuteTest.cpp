#include "CppUTest/TestHarness.h"

extern "C"{

#include "../../src/HomeAutomation/RandomMinute.h"
#include <stdio.h>
}
enum{ BOUND = 30};

TEST_GROUP(RandomMinute)
{
	int minute;

	void setup()
	{
		RandomMinute_Create(BOUND);
		srand(1);
	}
	void teardown(){

	}
	void AssertMinuteIsInRange()
	{
		if(minute < -BOUND || minute > BOUND){
			printf("bandminute value:%d\n",minute);
			FAIL("Minute out of range");
		}
	}

};


TEST(RandomMinute,GetIsInRange)
{
	for(int i=0; i <100;i++){
		minute = RandomMinute_Get();
		AssertMinuteIsInRange();
	}
}
