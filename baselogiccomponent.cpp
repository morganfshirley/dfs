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

	//Act if we feel like it
	if(initiative > 0) {
		switch(rand() % 5) {
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
		initiative = initiative - 5;
	}
	initiative++;
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
