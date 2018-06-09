/*
 * menu.c
 *
 *  Created on: 19 de mai de 2018
 *      Author: Luis Felipe Kunzler
 */

#include "menu.h"

void _menuEnterPosition(uint8_t pos);

void menuInit() {

}

void menuGoto(uint8_t pos) {
	_menuEnterPosition(pos);
}

void menuSetPosition(uint8_t pos, MenuItem *item) {
	Menu.Items[pos] = item;
}

void _menuEnterPosition(uint8_t pos) {
	Menu.Current = Menu.Items[pos];
	Menu.Current->Enter();
	Menu.NeedsRedraw = 1;
}

void menuNext() {
	Menu.Index++;

	Menu.Current->Exit();
	if (Menu.Index >= MENU_ITEMS_COUNT)
		Menu.Index = 0;

	_menuEnterPosition(Menu.Index);
}

void menuPrev() {
	Menu.Current->Exit();
	if (Menu.Index > 0)
		Menu.Index--;

	_menuEnterPosition(Menu.Index);
}

void menuSetKey(KEYS key) {
	Menu.Current->KeyPressed(key);
}

void menuDraw() {
	Menu.NeedsRedraw = 1;
}

void menuReset() {
	Menu.Current->Exit();
	Menu.Index = 0;
	_menuEnterPosition(Menu.Index);
}

void menuRuntime() {
	if (Menu.NeedsRedraw) {
		Menu.NeedsRedraw = 0;
		if (Menu.Current) {
			Menu.Current->Render();
		}
	}
}
