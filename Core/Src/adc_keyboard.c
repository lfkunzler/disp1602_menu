/*
 * adc_keyboard.c
 *
 *  Created on: 9 de jun de 2018
 *      Author: luis
 */

#include "keyboard_interface.h"
#include "stm32f4xx_hal.h"
#include "adc.h"

uint16_t aux;

void keyboard_init() {
	/* por pooling */
	//HAL_ADC_Start(&hadc1);
}

uint8_t keyboard_read() {
	/* por pooling */
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 10);

	//uint16_t aux = HAL_ADC_GetValue(&hadc1);
	aux = HAL_ADC_GetValue(&hadc1);

	if (aux < 100) { // nenhuma tecla pressionada
		return 0;
	}
	if (aux > 4000) { // tecla 1 pressionada
		return 1;
	}
	if (aux > 3300 && aux < 3500) { // tecla 2
		return 2;
	}
	if (aux > 1950 && aux < 2150) { // tecla 3
		return 3;
	}
	if (aux < 800) { // tecla 4
		return 4;
	}

	return 0xFF;
}
