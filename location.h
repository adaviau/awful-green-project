#ifndef LOCATION_H
#define LOCATION_H

#include <vector>
#include <string>
#include <algorithm>

class Entity;

class Location {

private:
    std::string name;

public:
    int id;
    int map_idx;

    std::vector< Entity* > occupents;

    Location();
    Location( std::string, int );
    Location( std::string, int, int );

    void enter( Entity& );

    int num_occupents();
    std::string getName();
    
};

#endif