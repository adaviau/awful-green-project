#include "attack_plan.h"

AttackPlan::AttackPlan( std::string n ) {

    name = n;

}

void AttackPlan::set_attack_team( std::vector< Actor* >& in_team ) {



}

void AttackPlan::set_target( std::vector< Actor* >& in_target ) {



}

int AttackPlan::calculate_attack_force( ) {

    return -1;
}

bool AttackPlan::team_has_area_effect_weapon( ) {

    return false;
}

std::string AttackPlan::perform_attack( ) {

    return "invalid_plan";
}