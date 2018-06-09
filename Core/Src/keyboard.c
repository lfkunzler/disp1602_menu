/*
 * keyboard.c
 *
 *  Created on: 9 de jun de 2018
 *      Author: luis
 */

#include "keyboard.h"

void keyboardInit(KeyboardCallback callback) {
	keyboard_init();

	Keyboard.Callback = callback;
	Keyboard.OldValue = 0xFF; // Dummy Value
}

// TODO: se ficar pressionando a tecla o tempo todo, vai ficar chamando essa funcao
// Para isso, implementamos um "keyboard_changed", que garante que o "evento" nao seja
// chamado o tempo todo
void keyboardRuntime() {
	uint8_t chave = keyboard_read();

	if (Keyboard.Callback) {
		if (chave != Keyboard.OldValue) { // se for diferente

			Keyboard.OldValue = chave; // atualiza valor  do teclado
			switch (chave) {
			case 0:
				// nenhuma tecla pressionada
				Keyboard.Callback(KEYNONE);

				break;
			case 1:
				Keyboard.Callback(KEY1);

				break;
			case 2:
				Keyboard.Callback(KEY2);

				break;
			case 3:
				Keyboard.Callback(KEY3);

				break;
			case 4:
				Keyboard.Callback(KEY4);

				break;
			}
		}
	}
}
