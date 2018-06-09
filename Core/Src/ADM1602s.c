/*
 * ADM1602s.c
 *
 *  Created on: 19 de mai de 2018
 *      Author: luis
 */

#include "main.h"
#include "lcd_interface.h"

void lcd_init()
{
	HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 0);
}

void lcd_write(uint8_t c)
{
	// para escrever dados, RS_pin = 1
	HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, 1);

	HAL_GPIO_WritePin(DB0_GPIO_Port, DB0_Pin, (c & 0x01) > 0 ? 1 : 0);
	HAL_GPIO_WritePin(DB1_GPIO_Port, DB1_Pin, (c & 0x02) > 0 ? 1 : 0);
	HAL_GPIO_WritePin(DB2_GPIO_Port, DB2_Pin, (c & 0x04) > 0 ? 1 : 0);
	HAL_GPIO_WritePin(DB3_GPIO_Port, DB3_Pin, (c & 0x08) > 0 ? 1 : 0);
	HAL_GPIO_WritePin(DB4_GPIO_Port, DB4_Pin, (c & 0x10) > 0 ? 1 : 0);
	HAL_GPIO_WritePin(DB5_GPIO_Port, DB5_Pin, (c & 0x20) > 0 ? 1 : 0);
	HAL_GPIO_WritePin(DB6_GPIO_Port, DB6_Pin, (c & 0x40) > 0 ? 1 : 0);
	HAL_GPIO_WritePin(DB7_GPIO_Port, DB7_Pin, (c & 0x80) > 0 ? 1 : 0);

	// pulso no enable, para pegar a informacao nos pinos
	// precisaria de 43us no enable
	HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
	HAL_Delay(2); // usaremos 1mili por enquanto
	HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 0);
}

void lcd_cmd_write(uint8_t c)
{
	HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, 0);

	HAL_GPIO_WritePin(DB0_GPIO_Port, DB0_Pin, (c & 0x01) > 0 ? 1 : 0);
	HAL_GPIO_WritePin(DB1_GPIO_Port, DB1_Pin, (c & 0x02) > 0 ? 1 : 0);
	HAL_GPIO_WritePin(DB2_GPIO_Port, DB2_Pin, (c & 0x04) > 0 ? 1 : 0);
	HAL_GPIO_WritePin(DB3_GPIO_Port, DB3_Pin, (c & 0x08) > 0 ? 1 : 0);
	HAL_GPIO_WritePin(DB4_GPIO_Port, DB4_Pin, (c & 0x10) > 0 ? 1 : 0);
	HAL_GPIO_WritePin(DB5_GPIO_Port, DB5_Pin, (c & 0x20) > 0 ? 1 : 0);
	HAL_GPIO_WritePin(DB6_GPIO_Port, DB6_Pin, (c & 0x40) > 0 ? 1 : 0);
	HAL_GPIO_WritePin(DB7_GPIO_Port, DB7_Pin, (c & 0x80) > 0 ? 1 : 0);

	HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
	HAL_Delay(1); // usaremos 1mili por enquanto
	HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 0);
}

void lcd_set_addr(uint8_t addr)
{
	HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, 0);

	HAL_GPIO_WritePin(DB0_GPIO_Port, DB0_Pin, (addr & 0x01) > 0 ? 1 : 0);
	HAL_GPIO_WritePin(DB1_GPIO_Port, DB1_Pin, (addr & 0x02) > 0 ? 1 : 0);
	HAL_GPIO_WritePin(DB2_GPIO_Port, DB2_Pin, (addr & 0x04) > 0 ? 1 : 0);
	HAL_GPIO_WritePin(DB3_GPIO_Port, DB3_Pin, (addr & 0x08) > 0 ? 1 : 0);
	HAL_GPIO_WritePin(DB4_GPIO_Port, DB4_Pin, (addr & 0x10) > 0 ? 1 : 0);
	HAL_GPIO_WritePin(DB5_GPIO_Port, DB5_Pin, (addr & 0x20) > 0 ? 1 : 0);
	HAL_GPIO_WritePin(DB6_GPIO_Port, DB6_Pin, (addr & 0x40) > 0 ? 1 : 0);
	HAL_GPIO_WritePin(DB7_GPIO_Port, DB7_Pin, 1);

	HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
	HAL_Delay(1); // usaremos 1mili por enquanto
	HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 0);
}
