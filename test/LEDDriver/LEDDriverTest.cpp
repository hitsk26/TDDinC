#include "CppUTest/TestHarness.h"

extern "C"{
#include "../LedDriver/LedDriver.h"
#include <stdio.h>
#include <memory.h>

}


TEST_GROUP(LEDDriver)
{
	//uint16_t virtualLeds;

	void setUp(){

	}
	void tearDown(){

	}
};

TEST(LEDDriver,LedsOffAfterCreate)
{
	uint16_t virtualLeds = 0xffff;
	LedDriver_Create(&virtualLeds);
	LONGS_EQUAL(0, virtualLeds);
}

TEST(LEDDriver, TurnOnLedOne)
{
	uint16_t virtualLeds;
	LedDriver_Create(&virtualLeds);
	LedDriver_TurnOn(1);
	LONGS_EQUAL(1,virtualLeds);

}