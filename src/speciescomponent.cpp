#include "object.h" //Forward-declared
#include "speciescomponent.h"

SpeciesComponent::SpeciesComponent() {
	species = NULL;
	object->setSymbol('?');
}

SpeciesComponent::SpeciesComponent(Species *new_species) {
	species = new_species;
}

void SpeciesComponent::run() {	
	object->setSymbol(species->symbol);
	object->setBaseStats(&(species->stats));
}
