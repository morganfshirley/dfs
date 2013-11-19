//The Engine is what does the stuff

#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>

#include "render.h"
#include "object.h"
#include "playerlogiccomponent.h"

class Engine {
private:
	bool running;
	std::vector<Object*> object_list;
	Object *player;
	PlayerLogicComponent *player_brain;

	int getInput();
	void dealWithKeys(int);
public:
	Engine();
	~Engine();

	bool isRunning();
	void run();
	void render();
};
