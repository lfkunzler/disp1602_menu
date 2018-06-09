/*
 * menu.h
 *
 *  Created on: 19 de mai de 2018
 *      Author: Luis Felipe Kunzler
 *      Mail: kunzler.luis@gmail.com
 */

#ifndef INC_MENU_H_
#define INC_MENU_H_
#include <stdint.h>

#include "keyboard.h"

#define MENU_ITEMS_COUNT 4

typedef void (*OnEnter)();
typedef void (*OnRender)();
typedef void (*OnKey)(KEYS key);
typedef void (*OnExit)();

typedef struct _MenuItem
{
	OnEnter Enter;
	OnRender Render;
	OnKey KeyPressed;
	OnExit Exit;
} MenuItem;

struct _Menu
{
	uint8_t NeedsRedraw;
	uint8_t Index;
	MenuItem* Current;
	MenuItem* Items[MENU_ITEMS_COUNT];
} Menu;

void menuInit();
void menuGoto(uint8_t pos);
void menuSetPosition(uint8_t pos, MenuItem *item);
void menuNext();
void menuPrev();
void menuReset();
void menuRuntime();
void menuSetKey(KEYS key);
// Required execution rate = 50hz;
void menuDraw();

#endif /* INC_MENU_H_ */
