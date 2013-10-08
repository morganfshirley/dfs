#include "engine.h"

char Engine::getInput() {
	return getch();
}

Engine::Engine() {
	running = true;
}

bool Engine::isRunning() {
	return running;
}

void Engine::run() {

}

void Engine::render() {
	char ch = getInput();
}
