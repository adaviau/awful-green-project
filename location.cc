#include <iostream>

#include "location.h"
#include "entity.h"

static int UNIQUE_IDENTIFIER = 2000;

Location::Location() : Location( "invalid", -1 ) {  }

Location::Location( std::string n, int i ) {

    id = ++UNIQUE_IDENTIFIER;
    name = n;
    map_idx = i;

}

void Location::add_connection( int i ) {

    room_connections.push_back( i );
    room_connections.shrink_to_fit();

}
void Location::add_sightline( int i ) {

    room_sightlines.push_back( i );
    room_sightlines.shrink_to_fit();

}

bool Location::contains( Entity& e ) {

    if ( find_index( e ) >= 0 )
            return true;
    return false;

}

int Location::find_index( Entity& e ) {

    for ( int i=0; i<occupents.size(); ++i ) 
        if ( occupents[i]->getID() == e.getID() )
            return i;
    return -1;
    
}

Entity * Location::find_entity( Entity& e ) {

    int temp_idx = find_index( e );
    if ( temp_idx >= 0 )
        return occupents[temp_idx];
    return nullptr;

}

void Location::add_occupent( Entity& e ) { 

    // std::cout << "DEBUG - Entity[" << e.getName() << "]"
    //             << " wants to be added to the guest list " << name << std::endl;
    if ( contains( e ) ) {
        // std::cout << "DEBUG - Entity is already in occupent list.\n";
    } else {
        // std::cout << "DEBUG - Entity added to occupent list.\n";
        occupents.push_back( &e );
    }
    
}

void Location::remove_occupent( Entity& e ) { 

    // std::cout << "DEBUG - Entity[" << e.getName() << "]"
    //             << " wants to be removed from the guest list " << name << std::endl;
    int temp_index = find_index( e );
    if ( temp_index >= 0 ) {
        // std::cout << "DEBUG - Entity is on the list.\n";
        // std::cout << "DEBUG - Removing Entity from list.\n";
        std::iter_swap( occupents.begin()+temp_index, occupents.end()-1 );
        occupents.pop_back();
    } else {
        // std::cout << "DEBUG - Entity was not on the list.\n";
    }
    
}

int Location::num_occupents() { 
    return occupents.size();    
}
 
std::string Location::getName() {
    return name;
}
