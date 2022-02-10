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
        setStats( 0, 8, 1 );
    } else if ( s == "EGG" ) {
        setStats( 0, 5, 0 );
    } else if ( s == "BABY" ) {
        setStats( 1, 12, 2 );
    } else if ( s == "ADULT" ) {
        setStats( 2, 16, 4 );
    }

}

void Monster::grow() {   
    if ( stage == "FRAGMENT" ) {
        setStats( 1, 12, 2 );
    } else if ( stage == "EGG" ) {
        setStats( 1, 12, 2 );
    } else if ( stage == "BABY" ) {
        setStats( 1, 12, 2 );
    } else if ( stage == "ADULT" ) {
        setStats( 2, 16, 4 );
    }
}

std::string Monster::getStage() {   return stage;   }