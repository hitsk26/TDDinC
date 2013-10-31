#include "LedDriver.h"

static uint16_t *ledsAddress;
static uint16_t convertLedNumberToBit(int ledNumber);

enum {ALL_LEDS_ON = ~0,ALL_LEDS_OFF = ~ALL_LEDS_ON};


void LedDriver_Create(uint16_t *address)
{
	ledsAddress = address;
	*address = (uint16_t)ALL_LEDS_OFF;

}

void LedDriver_Destroy(void)
{
}


void LedDriver_TurnOn(int ledNumber)
{
	*ledsAddress |= convertLedNumberToBit(ledNumber);
}


void LedDriver_TurnOff(int ledNumbers){
	*ledsAddress &= (uint16_t)~(convertLedNumberToBit(ledNumbers));

}


void LedDriver_TurnAllOn(void)
{
	*ledsAddress = (uint16_t)ALL_LEDS_ON;
}

static uint16_t convertLedNumberToBit(int ledNumber){
	return (uint16_t)(1<<(ledNumber -1) );
}