#ifndef ACTION_GENERATOR_H
#define ACTION_GENERATOR_H

#include <vector>
#include <stack>
#include <random>
#include <algorithm>

#include "manifest.h"
#include "map.h"
#include "crew.h"
#include "monster.h"

namespace ActionGenerator {

    // Movement Related Functions
    std::vector< Location* > get_movement( Actor*, Map& );
    std::vector< Location* > get_connected_locations( Location&, Map& );
    std::vector< Location* > get_line_of_sight_locations( Location&, Map& );

    // HELPERS    
    bool has_halting_entities( ENTITY_TYPE, Location&, Map& );
    void get_movement_range( Actor*, int, Location&, Map&, std::vector< Location* >& );

    // Entity Targeting Related Functions
    std::vector< Crew* > get_crew_targets( Location&, Map& );
    std::vector< Crew* > get_armed_crew( Location&, Map& );
    std::vector< Crew* > get_armed_crew_except_self( Crew*, Location&, Map& );
    std::vector< Monster* > get_monster_targets_near( Location&, Map& );
    std::vector< Monster* > get_monster_targets_ranged( Location&, Map& );
    // std::vector< Weapon* > get_grabbable_weapons( Crew&, Location&, Map& );
    std::vector< Weapon* > get_weapons( Location&, Map& );

    // HELPERS
    std::vector< Entity* > get_entities( ENTITY_TYPE, Location&, Map& );
    
    // Random Order Functions
    std::vector< Crew* > shuffled_crew_list( Manifest& );
    std::vector< Monster* > shuffled_monster_list( Manifest& );
    std::vector< Location* > shuffled_location_list( Map& );

    std::vector< Crew* > crew_that_can_attack( Location&, Manifest& );
    std::vector< Monster* > monsters_that_can_attack( Location&, Manifest& );

    void get_crew_attack_options( );
    std::vector< Crew* > create_attack_parties( );
    std::vector< Actor* > get_location_attackers( ENTITY_TYPE, Location&, Manifest& );

    std::mt19937 random_engine();

    // Growth Options
    std::vector< std::string > get_growth_options( Manifest& );
    Effect * get_available_effect( std::vector< Effect* >& );



};

#endif