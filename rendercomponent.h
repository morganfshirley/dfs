#ifndef RENDERCOMPONENT_H
#define RENDERCOMPONENT_H

#include "component.h"

class RenderComponent : public Component {
private:
	unsigned char symbol;
public:
	RenderComponent();
	RenderComponent(unsigned char);
	unsigned char getSymbol();
	void setSymbol(unsigned char);	

	virtual void run();
};

#endif //RENDERCOMPONENT_H
