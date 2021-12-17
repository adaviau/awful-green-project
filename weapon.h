#ifndef WEAPON_H
#define WEAPON_H

#include <string>

#include "map.h"
#include "entity.h"

class Weapon : public Entity {

private:
    bool held;
    bool deployable;
    bool deployed;
    // WeaponEffect * effect;

public:
    Weapon( std::string );
    Weapon( std::string, Location& );

    void set_deployable();

    void grab();
    void drop( Location& );

    void deploy( Location& );

    bool isHeld();
    bool isDeployable();
    bool isDeployed();

    // void pickup( Actor& );
    // void discoverEffect( WeaponEffect& );

};

#endif