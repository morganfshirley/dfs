#include "object.h" //Forward-declared in component.h
#include "rendercomponent.h"

RenderComponent::RenderComponent(){
	symbol = '?';
}

RenderComponent::RenderComponent(unsigned char in) {
	symbol = in;
}

unsigned char RenderComponent::getSymbol() {
	return symbol;
}

void RenderComponent::setSymbol(unsigned char in) {
	symbol = in;
}

void RenderComponent::run() {
	object->setSymbol(symbol);
}
