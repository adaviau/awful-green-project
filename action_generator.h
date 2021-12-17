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
    std::vector< Monster* > get_monster_targets_near( Location&, Map& );
    std::vector< Monster* > get_monster_targets_ranged( Location&, Map& );
    std::vector< Weapon* > get_weapons( Location&, Map& );

    // HELPERS
    std::vector< Entity* > get_entities( ENTITY_TYPE, Location&, Map& );

    // Random Order Functions
    std::vector< Crew* > shuffled_crew_list( Manifest& );
    std::vector< Monster* > shuffled_monster_list( Manifest& );
    std::vector< Location* > shuffled_location_list( Map& );

    std::mt19937 random_engine();

    // Growth Options
    std::vector< std::string > get_growth_options( Manifest& );

};

#endif