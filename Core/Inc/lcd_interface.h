/*
 * lcd_interface.h
 *
 *  Created on: 19 de mai de 2018
 *      Author: luis
 */

#ifndef INC_LCD_INTERFACE_H_
#define INC_LCD_INTERFACE_H_

#define POS_LINE_0 0x00
#define POS_LINE_1 0x01

void lcd_init();
void lcd_write(uint8_t text);
void lcd_cmd_write(uint8_t c);
void lcd_set_addr(uint8_t addr);

#endif /* INC_LCD_INTERFACE_H_ */
