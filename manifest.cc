
#include <iostream>

#include "manifest.h"

Manifest::Manifest() { }

int Manifest::size() {   return entities.size();    }

void Manifest::add( Entity& e ) {   
    
    entities.push_back( &e );  
    
}

Entity& Manifest::getEntity( int idx ) { return *entities[idx]; } 

Entity& Manifest::operator[]( int index ) {

    if ( index >= size() ) {
        std::cerr << "Array index out of bound, exiting";
        exit(0);
    }
    return *entities[index];

}

void Manifest::debug() {

    std::cout << "\nMANIFEST DEBUG - Size: " << size() << "\n";
    for (int i=0; i<size(); ++i) {

        std::cout << "Entity[" << entities[i]->getName() << ", addr:"  
                            << &entities[i] << ", Location: " ;
        Location * loc_ptr = entities[i]->getLocation();
        if ( loc_ptr )
            std::cout << loc_ptr->getName() << ", addr:" << loc_ptr;
        else
            std::cout << "NULL_SPACE";
        std::cout << "]" << std::endl;

    }

}