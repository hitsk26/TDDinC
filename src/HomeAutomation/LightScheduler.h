#ifndef LIGHTSCHEDULER_H_
#define LIGHTSCHEDULER_H_

void LightScheduler_Create(void);
void LightScheduler_Destroy(void);
void LightScheduler_Wakeup(void);
void LightScheduler_SchedulerTurnOn(int id,Day day,int minuteOfDay);

enum{
	UNUSED
};

#endif /* LIGHTSCHEDULER_H_ */
