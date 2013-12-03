#ifndef SPECIES_H
#define SPECIES_H

#include <string>
#include <fstream> 
#include <cstdlib>

#include "stats.h"

/**
 * This should be loaded from a file in the following format:
 *
 * [name="..." symbol="0" speed="10" hitpoints="123" strength="32.3"
 * 	armorclass="23423"]
 */ 

typedef struct Species {
	std::string name;
	unsigned char symbol;
	Stats stats;
} Species;

bool loadSpecies(Species*, std::ifstream*);


#endif
