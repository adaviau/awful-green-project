#ifndef ATTACK_PLAN_H
#define ATTACK_PLAN_H

#include <string>
#include "actor.h"

class AttackPlan {

private:

    std::string name;
    int id;
    
    std::vector< Actor* > attack_team;
    std::vector< Actor* > target;

public:

    AttackPlan( std::string );

    void set_attack_team( std::vector< Actor* >& );
    void set_target( std::vector< Actor* >& );

    int calculate_attack_force( );
    bool team_has_area_effect_weapon( );

    std::string perform_attack( );

};

#   endif