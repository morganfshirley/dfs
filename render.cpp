#include "render.h"

void initNCurses()
{
	initscr();
	clear();
	noecho();
	raw();
	keypad(stdscr, true);
	curs_set(0);
}
