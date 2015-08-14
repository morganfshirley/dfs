#ifndef SPECIESCOMPONENT_H
#define SPECIESCOMPONENT_H

#include "rendercomponent.h"
#include "species.h"

class SpeciesComponent : public RenderComponent {
private:
	Species *species;
public:
	SpeciesComponent();
	SpeciesComponent(Species*);

	void run();
};
#endif
