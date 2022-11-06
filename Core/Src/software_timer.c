/*
 * software_timer.c
 *
 *  Created on: Nov 5, 2022
 *      Author: lamkh
 */

#include "software_timer.h"

int timerBlinky_counter = 0;
int timerBlinky_flag =  0;

int counterMain = 0;
int counterMain_flag =  0;

void setTimerBlinky(int duration) {
	timerBlinky_counter = duration;
	timerBlinky_flag = 0;
}
void setCounterMain(int duration) {
	counterMain = duration;
	counterMain_flag = 0;
}

void timerRun(){
	if(timerBlinky_counter > 0){
		timerBlinky_counter--;
		if(timerBlinky_counter <= 0){
			timerBlinky_flag = 1;
		}
	}
	if (counterMain > 0) {
		counterMain--;
		if(counterMain == 0) counterMain_flag = 1;
	}
}
