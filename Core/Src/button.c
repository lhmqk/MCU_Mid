/*
 * button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: lamkh
 */

#include "button.h"

int buttonReset_flag = 0;
int buttonInc_flag = 0;
int buttonDec_flag = 0;

int KeyReg0 = NORMAL_STATE;	//Reset
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;

int KeyReg3 = NORMAL_STATE;	//Inc
int KeyReg4 = NORMAL_STATE;
int KeyReg5 = NORMAL_STATE;

int KeyReg6 = NORMAL_STATE;	//Dec
int KeyReg7 = NORMAL_STATE;
int KeyReg8 = NORMAL_STATE;

int KeyReg9 = NORMAL_STATE;	//Reset
int KeyReg10 = NORMAL_STATE;//Inc
int KeyReg11 = NORMAL_STATE;//Dec

int timerForKeyPressRes = 300;
int timerForKeyPressInc = 300;
int timerForKeyPressDec = 300;

int isButtonResetPressed(){
	if(buttonReset_flag == 1){
		buttonReset_flag = 0;
		return 1;
	}
	return 0;
}
int isButtonIncPressed(){
	if(buttonInc_flag == 1){
		buttonInc_flag = 0;
		return 1;
	}
	return 0;
}
int isButtonDecPressed(){
	if(buttonDec_flag == 1){
		buttonDec_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyProcessReset(){
	buttonReset_flag = 1;
//	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
}
void subKeyProcessInc(){
	buttonInc_flag = 1;
//	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
}
void subKeyProcessDec(){
	buttonDec_flag = 1;
//	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
}

void getKeyInputReset(){
	KeyReg0 = KeyReg1;
	KeyReg1 = KeyReg2;
	KeyReg2 = HAL_GPIO_ReadPin(ButtonReset_GPIO_Port, ButtonReset_Pin);
	if((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)){
		if(KeyReg9 != KeyReg2){
			KeyReg9 = KeyReg2;
			if(KeyReg2 == PRESSED_STATE){	//Nhan Tha
				//TODO
				subKeyProcessReset();
				timerForKeyPressRes = 300;
			}
		} else {							//Nhan Giu
			timerForKeyPressRes--;
			if(timerForKeyPressRes == 0){
				//TODO
				if(KeyReg2 == PRESSED_STATE){
					subKeyProcessReset();
				}
				timerForKeyPressRes = 100;
			}
		}
	}
}
void getKeyInputInc(){
	KeyReg3 = KeyReg4;
	KeyReg4 = KeyReg5;
	KeyReg5 = HAL_GPIO_ReadPin(ButtonInc_GPIO_Port, ButtonInc_Pin);
	if((KeyReg3 == KeyReg4) && (KeyReg4 == KeyReg5)){
		if(KeyReg10 != KeyReg5){
			KeyReg10 = KeyReg5;
			if(KeyReg5 == PRESSED_STATE){	//Nhan Tha
				//TODO
				subKeyProcessInc();
				timerForKeyPressInc = 300;
			}
		} else {							//Nhan Giu
			timerForKeyPressInc--;
			if(timerForKeyPressInc == 0){
				//TODO
				if(KeyReg5 == PRESSED_STATE){
					subKeyProcessInc();
				}
				timerForKeyPressInc = 100;
			}
		}
	}
}
void getKeyInputDec(){
	KeyReg6 = KeyReg7;
	KeyReg7 = KeyReg8;
	KeyReg8 = HAL_GPIO_ReadPin(ButtonDec_GPIO_Port, ButtonDec_Pin);
	if((KeyReg6 == KeyReg7) && (KeyReg7 == KeyReg8)){
		if(KeyReg11 != KeyReg8){
			KeyReg11 = KeyReg8;
			if(KeyReg8 == PRESSED_STATE){	//Nhan Tha
				//TODO
				subKeyProcessDec();
				timerForKeyPressDec = 300;
			}
		} else {							//Nhan Giu
			timerForKeyPressDec--;
			if(timerForKeyPressDec == 0){
				//TODO
				if(KeyReg8 == PRESSED_STATE){
					subKeyProcessDec();
				}
				timerForKeyPressDec = 100;
			}
		}
	}
}

