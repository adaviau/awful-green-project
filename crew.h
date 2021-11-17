#ifndef CREW_H
#define CREW_H

#include "actor.h"
#include "weapon.h"

class Crew : public Actor {

private:
    bool alive;
    Weapon * weapon;
    // Equipement * wearable;

public:
    Crew( std::string, Location& );
    
    bool isAlive();

};

#endif