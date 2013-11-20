#include "./StrategyPart/Runner.h"

#include "Factory.h"

#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"

//カウンタの宣言
DeclareCounter(SysTimerCnt);

//タスクの宣言
DeclareTask(ActionTask);
DeclareTask(INITIALIZE);
DeclareTask(UI);

DeclareTask(DriveTask1);
DeclareTask(DriveTask2);


//初期処理
void ecrobot_device_initialize(void){
	ecrobot_init_bt_slave("LEJOS-OSEK");
	ecrobot_set_light_sensor_active(NXT_PORT_S3);
	ecrobot_init_sonar_sensor(NXT_PORT_S2);
	initialization();
}

//後始末処理
void ecrobot_device_terminate(void){

	ecrobot_set_light_sensor_inactive(NXT_PORT_S3);
	ecrobot_set_motor_speed(NXT_PORT_B, 0);
	ecrobot_set_motor_speed(NXT_PORT_C, 0);
	ecrobot_term_sonar_sensor(NXT_PORT_S2);
	ecrobot_term_bt_connection();

}


/*--------------------------------------------------------------------------*/
/* OSEK hooks                                                               */
/*--------------------------------------------------------------------------*/
void StartupHook(void){}
void ShutdownHook(StatusType ercd){}
void PreTaskHook(void){}
void PostTaskHook(void){}
void ErrorHook(StatusType ercd){}


/*--------------------------------------------------------------------------*/
/* Function to be invoked from a category 2 interrupt                       */
/*--------------------------------------------------------------------------*/
void user_1ms_isr_type2(void){
	StatusType ercd;
	/*
	 *  Increment OSEK Alarm System Timer Count
     */
	ercd = SignalCounter( SysTimerCnt );
	if( ercd != E_OK ){
		ShutdownOS( ercd );
	}
}


TASK(INITIALIZE){
	while(1){
		if(Calibration_calibration(&calibration) ==1){
			break;
		}
	}
	Runner_start_run(&runner);
	TerminateTask();
}

TASK(ActionTask){

	Runner_execute(&runner);
	TerminateTask();
}

TASK(DriveTask1){
	float curvature_turn = CC_run(&mCurvatureCtrl);
	TerminateTask();
}

TASK(DriveTask2){
	float brightness_turn = LVC_run(&mLightValCtrl);
	TerminateTask();
}
TASK(UI){

	Starter_user_command_accept(&starter);
	TerminateTask();
}
