/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
//#if !defined(__SOFT_FP__) && defined(__ARM_FP)
//  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
//#endif

void delay(void){
	for(uint32_t i = 0; i < 300000; i++);
}

uint8_t keypadPress(GPIOx_IDR_t *input, GPIOx_ODR_t *output, char *password, char *temp){
	uint8_t state = 1;
	output->pin_0 = 1;
	output->pin_1 = 1;
	output->pin_2 = 1;
	output->pin_3 = 1;
	output->pin_0 = 0;
	if(!(input->pin_8 == 1)){
		delay();
		strcat(temp, "1");

	}
	if(!(input->pin_9 == 1)){
		delay();
		strcat(temp, "2");
	}
	if(!(input->pin_10 == 1)){
		delay();
		strcat(temp, "3");
	}
	if(!(input->pin_11 == 1)){
		delay();
		strcat(temp, "A");
	}

	output->pin_0 = 1;
	output->pin_1 = 1;
	output->pin_2 = 1;
	output->pin_3 = 1;
	output->pin_1 = 0;
	if(!(input->pin_8 == 1)){
		delay();
		strcat(temp, "4");
	}
	if(!(input->pin_9 == 1)){
		delay();
		strcat(temp, "5");
	}
	if(!(input->pin_10 == 1)){
		delay();
		strcat(temp, "6");
	}
	if(!(input->pin_11 == 1)){
		delay();
		strcat(temp, "B");
	}

	output->pin_0 = 1;
	output->pin_1 = 1;
	output->pin_2 = 1;
	output->pin_3 = 1;
	output->pin_2 = 0;
	if(!(input->pin_8 == 1)){
		delay();
		strcat(temp, "7");
	}
	if(!(input->pin_9 == 1)){
		delay();
		strcat(temp, "8");
	}
	if(!(input->pin_10 == 1)){
		delay();
		strcat(temp, "9");
	}
	if(!(input->pin_11 == 1)){
		delay();
		strcat(temp, "C");
	}

	output->pin_0 = 1;
	output->pin_1 = 1;
	output->pin_2 = 1;
	output->pin_3 = 1;
	output->pin_3 = 0;
	if(!(input->pin_8 == 1)){
		delay();
		strcat(temp, "*");
	}
	if(!(input->pin_9 == 1)){
		delay();
		strcat(temp, "0");
	}
	if(!(input->pin_10 == 1)){
		delay();
		state = strcmp(password, temp);
		if(state != 0){
			printf("You have enter incorrect password. Please try again\n");
			strcpy(temp, "");
		}
	}
	if(!(input->pin_11 == 1)){
		delay();
		strcat(temp, "D");
	}
	return state;
}

int main(void)
{
	/*
	 * Setting the address of registers
	 */
	RCC_AHB1ENR_t *pClkCtrlReg = (RCC_AHB1ENR_t *) 0x40023830;
	GPIOx_MODER_t *pPortDModeReg = (GPIOx_MODER_t *) 0x40020C00;
	GPIOx_PUPDR_t *pPortDPUPDReg = (GPIOx_PUPDR_t *) 0x40020C0C;
	GPIOx_IDR_t *pPortDInReg = (GPIOx_IDR_t *) 0x40020C10;
	GPIOx_ODR_t *pPortDOutReg = (GPIOx_ODR_t *) 0x40020C14;

	// 1. Enable GPIOD clock register
	pClkCtrlReg->gpiod_en = 1;

	// 2. Configure PD0, PD1, PD2, PD3 as output (rows)
	pPortDModeReg->pin_0 = 0;
	pPortDModeReg->pin_1 = 0;
	pPortDModeReg->pin_2 = 0;
	pPortDModeReg->pin_3 = 0;

	pPortDModeReg->pin_0 = 0x01;
	pPortDModeReg->pin_1 = 0x01;
	pPortDModeReg->pin_2 = 0x01;
	pPortDModeReg->pin_3 = 0x01;

	// 3. Configure PD8, PD9, PD10, PD11 as input (cols)
	pPortDModeReg->pin_8 = 0;
	pPortDModeReg->pin_9 = 0;
	pPortDModeReg->pin_10 = 0;
	pPortDModeReg->pin_11 = 0;

	// 4. Enable internal pull-up registers for PD8, PD9, PD10, PD11
	pPortDPUPDReg->pin_8 = 0;
	pPortDPUPDReg->pin_9 = 0;
	pPortDPUPDReg->pin_10 = 0;
	pPortDPUPDReg->pin_11 = 0;

	pPortDPUPDReg->pin_8 = 0x01;
	pPortDPUPDReg->pin_9 = 0x01;
	pPortDPUPDReg->pin_10 = 0x01;
	pPortDPUPDReg->pin_11 = 0x01;

	char password[5] = "1234";
	char temp[5] = "";
	printf("Enter password to unlock (press # to exit): \n");
	while(1){
			uint8_t state = keypadPress(pPortDInReg, pPortDOutReg, password, temp);
			if(state == 0){
				printf("Correct password\n");
				strcpy(temp, "");
			}
	}
}