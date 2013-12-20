#ifndef TIMESERVICE_H_
#define TIMESERVICE_H_

typedef struct {
	int minuteOfDay;
	int dayOfWeek;
}Time;

enum {
	TIME_UNKNOWN = -1
};



void TimeService_Create(void);

void TimeService_Destroy(void);

int TimeService_GetTime(Time *time);

#endif /* TIMESERVICE_H_ */
