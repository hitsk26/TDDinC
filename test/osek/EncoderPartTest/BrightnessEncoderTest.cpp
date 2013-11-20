#include "CppUTest\TestHarness.h"

extern "C" {
#include "../../src/osek/EncoderPart/BrightnessEncoder.h"

}

TEST_GROUP(Encoder) {
	void setup() {
			}
	void teardown() {
		}
};

TEST(Encoder, light) {
	BrightnessEncoder a;
	LowPassFillter    b;
	BrightnessEncoder_init(&a,0,&b);
	LONGS_EQUAL(0,a.black_value);
}
