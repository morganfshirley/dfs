#include "object.h" //Forward-declared in component.h
#include "rendercomponent.h"

RenderComponent::RenderComponent(Object* parent) : Component(parent){
	symbol = '?';
}

RenderComponent::RenderComponent(Object* parent, unsigned char in) : Component(parent) {
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
