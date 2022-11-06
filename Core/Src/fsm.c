/*
 * fsm.c
 *
 *  Created on: Nov 6, 2022
 *      Author: lamkh
 */

#include "fsm.h"

void fsm_simple_buttons_run(){
	switch(status){
		case 0: //Initialize
			if(counterMain_flag == 1){
				setCounterMain(100);
				status = 4;
			}
			break;
		case 1: //Reset
			n = 0;
			display7(n);
			status = 4;
			break;
		case 2: //Increase
			n++;
			if(n > 9) n = 0;
			display7(n);
				status = 4;
			break;
		case 3: //Decrease
			n--;
			if(n < 0) n = 9;
			display7(n);
				status = 4;
			break;
		case 4: //Countdown
			if(counterMain_flag == 1){
				n--;
				if(n < 0) n = 0;
				setCounterMain(100);
			}
			display7(n);
			if(isButtonResetPressed() == 1) status = 1;
			else if(isButtonIncPressed() == 1){
				setCounterMain(100);
				status = 2;
			} else if(isButtonDecPressed() == 1){
				setCounterMain(100);
				status = 3;
			}
			break;
		default:
			break;
	}
}
