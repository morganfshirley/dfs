#include "component.h"

Component::Component() {
	symbol = '$';
}

unsigned char Component::getSymbol() {
	return symbol;
}

void Component::setSymbol(unsigned char in) {
	symbol = in;
}
