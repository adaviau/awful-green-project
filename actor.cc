#include <iostream>

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
    std::cout << "Stats (m,s,c) : " << movement << "," << strength << "," << constitution << "\n";
}

int Actor::getMovement() { return movement; }
int Actor::getStrength() { return strength; }
int Actor::getConstitution() { return constitution; }

bool Actor::isStunned() { return stunned; }
bool Actor::isActive() { return active; }

void Actor::stun() { stunned = true; }
void Actor::wakeup() { stunned = false; }