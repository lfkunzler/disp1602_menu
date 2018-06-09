/*
 * display.h
 *
 *  Created on: 19 de mai de 2018
 *      Author: luis
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_
#include "stdint.h"
#include "stm32f4xx_hal.h"
#include "lcd_interface.h"

typedef struct {
	uint8_t NeedsRedraw;
	uint8_t Memory[2][16];
} LCD;

void lcdInit(LCD *lcd);
void lcdWrite(LCD *lcd, char *string, uint8_t lin, uint8_t col);
//int lcdSetPos(uint8_t linha, uint8_t coluna);
//void lcdCmdWrite();
void lcdRuntTime(LCD *lcd);

#endif /* INC_DISPLAY_H_ */
