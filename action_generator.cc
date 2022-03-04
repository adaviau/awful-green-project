
#include <iostream>

#include "action_generator.h"

// Returns all locations that a Crew Member can go to
std::vector< Location* > 
    ActionGenerator::get_movement( Actor * a, Map& m ) {

    // std::cout << "DEBUG - get_movement called.\n";
    // std::cout << "DEBUG - Actor[" << a->getName() << ", " << 
        // a->getMovement() << "]\n";

    std::vector< Location* > output;
    output.resize( m.size() );

    // std::cout << "DEBUG - output arr starts at size: " << output.size() << ".\n";
    get_movement_range( a, a->getMovement(), *a->getLocation(), m, output );

    // condense output list
    int free_spot = 0;
    for ( int i=0; i<output.size(); ++i ) {
        if ( output[i] ) {

            if ( free_spot != i ) {

                output[free_spot] = output[i];
                output[i] = nullptr;

            }

            ++free_spot; 

        }
    }

    output.resize( free_spot );

    // std::cout << "DEBUG - Location List size: " << output.size() << ".\n";

    return output;

}

// Return movement range based on movement value
void ActionGenerator::get_movement_range( Actor * a, int depth, Location& l, 
                                Map& m, std::vector< Location * >& list ) {

    if ( !list[l.map_idx] ) {

        list[l.map_idx] = &l;

        // THIS PART NEEDS TO NOT ALLOW PROGRESSION FROM PLACES WITH HALTERS
        // ELECTRIC FENCES OR MONSTERS FOR CREWMEN

        if ( depth > 0 ) {

            std::vector< Location* > neighbors = 
                get_connected_locations( l, m );
 
            for ( int i=0; i<neighbors.size(); ++i )
                if ( ( !has_halting_entities( a->getType(), l, m ) ) || 
                     ( l.id == a->getLocation()->id ) ) {
                        // std::cout << "Eval as true\n";
                    get_movement_range( a, depth-1, m[ neighbors[i]->map_idx ], m, list );
                }
                
        }
    }
}

// Returns all the directly connected Locations of another Location
std::vector< Location* > 
    ActionGenerator::get_connected_locations( Location& l, Map& m ) {

    std::vector< Location* > output;

    for ( int i=0; i<l.room_connections.size(); ++i ) 
        output.push_back( &m[ l.room_connections[i] ] );

    return output;

}

// Returns all the line of sight locations of a Location.
std::vector< Location* >
    ActionGenerator::get_line_of_sight_locations( Location& l, Map& m ) {

    std::vector< Location* > output = get_connected_locations( l, m );

    for ( int i=0; i<l.room_sightlines.size(); ++i ) 
        output.push_back( &m[ l.room_sightlines[i] ] );

    return output;

}

// Return all the exansion locations for expanding weapons.
std::vector< Location* >
    ActionGenerator::get_expansion_locations( Location& l, Map& m ) {

    std::vector< Location* > output;

    for ( int i=0; i<l.room_expansions.size(); ++i ) 
        output.push_back( &m[ l.room_expansions[i] ] );

    return output;

}

// Check if a location has a halting entity
bool ActionGenerator::has_halting_entities( ENTITY_TYPE t, Location& l, Map& m ) {

    std::vector< Weapon* > list = get_weapons( l, m );
    for ( auto it = list.begin(); it != list.end(); ++it ) 
        if ( (*it)->isDeployed() )
            return true;

    if ( t == CREW ) {

        std::vector< Monster* > list = get_monster_targets_near( l, m );
        for ( auto it = list.begin(); it != list.end(); ++it ) 
            if (    !(*it)->isStunned() && 
                    (*it)->getStage() == "ADULT" || 
                    (*it)->getStage() == "BABY" )
                return true;

    } else if ( t == MONSTER ) {

        std::vector< Crew* > list = get_crew_targets( l, m );
        // std::cout << "DEBUG - Crew list is " << list.size() << " long.\n"; 
        for ( auto it = list.begin(); it != list.end(); ++it ) 
            if ( !(*it)->isStunned() )
                return true;

    }

    return false;

}

// Get All Entities in a location
std::vector< Entity* > ActionGenerator::get_entities( ENTITY_TYPE t, Location& l, Map& m ) {

    std::vector< Entity* > output;

    for ( int i=0; i<l.occupents.size(); ++i ) {
        if ( l.occupents[i]->getType() == t )
            output.push_back( l.occupents[i] );
    }

    return output;

}
/* TARGETTING FUNCTIONS
 * 
 */
// Get Crew Targets
std::vector< Crew* > ActionGenerator::get_crew_targets( Location& l, Map& m ) {
    
    std::vector< Entity* > temp = get_entities( CREW, l, m );
    std::vector< Crew* > output;

    for ( int i=0; i<temp.size(); ++i )
        if ( static_cast< Crew* >( temp[i] )->isAlive() ) 
            output.push_back( static_cast< Crew* >( temp[i] ) );

    return output;

}

