/*
 * button.h
 *
 *  Created on: Nov 5, 2022
 *      Author: lamkh
 */

#ifndef SRC_BUTTON_H_
#define SRC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

int isButtonResetPressed();
int isButtonIncPressed();
int isButtonDecPressed();

void getKeyInputReset();
void getKeyInputInc();
void getKeyInputDec();


#endif /* SRC_BUTTON_H_ */
