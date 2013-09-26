#include "CppUTest\TestHarness.h"

extern "C" {
#include "../../src/osek/lib/mymath.h"

}

TEST_GROUP(mymath) {
	void setup() {
			}
	void teardown() {
		}
};


TEST(mymath, sin) {
	LONGS_EQUAL(0,mysin(0));
	DOUBLES_EQUAL(1,mysin(PI/2),1);
	DOUBLES_EQUAL(-1,mysin(-PI/2),1);
}



