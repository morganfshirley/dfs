#include "object.h" //Forward-declared in component.h
#include "component.h"

void Component::setObject(Object *newObject) {
	object = newObject;
}

Object* Component::getObject() {
	return object;
}

void Component::run() {

}
