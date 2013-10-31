#include "LedDriver.h"
#include "../../include/util/RunTimeError.h"

static uint16_t *ledsAddress;
static uint16_t ledsImage;

static uint16_t convertLedNumberToBit(int ledNumber);
static void updateHardWare(void);

enum {ALL_LEDS_ON = ~0,ALL_LEDS_OFF = ~ALL_LEDS_ON};


void LedDriver_Create(uint16_t *address)
{
	ledsAddress = address;
	ledsImage = ALL_LEDS_OFF;
	*ledsAddress = ledsImage;
}

void LedDriver_Destroy(void)
{
}


void LedDriver_TurnOn(int ledNumber)
{
	if(ledNumber <= 0 || ledNumber > 16)
	{
		RUNTIME_ERROR("LED Driver: out-of-bounds LED", -1);
		return;
	}
	ledsImage |= convertLedNumberToBit(ledNumber);
	updateHardWare();
}


void LedDriver_TurnOff(int ledNumber)
{
	if(ledNumber <= 0 || ledNumber > 16)
		return;
	ledsImage &= ~(convertLedNumberToBit(ledNumber));
	updateHardWare();
}
void LedDriver_TurnAllOn(void)
{
	ledsImage= ALL_LEDS_ON;
	updateHardWare();
}

static uint16_t convertLedNumberToBit(int ledNumber){
	return (uint16_t)(1<<(ledNumber -1) );
}

static void updateHardWare(void)
{
	*ledsAddress = ledsImage;
}