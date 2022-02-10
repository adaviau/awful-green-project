#ifndef WEAPON_H
#define WEAPON_H

#include <string>

#include "map.h"
#include "entity.h"

class Weapon : public Entity {

private:
    bool held;
    bool deployable;
    bool has_area_of_effect;
    bool deployed;
    bool ranged;
    // WeaponEffect * effect;

public:
    Weapon( std::string );
    Weapon( std::string, Location& );

    void set_deployable();
    void set_area_of_effect();
    void set_ranged();

    void grab();
    void drop( Location& );

    void deploy( Location& );

    bool isHeld();
    bool isDeployable();
    bool isDeployed();
    bool isRanged();
    bool hasAreaEffect();

    // void pickup( Actor& );
    // void discoverEffect( WeaponEffect& );

};

#endif