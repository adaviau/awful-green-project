#include <iostream>

#include "weapon.h"

Weapon::Weapon( std::string n ) : 
                    Entity( n, WEAPON ) {

    held = false;
    ranged = false;
    deployable = false;
    deployed = false;
    tested = false;
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

    std::cout << "DEBUG - is area effect weapon: " << has_area_of_effect << std::endl;
    has_area_of_effect = true; 
    std::cout << "DEBUG - set_area_of_effect: " << has_area_of_effect << std::endl;

}

void Weapon::set_expanding() { 

    std::cout << "DEBUG - has expansion properties:" << expands << std::endl;
    expands = true; 
    std::cout << "DEBUG - set_expanding: " << expands << std::endl;

}

void Weapon::set_single_use() { 

    std::cout << "DEBUG - has single-use properties:" << expands << std::endl;
    single_use = true; 
    std::cout << "DEBUG - set_single_use: " << expands << std::endl;

}

void Weapon::set_respawning() { 

    std::cout << "DEBUG - has respawns:" << respawning << std::endl;
    respawning = true; 
    std::cout << "DEBUG - set_respawning: " << respawning << std::endl;

}

void Weapon::set_respawn_location( Location& l ) { 

    respawn_location = &l;

}


void Weapon::repawn() {

    std::cout << "STATE- Weapon(" << getName() << ", " << getID() << " respawned at ";
    enter( *respawn_location );
    std::cout << location->getName() << std::endl;

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

void Weapon::set_regular_effect( Effect& e ) {

    if ( regular_effect ) {
        std::cout << "ERROR: Weapon already has assignment" << std::endl; 
        return;
    }
    regular_effect = &e;

}

void Weapon::assign_effect( Effect& e ) {
    
    if ( monster_effect ) {
        std::cout << "ERROR: Weapon already has assignment" << std::endl; 
        return;
    }
    monster_effect = &e;
    e.set_unavailable();
    tested = true;
    
}

void Weapon::remove_effect( ) {    
    
    monster_effect->set_available();
    monster_effect = nullptr;
    tested = false;
    
}


bool Weapon::isTested() { return tested; };

Effect * Weapon::get_regular_effect( ) {  return regular_effect;   }

Effect * Weapon::get_monster_effect( ) {  return monster_effect;   }

bool Weapon::isHeld() {     return held;   }

bool Weapon::isRanged() {   return ranged;  }

bool Weapon::isDeployable() {     return deployable;   }

bool Weapon::isDeployed() {     return deployed;   }

bool Weapon::isSingleUse() {   return single_use;  }

bool Weapon::isRespawning() {   return respawning;  }

bool Weapon::hasAreaEffect() {  return has_area_of_effect;  }

bool Weapon::hasExpandingEffect() {  return expands;  }


// void Weapon::pickup( Actor& a ) {
//     onGround = false;
//     location = &a.getLocation();
//     wielder = &a;
// }

// void Weapon::discoverEffect( WeaponEffect& e ) {
//     effect = &e;
// }