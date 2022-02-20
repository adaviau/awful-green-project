#ifndef WEAPON_H
#define WEAPON_H

#include <string>

#include "map.h"
#include "entity.h"
#include "effect.h"

class Weapon : public Entity {

private:
    bool held;
    bool deployable;
    bool has_area_of_effect;
    bool expands;
    bool deployed;
    bool ranged;
    bool tested;
    Effect * regular_effect;
    Effect * monster_effect;

public:
    Weapon( std::string );
    Weapon( std::string, Location& );

    void set_deployable();
    void set_area_of_effect();
    void set_expanding();
    void set_ranged();

    void grab();
    void drop( Location& );

    void deploy( Location& );

    bool isHeld();
    bool isDeployable();
    bool isDeployed();
    bool isRanged();
    bool hasAreaEffect();
    bool hasExpandingEffect();

    bool isTested( );
    void assign_effect( Effect& );
    void remove_effect( );

    Effect * get_regular_effect( );    
    Effect * get_monster_effect( );

};

#endif