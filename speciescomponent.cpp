#include "object.h" //Forward-declared
#include "speciescomponent.h"

SpeciesComponent::SpeciesComponent() {
	species = NULL;
	symbol = '?';
}

SpeciesComponent::SpeciesComponent(Species *new_species) {
	species = new_species;
	symbol = species->symbol;
}
