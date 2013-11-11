#include <stdint.h>

void LedDriver_Create(uint16_t *address);
void LedDriver_Destroy(void);

void LedDriver_TurnOn(int ledNumbers);
void LedDriver_TurnOff(int ledNumbers);
void LedDriver_TurnAllOn(void);
void LedDriver_TurnAllOff(void);
int  LedDriver_IsOn(int ledNumber);
int LedDriver_IsOff(int ledNumber);

