#include "monster.h"

Monster::Monster( std::string s ) : 
    Actor( "Monster", MONSTER ) {
    
    location = nullptr;
    active = false;
    setType( s );

}

Monster::Monster( std::string s, Location& l ) : 
    Actor( "Monster", MONSTER, l ) {
    
    active = false;
    setType( s );

}

void Monster::activate() {  active = true;  };

void Monster::setType( std::string s ) {

    stage = s; 

    if ( s == "FRAGMENT" ) {
        setStats( 0, 1, 8 );
    } else if ( s == "EGG" ) {
        setStats( 0, 0, 5 );
    } else if ( s == "BABY" ) {
        setStats( 1, 2, 12 );
    } else if ( s == "ADULT" ) {
        setStats( 2, 4, 16 );
    }

}

std::string Monster::getStage() {   return stage;   }