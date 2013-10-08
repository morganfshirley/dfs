#ifndef OBJECT_H
#define OBJECT_H

#include <vector>

#include "component.h"

class Object {
private:
	std::vector<Component> components;
public:
	Object();
	Object(Component c);
	
	void addComponent(Component c);
	unsigned char render();
	void run();
}

#endif //OBJECT_H
