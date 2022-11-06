/*
 * led7.c
 *
 *  Created on: Nov 6, 2022
 *      Author: lamkh
 */
#include "led7.h"
int status = 0;
int n = 9;
int led7[10][7] = {
		{0, 0, 0, 0, 0, 0, 1},	//0
		{1, 0, 0, 1, 1, 1, 1},	//1
		{0, 0, 1, 0, 0, 1, 0},	//2
		{0, 0, 0, 0, 1, 1, 0},	//3
		{1, 0, 0, 1, 1, 0, 0},	//4
		{0, 1, 0, 0, 1, 0, 0},	//5
		{0, 1, 0, 0, 0, 0, 0},	//6
		{0, 0, 0, 1, 1, 1, 1},	//7
		{0, 0, 0, 0, 0, 0, 0},	//8
		{0, 0, 0, 0, 1, 0, 0},	//9
};

void display7(int n){
	HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, led7[n][0]);
	HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, led7[n][1]);
	HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, led7[n][2]);
	HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, led7[n][3]);
	HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, led7[n][4]);
	HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, led7[n][5]);
	HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, led7[n][6]);
}
