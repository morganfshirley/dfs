#include "object.h"

Object::Object() {
	components.push_back(Component());
}

Object::Object(Component c) {
	components.push_back(c);
}

void Object::addComponent(Component c) {
	components.push_back(c);
}

unsigned char render() {
	return components.at(0).getSymbol();
}

void run() {
	
}
