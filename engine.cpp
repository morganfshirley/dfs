#include "engine.h"

char Engine::getInput() {
	return getch();
}

void Engine::dealWithKeys(unsigned char ch) {

	//exit the game if we press q (TODO remove this in favor of a menu)
	if(ch == 'q' || ch == 'Q') {
		running = false;
	}
}

Engine::Engine() {
	running = true;

	//Testing, TODO remove
	object_list.push_back(new Object(new RenderComponent(NULL, '!'), 3, 4));
	object_list.push_back(new Object(new RenderComponent(NULL, 'g'), 6, 1));
	object_list.push_back(new Object(new RenderComponent(NULL, '3'), 23, 4));
}

Engine::~Engine() {
	while(object_list.size() > 0) {
		delete object_list.back();
		object_list.pop_back();
	}
}

bool Engine::isRunning() {
	return running;
}

void Engine::run() {
	//Run objects
	for(int i = 0; i < object_list.size(); i++) {
		object_list.at(i)->run();
	}

	//Keyboard input
	char ch = getInput();
	dealWithKeys(ch);
}

void Engine::render() {
	//Get screen dimensions
	int screen_min_x, screen_min_y, screen_max_x, screen_max_y;
	getbegyx(stdscr, screen_min_y, screen_min_x);
	getmaxyx(stdscr, screen_max_y, screen_max_x);

	//Draw objects
	for(int i = 0; i < object_list.size(); i++) {
		mvaddch(
			object_list.at(i)->getY(),
			object_list.at(i)->getX(),
			object_list.at(i)->render()
		);
	}

	//Draw cursor
	curs_set(0);
	drawPointer(0, 0);
}
