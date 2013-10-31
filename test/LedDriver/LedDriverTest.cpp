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
TEST(LEDDriver,TurnOnMultipleLeds)
{
	LedDriver_TurnOn(9);
	LedDriver_TurnOn(8);
	LONGS_EQUAL(0x180,virtualLeds);
}

TEST(LEDDriver,TurnAllOn)
{
	LedDriver_TurnAllOn();
	LONGS_EQUAL(0xffff,virtualLeds);
}
TEST(LEDDriver,TurnOffAnyLed)
{
	LedDriver_TurnAllOn();
	LedDriver_TurnOff(8);
	LONGS_EQUAL(0xff7f,virtualLeds);
}