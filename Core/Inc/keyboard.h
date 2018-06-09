/*
 * keyboard.h
 *
 *  Created on: 9 de jun de 2018
 *      Author: luis
 */

#ifndef INC_KEYBOARD_H_
#define INC_KEYBOARD_H_

#include "keyboard_interface.h"

typedef enum {
	KEY1, KEY2, KEY3, KEY4, KEYNONE
} KEYS;

/* callback */
typedef void (*KeyboardCallback)(KEYS key);

struct {
	KeyboardCallback Callback; // pointeiro de funcao para callback
	uint8_t KeyboardChanged; // sinaliza o evento
	uint8_t OldValue;
} Keyboard;

void keyboardInit(KeyboardCallback callback);
void keyboardRuntime();

#endif /* INC_KEYBOARD_H_ */
