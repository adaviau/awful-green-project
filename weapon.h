#ifndef WEAPON_H
#define WEAPON_H

#include <string>

#include "map.h"
#include "entity.h"

class Weapon : public Entity {

private:
    bool onGround;
    // WeaponEffect * effect;

public:
    Weapon( std::string );
    Weapon( std::string, Location& );

    // void pickup( Actor& );
    // void discoverEffect( WeaponEffect& );
    bool isHeld();

};

#endif