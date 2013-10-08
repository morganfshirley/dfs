//The Engine is what does the stuff

#include <vector>

#include "render.h"
#include "object.h"

class Engine {
private:
	bool running;
	std::vector<Object*> object_list;
	Object *player;

	char getInput();
public:
	Engine();

	bool isRunning();
	void run();
	void render();
}
