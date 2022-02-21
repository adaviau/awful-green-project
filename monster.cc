#include "monster.h"

Monster::Monster( std::string s ) : 
    Actor( "Monster", MONSTER ) {
    
    location = nullptr;
    setType( s );

}

Monster::Monster( std::string s, Location& l ) : 
    Actor( "Monster", MONSTER, l ) {
    
    setType( s );

}

// void Monster::activate() {  active = true;  };

void Monster::setType( std::string s ) {

    stage = s; 

    if ( s == "FRAGMENT" ) {
        setStats( 0, 8, 1 );
        name = "f_Monster";
    } else if ( s == "EGG" ) {
        setStats( 0, 5, 0 );
        name = "e_Monster";
    } else if ( s == "BABY" ) {
        setStats( 1, 12, 2 );
        name = "b_Monster";
    } else if ( s == "ADULT" ) {
        setStats( 2, 16, 4 );
        name = "a_Monster";
    }

}

void Monster::grow() { 

    if ( stage == "FRAGMENT" ) 
        setType( "BABY" );

    else if ( stage == "EGG" )
        setType( "BABY" );

    else if ( stage == "BABY" )
        setType( "ADULT" );

}

std::string Monster::getStage() {   return stage;   }