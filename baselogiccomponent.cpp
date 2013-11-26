#include "object.h" //Forward-declared in component.h
#include "baselogiccomponent.h"

#include <cfloat>
#include <cstdlib>

int BaseLogicComponent::getHighestMotivation() {
	int max_value = -DBL_MAX; //set it to the minimum
	int max = 0;
	for(int i = 0; i < M_NUMBER; i++) {
		if(motivation_weights[i] > max_value) {
			max_value = motivation_weights[i];
			max = i;
		}
	}	
	return max;
}

void BaseLogicComponent::act() {
	//TODO: revamp

	switch(getHighestMotivation()) {
		case M_WANDERLUST: //The donkey has tons of Wanderlust

		/**
		 * Eventually we should do something like the following:
		 *
		 * -Locations will be defined
		 * -Pick a location
		 * -Pathfind to there
		 *
		 * Currently, however, we just pick a random spot
		 */

			if(planned_path.size() == 0) { //Choose somewhere to go
				//Pick a spot
				int new_x = rand() % 30;
				int new_y = rand() % 30;
	
				//Figure out how to go there
				planPath(new_x, new_y);
			}
			//Move!
			move(planned_path.back());
			planned_path.pop_back();
			
			break;
		default:
			//Act if we feel like it
			if(initiative > 0) {
				move(rand() % 5);
				initiative = initiative - 5;
			}
	}
	initiative++;
}

void BaseLogicComponent::planPath(int new_x, int new_y) {
	//Since we don't have collision detection, we'll just go there
	if(object->getX() > new_x) {
		for(int i = object->getX(); i > new_x; i--) {
			planned_path.push_back(3);
		}
	}
	else {
		for(int i = object->getX(); i < new_x; i++) {
			planned_path.push_back(2);
		}	
	}
	if(object->getY() > new_y) {	
		for(int i = object->getY(); i > new_x; i--) {
			planned_path.push_back(1);
		}	
	}
	else {
		for(int i = object->getY(); i < new_x; i++) {
			planned_path.push_back(0);
		}	
	}
}

void BaseLogicComponent::move(int direction) {
	switch(direction) {
		case 0: 
			object->setPosition(0, 1, true); break;
		case 1:
			object->setPosition(0, -1, true); break;
		case 2: 
			object->setPosition(1, 0, true); break;
		case 3:
			object->setPosition(-1, 0, true); break;
		case 4:
			//Do nothing
			break;
				}
}

//Publics:

BaseLogicComponent::BaseLogicComponent() {
	for(int i = 0; i < M_NUMBER; i++) {
		motivation_weights[i] = 0;
	}

	initiative = 0;
}

/**
 * Essentially, we should assign priorities to various wants/needs
 * and act accordingly. Possible motivations:
 * 	AMBITION
 * 	HUNGER
 * 	THIRST
 * 	MALICE
 * 	FRIGHT
 * 	WANDERLUST
 * 	WORRY
 *
 * And special motivations (override all):
 * 	PLAYER
 */

void BaseLogicComponent::run() {
	act();
}

void BaseLogicComponent::setMotivationWeight(int motivation, double weight) {
	motivation_weights[motivation] = weight;
} 
