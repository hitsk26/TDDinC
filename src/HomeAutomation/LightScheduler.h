#ifndef LIGHTSCHEDULER_H_
#define LIGHTSCHEDULER_H_

typedef enum
{
	NONE= -1,EVERYDAY=10,WEEKDAY,WEEKEND,
	SUNDAY=1,MONDAY,TUESDAY,WEDNESSDAY,THURSDAY,FRIDAY,SATURDAY
}Day;


void LightScheduler_Create(void);
void LightScheduler_Destroy(void);
void LightScheduler_Wakeup(void);
void LightScheduler_SchedulerTurnOn(int id,Day day,int minuteOfDay);
void LightScheduler_SchedulerTurnOff(int id,Day day,int minuteOfDay);

enum{
	UNUSED
};


#endif /* LIGHTSCHEDULER_H_ */
