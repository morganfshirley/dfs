#include "object.h" //Forward-declared
#include "playerlogiccomponent.h"

PlayerLogicComponent::PlayerLogicComponent() {
	//Null-initialize the input
	input = 0;
}

void PlayerLogicComponent::setInput(int in) {
	input = in;
}

void PlayerLogicComponent::act() {
	//Deal with any input we have
	switch(input) {
		//Arrow keys, or num pad
		case KEY_LEFT: 
			object->setPosition(-1, 0, true); break;
		case KEY_RIGHT:
			object->setPosition(1, 0, true); break;
		case KEY_UP:
			object->setPosition(0, -1, true); break;
		case KEY_DOWN:
			object->setPosition(0, 1, true); break;
		//Num pad diagonals
		case KEY_A1: //upper-left
			object->setPosition(-1, -1, true); break;
		case KEY_A3: //upper-right
			object->setPosition(1, -1, true); break;
		case KEY_C1: //lower-left
			object->setPosition(-1, 1, true); break;
		case KEY_C3: //lower-right
			object->setPosition(1, 1, true); break;
		case KEY_B2: //middle - do nothing!
			break;
		default:
			break;
	}
}

double PlayerLogicComponent::getInitiative() {
	return initiative;
}
