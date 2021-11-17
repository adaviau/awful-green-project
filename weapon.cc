#include "weapon.h"


Weapon::Weapon( std::string n ) : 
                    Entity( n, WEAPON ) {
    onGround = true;
    location = nullptr;
        
}

Weapon::Weapon( std::string n, Location& l ) : 
                    Entity( n, WEAPON, l ) {
    onGround = true;
        
}

bool Weapon::isHeld() {     return !onGround;   }

// void Weapon::drop(  ) {
//     onGround = true;
// }

// void Weapon::pickup( Actor& a ) {
//     onGround = false;
//     location = &a.getLocation();
//     wielder = &a;
// }

// void Weapon::discoverEffect( WeaponEffect& e ) {
//     effect = &e;
// }