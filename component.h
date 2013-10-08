#ifndef COMPONENT_H
#define COMPONENT_H

class Component {
private:
	unsigned char symbol;
public:
	Component();
	unsigned char getSymbol();
	void setSymbol(unsigned char);
}

#endif //COMPONENT_H
