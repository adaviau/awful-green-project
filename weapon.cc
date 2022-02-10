#include <iostream>

#include "weapon.h"

Weapon::Weapon( std::string n ) : 
                    Entity( n, WEAPON ) {
    held = false;
    ranged = false;
    deployable = false;
    deployed = false;
    location = nullptr;
        
}

Weapon::Weapon( std::string n, Location& l ) : 
                    Weapon( n ) {

    location = &l;
        
}
void Weapon::set_ranged() { 
    ranged = true; 
}

void Weapon::set_deployable() { 

    std::cout << "DEBUG - " << deployable << std::endl;
    deployable = true; 
    std::cout << "DEBUG - set_deployable: " << deployable << std::endl;

}

void Weapon::set_area_of_effect() { 

    std::cout << "DEBUG - " << has_area_of_effect << std::endl;
    has_area_of_effect = true; 
    std::cout << "DEBUG - set_deployable: " << has_area_of_effect << std::endl;

}

void Weapon::grab() {

    exit();
    held = true;

}

void Weapon::drop( Location& l ) {

    std::cout << l.getName();
    enter( l );
    held = false;

}

void Weapon::deploy( Location& l ) {     

    if ( deployable ) 
        deployed = true;
    drop( l );

}

bool Weapon::isHeld() {     return held;   }

bool Weapon::isRanged() {   return ranged;  }

bool Weapon::isDeployable() {     return deployable;   }

bool Weapon::isDeployed() {     return deployed;   }

bool Weapon::hasAreaEffect() {  return has_area_of_effect;  }


// void Weapon::pickup( Actor& a ) {
//     onGround = false;
//     location = &a.getLocation();
//     wielder = &a;
// }

// void Weapon::discoverEffect( WeaponEffect& e ) {
//     effect = &e;
// }