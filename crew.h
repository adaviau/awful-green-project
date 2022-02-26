#ifndef CREW_H
#define CREW_H

#include "actor.h"
#include "weapon.h"

class Crew : public Actor {

private:
    Weapon * weapon;
    bool mascot;
    bool robot;
    // Equipement * wearable;

public:
    Crew( std::string );
    Crew( std::string, Location& );

    void set_mascot( );
    void set_robot( );    
    bool isMascot( );
    bool isRobot( );
    void grab( Weapon& );
    bool canGrabWeapon( );
    bool hasWeapon( );
    Weapon * getWeapon( );
    // void grab( Equipment& );
    void drop( );

};

#endif