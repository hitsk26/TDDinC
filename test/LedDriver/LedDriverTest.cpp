#include "CppUTest/TestHarness.h"

extern "C"{
#include "../LedDriver/LedDriver.h"
#include <stdio.h>
#include <memory.h>
#include "../../include/util/RunTimeError.h"
#include "../../mocks/RuntimeErrorStub.h"

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

TEST(LEDDriver,LedMemoryIsNotReadable)
{
	virtualLeds = 0xffff;
	LedDriver_TurnOn(8);
	LONGS_EQUAL(0x80,virtualLeds);
}

TEST(LEDDriver, UpperAndLowerBounds)
{
	LedDriver_TurnOn(1);
	LedDriver_TurnOn(16);
	LONGS_EQUAL(0x8001, virtualLeds);
}

TEST(LEDDriver, OutOfBoundsTurnOnDoesNoHarm)
{
	LedDriver_TurnOn(-1);
	LedDriver_TurnOn(0);
	LedDriver_TurnOn(17);
	LedDriver_TurnOn(3141);
	LONGS_EQUAL(0, virtualLeds);
}

TEST(LEDDriver, OutOfBoundsTurnOffDoesNoHarm)
{
	LedDriver_TurnAllOn();
	LedDriver_TurnOff(-1);
	LedDriver_TurnOff(0);
	LedDriver_TurnOff(17);
	LedDriver_TurnOff(3141);
	LONGS_EQUAL(0xffff, virtualLeds);
}
TEST(LEDDriver, OutOfBoundsProduesRuntimeError)
{
	LedDriver_TurnOn(-1);
	STRCMP_EQUAL("LED Driver: out-of-bounds LED",
		RuntimeErrorStub_GetLastError());
	LONGS_EQUAL(-1, RuntimeErrorStub_GetLastParameter());
}

IGNORE_TEST(LEDDriver,OutOfBoundsToDo)
{
	/*TODO something*/

}

TEST(LEDDriver, IsON)
{
	CHECK_FALSE(LedDriver_IsOn(11));
	LedDriver_TurnOn(11);
	CHECK_TRUE(LedDriver_IsOn(11));
}

TEST(LEDDriver, OutOfBoundsLedsAreAlwaysOff)
{
	CHECK_TRUE(LedDriver_IsOff(0));
	CHECK_TRUE(LedDriver_IsOff(17));
	CHECK_FALSE(LedDriver_IsOn(0));
	CHECK_FALSE(LedDriver_IsOn(17));
}

TEST(LEDDriver,IsOff)
{
	CHECK_TRUE(LedDriver_IsOff(12));
	LedDriver_TurnOn(12);
	CHECK_FALSE(LedDriver_IsOff(12));
}

TEST(LEDDriver, TurnOffMultipleLeds)
{
	LedDriver_TurnAllOn();
	LedDriver_TurnOff(9);
	LedDriver_TurnOff(8);
	LONGS_EQUAL((~0x0180)&0xffff, virtualLeds);
	/*LONGS_EQUAL(~0x0180, virtualLeds);*/
	LONGS_EQUAL((uint16_t)~(0x0180), virtualLeds);
}

TEST(LEDDriver, AllOff)
{
	LedDriver_TurnAllOn();
	LedDriver_TurnAllOff();
	LONGS_EQUAL(0, virtualLeds);
}

