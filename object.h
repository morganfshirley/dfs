#ifndef OBJECT_H
#define OBJECT_H

#include <vector>

#include "component.h"
#include "rendercomponent.h"
#include "baselogiccomponent.h"

class Object {
private:
	std::vector<Component*> components;

	int x;
	int y;

	unsigned char symbol;
public:
	Object();
	Object(int, int);
	Object(Component*);
	Object(Component*, int, int);

	//Rule of 3 for Objects	
	~Object();
	Object(const Object &that);
	Object& operator=(const Object &that);

	void addComponent(Component*);
	unsigned char render();
	void run();

	int getX();
	int getY();
	void setPosition(int, int, bool = false);

	unsigned char getSymbol();
	void setSymbol(unsigned char);
};

#endif //OBJECT_H