std::vector< Crew* > ActionGenerator::get_armed_crew_except_self( Crew * c, 
                                Location& l, Map& m ) {

    std::vector< Entity* > temp = get_entities( CREW, l, m );
    std::vector< Crew* > output;

    // std::cout << "DEBUG--AG-- Num crew entities in location: " << temp.size() << std::endl;

    for ( int i=0; i<temp.size(); ++i )
        if ( c->getID() != temp[i]->getID() ) 
            if ( static_cast< Crew* >( temp[i] )->hasWeapon() )
                output.push_back( static_cast< Crew* >( temp[i] ) );
        
    return output;

}
// Get Armed Crew Nearby
std::vector< Crew* > ActionGenerator::get_armed_crew( Location& l, Map& m ) {

    std::vector< Crew* > nearby_crew = get_crew_targets( l, m );
    std::vector< Crew* > output;

    for ( int i=0; i<nearby_crew.size(); ++i )
        if ( nearby_crew[i]->hasWeapon() )
            output.push_back( static_cast< Crew* >( nearby_crew[i] ) );

    return output;

}

// Get Near Monster Targets
std::vector< Monster* > ActionGenerator::get_monster_targets_near( Location& l, Map& m ) {
    
    std::vector< Entity* > temp = get_entities( MONSTER, l, m );
    std::vector< Monster* > output;

    for ( int i=0; i<temp.size(); ++i )
        if ( static_cast< Monster* >( temp[i] )->isAlive() ) 
            output.push_back( static_cast< Monster* >( temp[i] ) );

    return output;

}

// Get Ranged Monster Targets
std::vector< Monster* > ActionGenerator::get_monster_targets_ranged( Location& l, Map& m ) {
    
    // std::cout << "Get Monster Ranged"
    std::vector< Monster* > output = get_monster_targets_near( l, m );
    std::vector< Location* > sightlines = get_line_of_sight_locations( l, m );

    for ( int s=0; s<sightlines.size(); ++s ) {

        std::vector< Entity* > temp = get_entities( MONSTER, *sightlines[s], m );
        for ( int i=0; i<temp.size(); ++i )
            output.push_back( static_cast< Monster* >( temp[i] ) );

    }

    return output;

}



std::vector< Entity* > ActionGenerator::collateral_damage_local( Actor& a, Map& m ) {

    std::vector< Entity* > output = collateral_damage_local( *a.getLocation(), m );

    for ( int i=0; i<output.size(); ++i ) {

        if ( a.getID() == output[i]->getID() ) {

            // Swap and drop
            output[i] = output[ output.size()-1 ];
            output.pop_back();
            break;

        }

    }

    return output;
    
}

std::vector< Entity* > ActionGenerator::collateral_damage_local( Location& l, Map& m ) {

    std::vector< Entity* > output;

    std::vector< Entity* > crew = get_entities( CREW, l, m );
    std::vector< Entity* > monsters = get_entities( MONSTER, l, m );

    output.insert( output.end(), crew.begin(), crew.end() );
    output.insert( output.end(), monsters.begin(), monsters.end() );

    return output;

}
std::vector< Entity* > ActionGenerator::collateral_damage_expanded( Location& l, Map& m ) {

    std::vector< Entity* > output;

    std::vector< Location* > locations = get_expansion_locations( l, m );

    for ( int i=0; i<locations.size(); ++i ) {

        std::vector< Entity* > temp = collateral_damage_local( *locations[i], m );
        output.insert( output.end(), temp.begin(), temp.end() );

    }

    return output;

}


// Get Weapons at a location
std::vector< Weapon* > ActionGenerator::get_weapons( Location& l, Map& m ) {

    std::vector< Entity* > temp = get_entities( WEAPON, l, m );
    std::vector< Weapon* > output;

    for ( int i=0; i<temp.size(); ++i )
        output.push_back( static_cast< Weapon* >( temp[i] ) );

    return output;

}

/* RANDOM ORDERINGS FUNCTIONS
 * 
 */
// Crew Shuffler
std::vector< Crew* > ActionGenerator::shuffled_crew_list( Manifest& m ) {
    std::vector< Crew* > output;   
    
    for ( int i=0; i<m.size(); ++i ) {
        Crew * ptr = static_cast< Crew* >( &m[i] );
        if ( ptr->isAlive() && !ptr->isStunned() )
            output.push_back( ptr );
    }
    std::shuffle( output.begin(), output.end(), random_engine() );

    return output;
}
// Monster Shuffler
std::vector< Monster* > ActionGenerator::shuffled_monster_list( Manifest& m ) {
    std::vector< Monster* > output; 
    
    for ( int i=0; i<m.size(); ++i ) {
        Monster * ptr = static_cast< Monster* >( &m[i] );
        if ( ptr->isAlive() && !ptr->isStunned() )
            output.push_back( ptr );
    }
    if ( output.size() )
        std::shuffle( output.begin(), output.end(), random_engine() );

    // std::cout << "REACHED\n";
    return output;
    
}
// Location Shuffler
std::vector< Location* > ActionGenerator::shuffled_location_list( Map& m ) {
    
    std::vector< Location* > output( m.size() ); 
    
    for ( int i=0; i<m.size(); ++i )
        output[i] = &m[i];
    std::shuffle( output.begin(), output.end(), random_engine() );

    return output;

}

