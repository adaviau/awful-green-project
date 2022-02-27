
#include "damage_profile.h"

DamageProfile::DamageProfile() {

    mt_rand = ActionGenerator::random_engine();
    init();
    area_effect = 0;
    expanded_effect = 0;

}

bool DamageProfile::has_area_effect() {

    return area_effect;

}
bool DamageProfile::has_expanded_effect() {

    return expanded_effect;

}

void DamageProfile::init() {

    damage_dir = 0;
    damage_loc = 0;
    damage_exp = 0;
    damage_loc_crew = 0;
    damage_exp_crew = 0;

    stun_dir = 0;
    stun_loc = 0;
    stun_exp = 0;
    stun_loc_crew = 0;
    stun_exp_crew = 0;

    grow_dir = 0;
    grow_loc = 0;
    grow_exp = 0;

    shrink_dir = 0;
    shrink_loc = 0;
    shrink_exp = 0;

    fragment_dir = 0;
    fragment_loc = 0;
    fragment_exp = 0;

}

void DamageProfile::roll() {

    init();

    damage_dir += roll_dice( hand_to_hand_strikes );

    for (int i=0; i<weapons_used.size(); ++i) {

        if ( weapons_used[i]->hasAreaEffect() )
            area_effect = true;
        if ( weapons_used[i]->hasExpandingEffect() )
            expanded_effect = true;

        Effect * effect = weapons_used[i]->get_monster_effect();
        Effect * crew_effect = weapons_used[i]->get_regular_effect();

        int roll_result = roll_dice( effect->get_dice_count() );

        if ( effect->is_kill_type() ) {

            if ( weapons_used[i]->hasAreaEffect() ) {
                damage_loc += roll_result;
                if ( weapons_used[i]->hasExpandingEffect() )
                    damage_exp += roll_result;
            } else {
                damage_dir += roll_result;
            }

        } else if ( effect->is_stun_type() ) {

            if ( weapons_used[i]->hasAreaEffect() ) {
                stun_loc += roll_result;
                if ( weapons_used[i]->hasExpandingEffect() )
                    stun_exp += roll_result;
            } else {
                stun_dir += roll_result;
            }

        } else if ( effect->is_grow_type() ) {

            if ( weapons_used[i]->hasAreaEffect() ) {
                grow_loc += 1;
                if ( weapons_used[i]->hasExpandingEffect() )
                    grow_exp += 1;
            } else {
                grow_dir += 1;
            }
        
        } else if ( effect->is_shrink_type() ) {

            if ( weapons_used[i]->hasAreaEffect() ) {
                shrink_loc += 1;
                if ( weapons_used[i]->hasExpandingEffect() )
                    shrink_exp += 1;
            } else {
                shrink_dir += 1;
            }
        
        } else if ( effect->is_frag_type() ) {

            if ( weapons_used[i]->hasAreaEffect() ) {
                fragment_loc += roll_result;
                if ( weapons_used[i]->hasExpandingEffect() )
                    fragment_exp += roll_result;
            } else {
                fragment_dir += roll_result;
            }

        }

        if ( crew_effect && crew_effect->is_kill_type() ) {

            if ( weapons_used[i]->hasAreaEffect() ) {
                damage_loc_crew += roll_result;
                if ( weapons_used[i]->hasExpandingEffect() )
                    damage_exp_crew += roll_result;
            } else {
                damage_dir += roll_result;
            }

        } else if ( crew_effect && crew_effect->is_stun_type() ) {

            if ( weapons_used[i]->hasAreaEffect() ) {
                stun_loc_crew += roll_result;
                if ( weapons_used[i]->hasExpandingEffect() )
                    damage_exp += roll_result;
            } else {
                stun_exp_crew += roll_result;
            }

        }

    }

}

int DamageProfile::roll_dice( int n ) {

    if ( n<1 )
        return 0;

    std::uniform_int_distribution<int> range( 1, 6 );
    return range( mt_rand ) + roll_dice( n-1 );

}