#ifndef ACTOR_H
#define ACTOR_H

#include <string>
#include "entity.h"

class Actor : public Entity {

private: 
    int movement;
    int strength;
    int constitution;
    bool stunned;

public:
    Actor( ENTITY_TYPE );
    Actor( std::string, ENTITY_TYPE );
    Actor( std::string, ENTITY_TYPE, Location& );

    void setStats( int, int, int );
    bool isStunned();

};

#endif
