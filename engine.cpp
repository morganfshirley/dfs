#include "engine.h"

int Engine::getInput() {
	return getch();
}

void Engine::dealWithKeys(int ch) {

	//exit the game if we press q (TODO remove this in favor of a menu)
	if(ch == 'q' || ch == 'Q') {
		running = false;
	}
	else if( //The following should be sent to the player
		ch == KEY_LEFT	||	ch == KEY_RIGHT	||
		ch == KEY_UP	||	ch == KEY_DOWN	||
		ch == KEY_A1	||	ch == KEY_A3	||
		ch == KEY_C1	||	ch == KEY_C3	||
		ch == KEY_B2 ) {
		player_brain->setInput(ch);
	}
}

Engine::Engine() {
	running = true;

	//Testing, TODO remove
	object_list.push_back(new Object(new RenderComponent('!'), 3, 4));
	object_list.push_back(new Object(new RenderComponent('g'), 6, 1));
	object_list.push_back(new Object(new RenderComponent('3'), 23, 4));
	object_list.at(0)->addComponent(new BaseLogicComponent());
	
	player = new Object(new RenderComponent('@'), 10, 10);
	object_list.push_back(player);
	
	player_brain = new PlayerLogicComponent();
	player->addComponent(player_brain);	

	srand(time(NULL));
}

Engine::~Engine() {
	while(object_list.size() > 0) {
		Object *deleted_ptr = object_list.back();
		object_list.pop_back();
		delete deleted_ptr;
	}
}

bool Engine::isRunning() {
	return running;
}

void Engine::run() {
	//Keyboard input
	int ch = getInput();
	dealWithKeys(ch);

	//Run objects
	for(int i = 0; i < object_list.size(); i++) {
		object_list.at(i)->run();
	}
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
