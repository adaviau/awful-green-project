#ifndef MANIFEST_H
#define MANIFEST_H

#include <vector>
#include <fstream>

#include "actor.h"

class Manifest {

private:
    std::vector< Entity* > entities;

public:
    Manifest();

    int size();
    void add( Entity& );

    void remove( int );
    
    Entity& getEntity( int );
    Entity& operator[]( int );

    void debug();

};

#endif