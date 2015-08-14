#include "object.h"

Object::Object() {
	symbol = '?'; //A rather elegant solution
	base_stats = 0;
	modified_stats = 0;
}

Object::Object(int x, int y) {
	setPosition(x, y);
	symbol = '?'; //A rather elegant solution
	base_stats = 0;
	modified_stats = 0;
}

Object::Object(Component *c) {
	addComponent(c);
	symbol = '?'; //A rather elegant solution
	base_stats = 0;
	modified_stats = 0;
}

Object::Object(Component *c, int x, int y) {
	addComponent(c);
	setPosition(x, y);
	symbol = '?'; //A rather elegant solution
	base_stats = 0;
	modified_stats = 0;
}

Object::~Object() {/**
	while(components.size() > 0) {
		delete components.at(components.size() - 1);
		components.pop_back();
	}*/
}

Object::Object(const Object &that) {
	for(std::size_t i = 0; i < that.components.size(); i++) {
		Component *c = new Component(*(that.components.at(i)));
		addComponent(c);
	}
}

Object& Object::operator=(const Object &that) {
	for(std::size_t i = 0; i < that.components.size(); i++) {
		Component *c = new Component(*(that.components.at(i)));
		addComponent(c);
	}
	return *this;
}

void Object::addComponent(Component *c) {
	c->setObject(this);
	components.push_back(c);
	
}

unsigned char Object::render() {
	return symbol;
}

void Object::run() {
	for(std::size_t i = 0; i < components.size(); i++) {
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

Stats * Object::getBaseStats() {
	return base_stats;
}

void Object::setBaseStats(Stats *in) {
	base_stats = in;
	if(modified_stats == 0) {
		modified_stats = new Stats;
		*modified_stats = *in;
	}
}

unsigned int Object::getSpeed() {
	return modified_stats->speed;
}

unsigned int Object::getHitpoints() {
	return modified_stats->hitpoints;
}
double Object::getStrength() {
	return modified_stats->strength;
}
double Object::getArmorclass() {
	return modified_stats->armorclass;
}

void Object::setSpeed(int in, bool relative) {
	if(relative) {
		if(modified_stats->speed + in < 0) {
			modified_stats->speed = 0;
			return;
		}
		modified_stats->speed += in;
	}
	else {
		modified_stats->speed = in;
	}
}

void Object::setHitpoints(int in, bool relative) {
	if(relative) {
		if(modified_stats->hitpoints + in < 0) {
			modified_stats->hitpoints = 0;
			return;
		}
		modified_stats->hitpoints += in;
	}
	else {
		modified_stats->hitpoints = in;
	}
}

void Object::setStrength(double in, bool relative) {
	if(relative) {
		modified_stats->strength += in;
	}
	else {
		modified_stats->strength = in;
	}
}

void Object::setArmorclass(double in, bool relative) {
	if(relative) {
		modified_stats->armorclass += in;
	}
	else {
		modified_stats->armorclass = in;
	}
}
