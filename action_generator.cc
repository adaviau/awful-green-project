
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

std::vector< Entity* > ActionGenerator::get_entities( ENTITY_TYPE t, Location& l, Map& m ) {

    std::vector< Entity* > output;

    for ( int i=0; i<l.occupents.size(); ++i ) {
        if ( l.occupents[i]->getType() == t )
            output.push_back( l.occupents[i] );
    }

    return output;

}

std::vector< Crew* > ActionGenerator::get_crew_targets( Location& l, Map& m ) {
    
    std::vector< Entity* > temp = get_entities( CREW, l, m );
    std::vector< Crew* > output;

    for ( int i=0; i<temp.size(); ++i )
        output.push_back( static_cast< Crew* >( temp[i] ) );

    return output;

}

std::vector< Monster* > ActionGenerator::get_monster_targets_near( Location& l, Map& m ) {
    
    std::vector< Entity* > temp = get_entities( MONSTER, l, m );
    std::vector< Monster* > output;

    for ( int i=0; i<temp.size(); ++i )
        output.push_back( static_cast< Monster* >( temp[i] ) );

    return output;

}

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

std::vector< Weapon* > ActionGenerator::get_weapons( Location& l, Map& m ) {

    std::vector< Entity* > temp = get_entities( WEAPON, l, m );
    std::vector< Weapon* > output;

    for ( int i=0; i<temp.size(); ++i )
        output.push_back( static_cast< Weapon* >( temp[i] ) );

    return output;

}

// Random Order Functions
std::vector< Crew* > ActionGenerator::shuffled_crew_list( Manifest& m ) {
    std::vector< Crew* > output;   
    
    for ( int i=0; i<m.size(); ++i ) {
        Crew * ptr = static_cast< Crew* >( &m[i] );
        if ( ptr->isActive() && !ptr->isStunned() )
            output.push_back( ptr );
    }
    std::shuffle( output.begin(), output.end(), random_engine() );

    return output;
}
std::vector< Monster* > ActionGenerator::shuffled_monster_list( Manifest& m ) {
    std::vector< Monster* > output; 
    
    for ( int i=0; i<m.size(); ++i ) {
        Monster * ptr = static_cast< Monster* >( &m[i] );
        if ( ptr->isActive() && !ptr->isStunned() )
            output.push_back( ptr );
    }
    if ( output.size() )
        std::shuffle( output.begin(), output.end(), random_engine() );

    // std::cout << "REACHED\n";
    return output;
}
std::vector< Location* > ActionGenerator::shuffled_location_list( Map& m ) {
    
    std::vector< Location* > output( m.size() ); 
    
    for ( int i=0; i<m.size(); ++i )
        output[i] = &m[i];
    std::shuffle( output.begin(), output.end(), random_engine() );

    return output;
}

std::mt19937 ActionGenerator::random_engine() {
    return std::mt19937( 
        std::chrono::high_resolution_clock::now().time_since_epoch().count() 
    );
}