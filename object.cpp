#include "object.h"

Object::Object() {
	symbol = '?'; //A rather elegant solution
}

Object::Object(int x, int y) {
	setPosition(x, y);
	symbol = '?'; //A rather elegant solution
}

Object::Object(Component *c) {
	addComponent(c);
	symbol = '?'; //A rather elegant solution
}

Object::Object(Component *c, int x, int y) {
	addComponent(c);
	setPosition(x, y);
	symbol = '?'; //A rather elegant solution
}

Object::~Object() {
	while(components.size() > 0) {
		delete components.back();
		components.pop_back();
	}
}

Object::Object(const Object &that) {
	for(int i = 0; i < that.components.size(); i++) {
		Component *c = new Component(*(that.components.at(i)));
		addComponent(c);
	}
}

Object& Object::operator=(const Object &that) {
	for(int i = 0; i < that.components.size(); i++) {
		Component *c = new Component(*(that.components.at(i)));
		addComponent(c);
	}
}

void Object::addComponent(Component *c) {
	c->setObject(this);
	components.push_back(c);
	
}

unsigned char Object::render() {
	return symbol;
}

void Object::run() {
	for(int i = 0; i < components.size(); i++) {
		components.at(i)->run();
	}
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

unsigned char Object::getSymbol() {
	return symbol;
}

void Object::setSymbol(unsigned char in) {
	symbol = in;
}
