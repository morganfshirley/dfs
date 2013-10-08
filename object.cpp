#include "object.h"

Object::Object() {
	components.push_back(Component());
}

Object::Object(int x, int y) {
	setPosition(x, y);
	components.push_back(Component());
}

Object::Object(Component c) {
	components.push_back(c);
}

Object::Object(Component c, int x, int y) {
	components.push_back(c);
	setPosition(x, y);
}

void Object::addComponent(Component c) {
	components.push_back(c);
}

unsigned char Object::render() {
	return components.at(0).getSymbol();
}

void Object::run() {
	
}

int Object::getX() {
	return x;
}

int Object::getY() {
	return y;
}

void Object::setPosition(int x, int y, bool relative) { //relative is optional, default to false
	if(relative) {
		this->x += x;
		this->y += y;
	}
	else {
		this->x = x;
		this->y = y;
	}
}
