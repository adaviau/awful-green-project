#include "actor.h"

Actor::Actor( ENTITY_TYPE t ) : Actor( "Invalid", t ) { }

Actor::Actor( std::string n, ENTITY_TYPE t ) : Entity( n, t ) { 
    location = nullptr;
    stunned = false;
}

Actor::Actor( std::string n, ENTITY_TYPE t,  Location& l ) : Actor( n, t ) { }

void Actor::setStats( int m, int s, int c ) {

    movement = m;
    strength = s;
    constitution = c;

}

bool Actor::isStunned() {   return stunned; }
