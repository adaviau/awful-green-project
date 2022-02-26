#include "crew.h"

Crew::Crew( std::string n ) : Actor( n, CREW ) {

    weapon = nullptr;
    location = nullptr;
    setStats( 0, 0, 0 );

}

Crew::Crew( std::string n, Location& l ) : Actor( n, CREW, l ) {

    weapon = nullptr;
    setStats( 0, 0, 0 );

}

void Crew::set_mascot() { mascot = true; }

void Crew::set_robot() { robot = true; }

void Crew::grab( Weapon& w ) {  
    
    if ( canGrabWeapon() ) {
        w.grab();
        weapon = &w;
    }

}

bool Crew::canGrabWeapon() {

    return !mascot && !stunned;

}

bool Crew::isMascot() { return mascot;  }

bool Crew::isRobot() {  return robot;   }

bool Crew::hasWeapon() {

    return weapon;

}

Weapon * Crew::getWeapon() {

    return weapon;

}

void Crew::drop() {  

    weapon->drop( *location );
    weapon = nullptr; 
    
}