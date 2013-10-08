#include "engine.h"

char Engine::getInput() {
	return getch();
}

Engine::Engine() {
	running = true;

	//Testing, TODO remove
	object_list.push_back(new Object(2, 3));
	object_list.push_back(new Object(4, 5));
	object_list.push_back(new Object(9, 1));
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
	char ch = getInput();
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
}
