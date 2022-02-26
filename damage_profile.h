#ifndef DAMAGE_PROFILE_H
#define DAMAGE_PROFILE_H

#include <vector>
#include "effect.h"
#include "weapon.h"

#include "action_generator.h"

class DamageProfile {

private:

    int roll_dice( int );
    std::mt19937 mt_rand;

public:

    DamageProfile();

    std::vector< Weapon* > weapons_used;

    int damage_dir;
    int damage_loc;
    int damage_exp;
    int damage_loc_crew;
    int damage_exp_crew;

    int stun_dir;
    int stun_loc;
    int stun_exp;
    int stun_loc_crew;
    int stun_exp_crew;

    int grow_dir;
    int grow_loc;
    int grow_exp;

    int shrink_dir;
    int shrink_loc;
    int shrink_exp;
    
    int fragment_dir;
    int fragment_loc;
    int fragment_exp;

    void roll();



};

#endif