#include <iostream>

#include "actor.h"

Actor::Actor( ENTITY_TYPE t ) : Actor( "Invalid", t ) { }

Actor::Actor( std::string n, ENTITY_TYPE t ) : Entity( n, t ) { 
    location = nullptr;
    stunned = false;
    turn_used = false;
    alive = true;
}

Actor::Actor( std::string n, ENTITY_TYPE t,  Location& l ) : Actor( n, t ) { }

void Actor::setStats( int m, int c, int s ) {

    movement = m;
    strength = s;
    constitution = c;
    std::cout << "Stats (m,s,c) : " << movement << "," << strength << "," << constitution << "\n";
}

int Actor::getMovement() { return movement; }
int Actor::getStrength() { return strength; }
int Actor::getConstitution() { return constitution; }

bool Actor::isStunned() { return stunned; }
bool Actor::isAlive() { return alive; }
bool Actor::canAttack() { return alive && !stunned && !turn_used ; }
void Actor::complete_turn() {   turn_used = true;   }
void Actor::reset_turn() {   turn_used = false;   }

void Actor::stun() { stunned = true; }
void Actor::wakeup() { stunned = false; }
void Actor::kill() { alive = false; }
