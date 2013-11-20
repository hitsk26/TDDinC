#include "CppUTest/TestHarness.h"

extern "C" {
#include "../../src/osek/DrivenPart/WheelActuator.h"
#include "../../src/osek/Factory.h"

}

TEST_GROUP(WheelActuator) {
	void setup() {
		WheelActuator_init(&wheelActuator);
		wheelActuator.forward = 0;
	}
	void teardown() {
		}
};


TEST(WheelActuator, initialize) {
	LONGS_EQUAL(0, wheelActuator.forward);
}

