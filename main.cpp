//DONKEY FINDING SIMULATOR
//
//A game about finding Donkeys
//
//Copyright Morgan Shirley 2013

#include <vector>

#include "render.h"
#include "engine.h"

int main() {
	initNCurses();

	Engine engine;

	while(engine.isRunning()) {
		clear();
		engine.render();
		engine.run();
	}

	endwin();
}
