#include "CppUTest/TestHarness.h"

extern "C"{
#include "../LedDriver/LedDriver.h"

}


TEST_GROUP(LedDriver){
	void setup(){


	}
	void teardown(){


	}

};
TEST(LedDriver,LedsOffafterCreate){
	uint16_t virtualLeds = 0xffff;
	LedDriver_Create(&virtualLeds);
	LONGS_EQUAL(0,virtualLeds);

}
