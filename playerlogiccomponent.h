#ifndef PLAYERLOGICCOMPONENT_H
#define PLAYERLOGICCOMPONENT_H

#include "baselogiccomponent.h"
#include <ncurses.h>

class PlayerLogicComponent : public BaseLogicComponent {
private:
	virtual void act();
	
	//This will hold any input given by the setInput() function
	int input;
public:
	PlayerLogicComponent();
	
	//If there's any input that changes the state of the player, put it here.
	void setInput(int);
};

#endif //PLAYERLOGICCOMPONENT_H
