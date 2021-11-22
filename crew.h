#ifndef CREW_H
#define CREW_H

#include "actor.h"
#include "weapon.h"

class Crew : public Actor {

private:
    Weapon * weapon;
    // Equipement * wearable;

public:
    Crew( std::string );
    Crew( std::string, Location& );

    void grab( Weapon& );
    // void grab( Equipment& );
    void drop();

};

#endif