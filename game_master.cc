#include <iostream>

#include "game_master.h"

GameMaster::GameMaster() : turn( 0 ), max_turns( 30 ) { }

void GameMaster::init() {

    mt_rand = ActionGenerator::random_engine();

    Initializer::buildMap( map );
    Initializer::buildCrew( crew );
    Initializer::buildMonsters( monsters );
    Initializer::buildWeapons( weapons );

    crew_placement();
    monster_placement();
    weapon_placement();

}

void GameMaster::crew_placement() { 

    crew[0].enter( map[0] );
    crew[1].enter( map[5] );
    crew[2].enter( map[3] );
    crew[3].enter( map[0] );

}
void GameMaster::monster_placement() {

    monsters[3].enter( map[8] );

}
void GameMaster::weapon_placement() {

    weapons[0].enter( map[1] );
    // weapons[3].enter( map[0] );
    Weapon * fence = static_cast< Weapon* >( &weapons[3] );
    std::cout << "is fence deployable " << fence->isDeployable() << std::endl;
    fence->deploy( map[8] );

}

void GameMaster::run() {

    crew_discovers_monsters();

    while ( ++turn <= max_turns ) {

        monster_turn();
        crew_turn();

    }

    std::cout << "Game ran for " << turn-1 << " turns." << std::endl;

}

void GameMaster::crew_turn() {

    // std::cout << "Turn " << turn << " - Crewmen" << std::endl;
    
    // std::cout << "--Pickup Phase" << std::endl;
    std::vector< Crew* > list = ActionGenerator::shuffled_crew_list( crew );
    // Grab Weapons
    for (auto it = list.begin(); it != list.end(); ++it) {
        // std::cout << (*it)->getName() << " didn't pickup a weapon." << std::endl;
    }
    // std::cout << "--Movement Phase" << std::endl;
    // Move
    list = ActionGenerator::shuffled_crew_list( crew );
    for (auto it = list.begin(); it != list.end(); ++it) {            
   
        // std::cout << (*it)->getName() << " can move " << (*it)->getMovement() << 
        //     " spaces" << std::endl;
  
        if ( (*it)->getLocation() ) {      
            std::vector< Location* > move_to = ActionGenerator::get_movement( *it, map );
            // std::cout << "DEBUG - Desination list is " << move_to.size() << " long." << std::endl;
            std::uniform_int_distribution<int> range( 0, move_to.size()-1 );
            (*it)->enter( *move_to[ range( mt_rand ) ] );
            std::cout << "Moved to " << (*it)->getLocation()->getName() << std::endl;
        }
    }

    // std::cout << "--Attack Phase" << std::endl;
    // Attack


    // std::cout << "--Wake Up Phase" << std::endl;
    // Wake Up



}

void GameMaster::monster_turn() {

    // std::cout << "Turn " << turn << " - Monsters" << std::endl;

    // Grow


    // Move


    // Attack


    // Wake Up


}

void GameMaster::crew_discovers_monsters() {

    std::cout << "Turn " << turn << " - Awful Green Things Discovered" << std::endl;
    // Move (1 or 2 crew up to allowed movement to discover monsters)
    // Attack (Hand to Hand only)

}