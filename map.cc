#include <iostream>

#include "map.h"

Map::Map() { }

int Map::size() {   return locations.size();    }

Location& Map::getLocation( int idx ) { return locations[idx]; } 

Location& Map::operator[]( int index ) {

    if ( index >= size() ) {
        std::cerr << "Array index out of bound, exiting";
        exit(0);
    }
    return locations[index];

}

void Map::add( Location& l ) { locations.push_back( l ); }

std::vector<Location>& Map::getLocations() {   return locations;   }

void Map::debug() {

    std::cout << "MAP DEBUG - Size: " << size() << "\n";
    for (int i=0; i<size(); ++i) {

        int occupent_count = locations[i].num_occupents();

        std::cout << "Map[" << locations[i].getName() << ", addr:"  
                            << &locations[i] 
                            << ", Occupents: " << occupent_count
                            << "]" << std::endl;

        for (int k=0; k<occupent_count; ++k) 
            std::cout << "   Entity[" << locations[i].occupents[k];
        if ( occupent_count )
            std::cout << "]" << std::endl;

    }

}