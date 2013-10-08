#ifndef OBJECT_H
#define OBJECT_H

#include <vector>

#include "component.h"

class Object {
private:
	std::vector<Component> components;

	int x;
	int y;
public:
	Object();
	Object(int, int);
	Object(Component);
	Object(Component, int, int);
	
	void addComponent(Component);
	unsigned char render();
	void run();

	int getX();
	int getY();
	void setPosition(int, int, bool = false);
};

#endif //OBJECT_H
