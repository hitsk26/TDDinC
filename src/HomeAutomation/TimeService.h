#ifndef TIMESERVICE_H_
#define TIMESERVICE_H_

typedef struct {
	int minuteOfDay;
	int dayOfWeek;
}Time;

enum {
	TIME_UNKNOWN = -1
};


typedef void (*WakeupCallback)(void);


void TimeService_Create(void);

void TimeService_Destroy(void);

void TimeService_GetTime(Time *time);

void TimeService_SetPeriodicAlarmInSeconds(int seconds,WakeupCallback cb);
void TimeService_CancelPeriodicAlarmInSeconds(int seconds,WakeupCallback cb);


#endif /* TIMESERVICE_H_ */
