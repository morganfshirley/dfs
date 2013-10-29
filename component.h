#ifndef COMPONENT_H
#define COMPONENT_H

//Forward-declaring object
class Object;

class Component {
private:
	unsigned char symbol;
protected:	
	Object *object; //the parent object
public:
	void setObject(Object*);
	Object* getObject();

	virtual void run();
};

#endif //COMPONENT_H
