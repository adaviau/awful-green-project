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
    std::vector<int> room_connections;
    std::vector<int> room_sightlines;

    Location();
    Location( std::string, int );
    Location( std::string, int, int );

    void add_connection( int );
    void add_sightline( int );

    void add_occupent( Entity& );
    void remove_occupent( Entity& );
    bool contains( Entity& );
    int find_index( Entity& );
    Entity * find_entity( Entity& );

    int num_occupents();
    std::string getName();
    
};

#endif