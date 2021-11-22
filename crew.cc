#include "crew.h"

Crew::Crew( std::string n ) : Actor( n, CREW ) {

    active = true;
    weapon = nullptr;
    location = nullptr;
    setStats( 0, 0, 0 );

}

Crew::Crew( std::string n, Location& l ) : Actor( n, CREW, l ) {

    active = true;
    weapon = nullptr;
    setStats( 0, 0, 0 );

}

void Crew::grab( Weapon& w ) {  
    
    w.grab();
    weapon = &w;
    
}

void Crew::drop() {  

    weapon->drop( *location );
    weapon = nullptr; 
    
}