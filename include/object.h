#ifndef OBJECT_H
#define OBJECT_H

#include <vector>

#include "component.h"
#include "rendercomponent.h"
#include "baselogiccomponent.h"
#include "stats.h"

class Object {
private:
	std::vector<Component*> components;

	int x;
	int y;

	unsigned char symbol;

	Stats *base_stats;
	Stats *modified_stats;
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

	Stats *getBaseStats();
	void setBaseStats(Stats*);
	
	//Modified stats
	unsigned int getSpeed();
	unsigned int getHitpoints();
	double getStrength();
	double getArmorclass();

	//Setters. automatically will set stats relatively.
	void setSpeed(int, bool = true); 
	void setHitpoints(int, bool = true);
	void setStrength(double, bool = true);
	void setArmorclass(double, bool = true);
};

#endif //OBJECT_H
