#include <iostream>

#include "entity.h"

static int UNIQUE_IDENTIFIER = 1000;

Entity::Entity() : id( ++UNIQUE_IDENTIFIER ), location( nullptr ) { }

Entity::Entity( std::string n, ENTITY_TYPE t ) : Entity() {

    name = n;
    type = t;
        
}

Entity::Entity( std::string n, ENTITY_TYPE t, Location& l ) : Entity(n, t) {

    enter( l );

}

void Entity::enter( Location& l ) {

    location = &l;
    location->enter( *this );

}

Location * Entity::getLocation() {  return location; }

int Entity::getID() {   return id;  }

std::string Entity::getName() { return name;    }

ENTITY_TYPE Entity::getType() { return type;    }



