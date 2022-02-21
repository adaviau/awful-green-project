#ifndef ACTOR_H
#define ACTOR_H

#include <string>
#include "entity.h"

class Actor : public Entity {

private: 
    int movement;
    int strength;
    int constitution;

protected:
    bool stunned;
    bool alive;
    bool turn_used;

public:
    Actor( ENTITY_TYPE );
    Actor( std::string, ENTITY_TYPE );
    Actor( std::string, ENTITY_TYPE, Location& );

    void setStats( int, int, int );
    bool isStunned();
    bool isAlive();
    bool canAttack();
    bool canGrabWeapon();

    void stun();
    void wakeup();
    void kill();
    void complete_turn();
    void reset_turn();

    int getMovement();
    int getStrength();
    int getConstitution();

};

#endif
