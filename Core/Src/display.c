/*
 * display.c
 *
 *  Created on: 19 de mai de 2018
 *      Author: luis
 */
#include "display.h"

void lcdInit(LCD *lcd) {
	// limpa a memoria do display
	for (int i = 0; i < 16; i++) {
		lcd->Memory[0][i] = 0x20;
		lcd->Memory[1][i] = 0x20;
	}

	lcd_init();
	lcd_cmd_write(0x01); // clear display
	lcd_cmd_write(0x02); // return home
	lcd_cmd_write(0x06); // entry mode set
	lcd_cmd_write(0x0C); // display on/off control
	lcd_cmd_write(0x14); // cursor or display shift
	lcd_cmd_write(0x38); // function set
	HAL_Delay(10); // 10 mili
}

#if 0
int lcdSetPos(uint8_t linha, uint8_t coluna) {
	uint8_t __addr = 0;

	switch (linha) {
		case 1:
		__addr = 0x00;
		break;
		case 2:
		__addr = 0x40;
		break;
		default:
		return -1; // linha incorreta
	}

	if (coluna == 0 || coluna > 16) {
		return -1; // coluna incorreta
	}
	else {
		__addr += (coluna-1);
	}

	return 0;
}
#endif

void lcdWrite(LCD *lcd, char *string, uint8_t lin, uint8_t col) {
	while (*string) {
		if (col == 16 && lin == 0) {
			lin = 1;
			col = 0;
		}
		lcd->Memory[lin][col++] = *string;
		string++;
	}
	lcd->NeedsRedraw = 1;
}

void lcdRuntTime(LCD *lcd) {
	if (lcd->NeedsRedraw == 1) {
		lcd_set_addr(0x00);
		for (int i = 0; i < 16; i++) {
			lcd_write(lcd->Memory[0][i]);
		}
		lcd_set_addr(0x40);
		for (int i = 0; i < 16; i++) {

			lcd_write(lcd->Memory[1][i]);
		}

		lcd->NeedsRedraw = 0;
	}
}

void lcdCmdWrite() {

}