/* ATTACKING FUNCTIONS
 *
 *
 */
std::vector< Crew* > 
    ActionGenerator::crew_that_can_attack( Location& l, Manifest& manifest ) {

    // std::cout << "VERBOSE-- finding crew that can attack location " << 
    //     l.getName() << std::endl;

    std::vector< Crew* > active = shuffled_crew_list( manifest );
    std::vector< Crew* > output;

    for ( int i=0; i<active.size(); ++i ) {

        if ( !active[i]->canAttack() ) { 
            // std::cout << "VERBOSE- crew[" << active[i]->getName() << "] cannot attack."
            //             << std::endl;
            continue;
        }

        int crew_map_idx = active[i]->getLocation()->map_idx;

        if ( crew_map_idx == l.map_idx ) {
            output.push_back( active[i] );
            // std::cout << "VERBOSE- crew[" << active[i]->getName() << "] is located in same place as target."
            //             << std::endl;
            continue;
        } else {
            // std::cout << "VERBOSE- crew[" << active[i]->getName() << "] is not in the same place as target."
            //             << std::endl;
        }
        if ( active[i]->hasWeapon() && active[i]->getWeapon()->isRanged() ) {
            // std::cout << "VERBOSE- crew[" << active[i]->getName() << "] has a ranged weapon.";
                        
            bool had_sightline_debug_flag = false;

            // std::cout << "    Sightlines: ";
            // for ( auto ids: l.room_sightlines )
            //     std::cout << ids << ' ';
            // std::cout << " : CrewMapIDX: " << crew_map_idx << std::endl;

            for ( int j=0; j<l.room_sightlines.size(); ++j ) {

                if ( crew_map_idx == l.room_sightlines[j] ) {
                    output.push_back( active[i] );
                    // std::cout << " And has line of sight to target." << std::endl;
                    had_sightline_debug_flag = true;
                    break;
                }

            }

            // if ( had_sightline_debug_flag == false )
            //     std::cout << " But no line of sight." << std::endl;

        }

    }

    // std::cout << "VERBOSE-- found " << output.size() << " crew can attack location " << 
    //     l.getName() << std::endl;

    return output;

}
std::vector< Monster* > 
    ActionGenerator::monsters_that_can_attack( Location& l, Manifest& manifest ) {

    std::vector< Monster* > active = shuffled_monster_list( manifest );
    std::vector< Monster* > output;

    for ( int i=0; i<active.size(); ++i ) 
        if ( active[i]->canAttack() && active[i]->getLocation()->id == l.id ) 
            output.push_back( active[i] );

    // std::cout << "DEBUG-- " << output.size() << " monsters can attack location " << 
    //     l.getName() << std::endl;

    return output;

}

std::vector< Monster* > 
    ActionGenerator::get_monsters_of_stage( std::string stage, Manifest& m ) { 

    std::vector< Monster* > active = shuffled_monster_list( m );
    std::vector< Monster* > output;

    for ( int i=0; i<active.size(); ++i ) 
        if ( active[i]->getStage() == stage ) 
            output.push_back( active[i] );

    return output;

}


Effect * ActionGenerator::get_available_effect( std::vector< Effect* >& m ) { 

    std::shuffle( m.begin(), m.end(), random_engine() );
    for (int i=0; i<m.size(); ++i)
        if ( m[i]->is_available() )
            return m[i];

    return nullptr;

}

// Determines which Monsters are available to grow
// does not take into consideration type maximums
std::vector< std::string > ActionGenerator::get_growth_options( Manifest& m ) {

    std::vector< Monster* > active = shuffled_monster_list( m );
    std::vector< std::string > output;

    bool flag_fragment = false;
    bool flag_egg = false;
    bool flag_baby = false;
    bool flag_adult = false;

    for ( int i=0; i<active.size(); ++i ) {
        std::string cursor_stage = static_cast< Monster* >( &m[i] )->getStage();
        if ( !flag_fragment && cursor_stage == "FRAGMENT" ) {

            output.push_back( "FRAGMENT" ); 
            flag_fragment = true;

        } else if ( !flag_egg && cursor_stage == "EGG" ) {

            output.push_back( "EGG" ); 
            flag_egg = true;

        } else if ( !flag_baby && cursor_stage == "BABY" ) {

            output.push_back( "BABY" ); 
            flag_baby = true;

        } else if ( !flag_adult && cursor_stage == "ADULT" ) {

            output.push_back( "ADULT" ); 
            flag_adult = true;

        }
    }

    // std::cout << "REACHED\n";
    std::shuffle( output.begin(), output.end(), random_engine() );
    return output;

}










// Randomizer function
std::mt19937 ActionGenerator::random_engine() {
    return std::mt19937( 
        std::chrono::high_resolution_clock::now().time_since_epoch().count() 
    );
}