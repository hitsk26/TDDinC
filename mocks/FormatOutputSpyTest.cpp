#include "CppUTest/TestHarness.h"

extern "C"{

#include "FormatOutputSpy.h"

}

TEST_GROUP(FormatOutputSpy)
{
	void setup(){
		UT_PTR_SET(FormatOutput, FormatOutputSpy);
	}
	void teardown(){
		FormatOutputSpy_Destroy();
	}
};

TEST(FormatOutputSpy,HelloWorld)
{
	FormatOutputSpy_Create(20);
	FormatOutput("Hello,World\n");
	STRCMP_EQUAL("Hello,World\n",FormatOutputSpy_GetOutput());

}
TEST(FormatOutputSpy,PrintMultipleTimes)
{
	FormatOutputSpy_Create(25);
	FormatOutput("Hello,");
	FormatOutput("World\n");
	STRCMP_EQUAL("Hello,World\n",FormatOutputSpy_GetOutput());

}
/*
TEST(FormatOutputSpy,PrintMultipleOutputsFull)
{
	FormatOutputSpy_Create(12);
	FormatOutput("12345");
	FormatOutput("67890");
	FormatOutput("ABCDEF");
	STRCMP_EQUAL("1234567890ABC",FormatOutputSpy_GetOutput());
}*/

