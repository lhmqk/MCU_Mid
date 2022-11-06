/*
 * software_timer.h
 *
 *  Created on: Nov 5, 2022
 *      Author: lamkh
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timerBlinky_flag;
extern int counterMain_flag;

void setTimerBlinky(int duration);
void setCounterMain(int duration);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
