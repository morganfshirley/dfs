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

void drawPointer(int x, int y) {
	//Get screen dimensions
	int screen_min_x, screen_min_y, screen_max_x, screen_max_y;
	getbegyx(stdscr, screen_min_y, screen_min_x);
	getmaxyx(stdscr, screen_max_y, screen_max_x);

	//TODO: Perspective stuff

	move(y, x);
}
