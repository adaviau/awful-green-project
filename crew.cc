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

void Crew::setMascot( bool b ) { mascot = b; }

void Crew::grab( Weapon& w ) {  
    
    if ( canGrabWeapon() ) {
        w.grab();
        weapon = &w;
    }

}

bool Crew::canGrabWeapon() {

    return !mascot && !stunned;

}

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