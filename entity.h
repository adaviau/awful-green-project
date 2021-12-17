#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include "location.h"

enum ENTITY_TYPE { 
    INVALID,
    CREW,
    MONSTER,
    WEAPON,
    EQUIPEMENT,
    ESCAPE_POD
};

class Entity {

protected:
    int id;
    std::string name;
    ENTITY_TYPE type;
    Location * location;

public:
    Entity();
    Entity( std::string, ENTITY_TYPE );
    Entity( std::string, ENTITY_TYPE, Location& );

    int getID();
    void enter( Location& );
    void exit();

    Location * getLocation();
    std::string getName();
    ENTITY_TYPE getType();

};

#endif