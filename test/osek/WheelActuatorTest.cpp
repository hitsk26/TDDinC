#include "CppUTest\TestHarness.h"

extern "C" {
#include "../../src/osek/DrivenPart/WheelActuator.h"
#include "../../src/osek/Factory.h"

}

TEST_GROUP(WheelActuator) {
	void setup() {
		WheelActuator_init(&wheelActuator);	
		wheelActuator.forward = 50;
	}
	void teardown() {
		}
};


TEST(WheelActuator, initialize) {
	//WheelActuator wheelActuator;
	LONGS_EQUAL(50, wheelActuator.forward);
}

TEST(WheelActuator, tail_running) {
	//WheelActuator wheelActuator;

	int pwm_l,pwm_r;
	WheelActuator_tail_running(&wheelActuator,&pwm_l,&pwm_r);
	LONGS_EQUAL(50, pwm_l);
}

