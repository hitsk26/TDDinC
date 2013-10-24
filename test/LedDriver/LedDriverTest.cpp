#include "CppUTest/TestHarness.h"

extern "C"{
#include "../LedDriver/LedDriver.h"
#include <stdio.h>
#include <memory.h>

}


TEST_GROUP(LEDDriver)
{
	uint16_t virtualLeds;

	void setup(){
		LedDriver_Create(&virtualLeds);
	}
	void teardown(){

	}
};

TEST(LEDDriver,LedsOffAfterCreate)
{
	virtualLeds = 0xffff;
	LedDriver_Create(&virtualLeds);
	LONGS_EQUAL(0, virtualLeds);
}

TEST(LEDDriver, TurnOnLedOne)
{
	LedDriver_TurnOn(1);
	LONGS_EQUAL(1,virtualLeds);

}

TEST(LEDDriver, TurnOffLedOne)
{
	LedDriver_TurnOn(1);
	LedDriver_TurnOff(1);
	LONGS_EQUAL(0, virtualLeds);
}