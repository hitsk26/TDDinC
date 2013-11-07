#include "LedDriver.h"
#include "../../include/util/RunTimeError.h"

static uint16_t *ledsAddress;
static uint16_t ledsImage;

static uint16_t convertLedNumberToBit(int ledNumber);
static void updateHardWare(void);
static int IsLedOutOfBounds(int ledNumber);
static void setLedImageBit(int ledNumber);
static void clearLedImageBit(int ledNumber);


enum {ALL_LEDS_ON = ~0,ALL_LEDS_OFF = ~ALL_LEDS_ON};
enum {FIRST_LED = 1,LAST_LED = 16};


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
	if(IsLedOutOfBounds(ledNumber))
	{
		RUNTIME_ERROR("LED Driver: out-of-bounds LED", -1);
		return;
	}
	setLedImageBit(ledNumber);
	updateHardWare();
}


void LedDriver_TurnOff(int ledNumber)
{
	if(IsLedOutOfBounds(ledNumber))
		return;
	clearLedImageBit(ledNumber);
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

static int IsLedOutOfBounds(int ledNumber)
{
	return (ledNumber < FIRST_LED) || (ledNumber > LAST_LED);
}

static void setLedImageBit(int ledNumber)
{
	ledsImage |= convertLedNumberToBit(ledNumber);
}

static void clearLedImageBit(int ledNumber)
{
	ledsImage &= ~(convertLedNumberToBit(ledNumber)); 
}