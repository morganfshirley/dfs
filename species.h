#ifndef SPECIES_H
#define SPECIES_H

#include <string>

#include "stats.h"

typedef struct Species {
	std::string name;
	unsigned char symbol;
	Stats stats;
} Species;

#endif
