#include <iostream>

#include "location.h"
#include "entity.h"

Location::Location() : Location( "invalid", -1 ) {}

Location::Location( std::string n, int i ) {

    name = n;
    map_idx = i;

}

void Location::enter( Entity& e ) { 
    occupents.push_back( &e );
}

int Location::num_occupents() { 
    return occupents.size();    
}
 
std::string Location::getName() {
    return name;
}
