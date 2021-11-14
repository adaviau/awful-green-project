#ifndef MAP_H
#define MAP_H

#include <vector>
#include <fstream>

#include "location.h"

class Map {

private:    
    std::vector< Location > locations;

public:
    Map();    

    int size();
    Location& getLocation( int );
    Location& operator[]( int );
    void add( Location& );
    std::vector<Location>& getLocations();

    void debug();

};

#endif