#ifndef FAKETIMESERVICE_H_
#define FAKETIMESERVICE_H_

#include "TimeService.h"


void FakeTimeService_SetMinute(int minute);
void FakeTimeService_SetDay(int day);

WakeupCallback FakeTimeService_GetAlarmCallback(void);
int FakeTimeService_GetAlarmPeriod(void);


#endif /* FAKETIMESERVICE_H_ */
