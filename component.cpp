#include "object.h" //Forward-declared in component.h
#include "component.h"

Component::Component(Object* parent) {
	object = parent;
}

void Component::setObject(Object *newObject) {
	object = newObject;
}

Object* Component::getObject() {
	return object;
}

void Component::run() {

}
