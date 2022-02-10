#include <iostream>

#include "game_master.h"

GameMaster::GameMaster() : turn( 0 ), max_turns( 500 ) { }

GameMaster::GameMaster( int turn_option ) : turn( 0 ), max_turns( turn_option ) { }

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
    crew[1].enter( map[2] );
    crew[2].enter( map[4] );
    crew[3].enter( map[1] );

}
void GameMaster::monster_placement() {

    monsters[3].enter( map[0] );
    monsters[0].enter( map[1] );
    monsters[1].enter( map[5] );
    monsters[2].enter( map[4] );

}
void GameMaster::weapon_placement() {

    weapons[0].enter( map[1] );
    weapons[1].enter( map[4] );
    weapons[2].enter( map[4] );
    weapons[3].enter( map[0] );
    weapons[4].enter( map[0] );
    Weapon * fence = static_cast< Weapon* >( &weapons[3] );
    // std::cout << "is fence deployable " << fence->isDeployable() << std::endl;
    // fence->deploy( map[8] );

}

void GameMaster::run_design() {

    crew_discovers_monsters();

    monster_turn();

    Crew *andrew = static_cast< Crew* >( &crew[0] );
    Weapon *pool_queue = static_cast< Weapon* >( &weapons[4] );

    std::vector< Location* > move_to = ActionGenerator::get_movement( andrew, map );
    std::cout << "Move option " << move_to.size() << std::endl;
    
    // check for available weapons
    std::vector< Weapon* > weps = ActionGenerator::get_weapons( *andrew->getLocation(), map );
    std::cout << "weapon option " << weps.size() << std::endl;
    std::vector< Crew* > held_weps = ActionGenerator::get_armed_crew( *andrew->getLocation(), map );
    weps = ActionGenerator::get_weapons( *andrew->getLocation(), map );
    std::cout << "held weapon options " << held_weps.size() << std::endl;

    andrew->grab( *pool_queue );
    
    // check for available weapons
    weps = ActionGenerator::get_weapons( *andrew->getLocation(), map );
    std::cout << "weapon options " << weps.size() << std::endl;
    held_weps = ActionGenerator::get_armed_crew( *andrew->getLocation(), map );
    weps = ActionGenerator::get_weapons( *andrew->getLocation(), map );
    std::cout << "held weapon options " << held_weps.size() << std::endl;

    std::cout << "Game ran designed simulation." << std::endl;

}

void GameMaster::run() {

    crew_discovers_monsters();

    while ( ++turn <= max_turns ) {

        monster_turn();
        crew_turn();

        if ( check_win_conditions() )
            break;

    }

    std::cout << "Game ran for " << turn-1 << " turns." << std::endl;

}

void GameMaster::crew_turn() {

    // GRAB, MOVE, ATTACK, WAKE

    std::cout << "\nTurn " << turn << " ------------- CREWMEN" << std::endl;
    
    std::cout << "\n******** PICKUP PHASE ******" << std::endl;
    std::vector< Crew* > list = ActionGenerator::shuffled_crew_list( crew );

    // weapons.debug();
    // crew.debug();

    // Grab Weapons
    for (auto it = list.begin(); it != list.end(); ++it) {

        if ( (*it)->canGrabWeapon() ) {
            std::cout << "DEBUG-- " << (*it)->getName() << " can grab weapon." << std::endl;
        } else {
            std::cout << "DEBUG-- " << (*it)->getName() << " can grab weapon." << std::endl;
            continue;
        }

        int option_count = 1;

        if ( (*it)->hasWeapon() ) {
            std::cout << "DEBUG-- " << (*it)->getName() << " is armed: " << std::endl;
            ++option_count;
        } else {
            std::cout << "DEBUG-- " << (*it)->getName() << " is unarmed: " << std::endl;
        }

        Location *crew_location = (*it)->getLocation();

        // NEED TO BUILD PICKUP OF DEPLOYED WEAPONS

        std::vector< Weapon* > ground_weapons = ActionGenerator::get_weapons( *crew_location, map );
        std::vector< Crew* > trade_options = 
            ActionGenerator::get_armed_crew_except_self( *it, *crew_location, map );

        std::cout << "DEBUG-- ground size: " << ground_weapons.size() << std::endl;        
        std::cout << "DEBUG-- tradable size: " << trade_options.size() << std::endl;
        option_count += ground_weapons.size();

        option_count += trade_options.size();


        std::cout << "There are " << option_count << " weapon action(s) to choose.";
        std::uniform_int_distribution<int> range( 0, option_count-1 );
        int action_choice = range( mt_rand );
        std::cout << " Selecting weapon option: " << action_choice << std::endl;

        if ( action_choice == 0 ) {
            // Do Nothing
            std::cout << "DEBUG-- No weapon action" << std::endl;
            continue;
        }
        if ( (*it)->hasWeapon() && action_choice == 1 ) {
            // Drop Weapon
            std::cout << "DEBUG-- Weapon dropped" << std::endl;
            (*it)->drop();
            continue;
        }
        --action_choice; // decrement for choice indexing
        if ( (*it)->hasWeapon() ) {
            (*it)->drop(); // drop weapon 
            --action_choice;
        }

        if ( action_choice < ground_weapons.size() ) {
            std::cout << "DEBUG-- Grabbing ground weapon" << std::endl;
            (*it)->grab( *ground_weapons[action_choice] );
            continue;
        }

        // std::cout << "The trading area is REACHED!\n";

        action_choice -= ground_weapons.size();

        // std::cout << "DEBUG-- Array sizes " << action_choice << " : " << trade_options.size() <<
        //     std::endl;

        // std::cout << "Trying to get Weapon Reference from other guy!\n";
        Weapon * weapon_to_steal = trade_options[action_choice]->getWeapon();
        // std::cout << "Got Ref I guess...! " << weapon_to_steal->getID() << "\n";
        trade_options[action_choice]->drop();
        // std::cout << "Make him drop the weapon!\n";

        std::cout << "DEBUG-- Grab held weapon" << std::endl;
        (*it)->grab( *weapon_to_steal );

    }
    
    std::cout << "\n****** MOVEMENT PHASE ******" << std::endl;
    // Move
    for (auto it = list.begin(); it != list.end(); ++it) {            
  
        if ( (*it)->getLocation() ) {      
            std::vector< Location* > move_to = ActionGenerator::get_movement( *it, map );
            
            std::uniform_int_distribution<int> range( 0, move_to.size()-1 );
            (*it)->enter( *move_to[ range( mt_rand ) ] );
            std::cout << (*it)->getName() << "(" << (*it)->getID() << ")";
            std::cout << " moved to " << (*it)->getLocation()->getName() << std::endl;

        }
    }

    
    std::cout << "\n****** ATTACK PHASE ******" << std::endl;
    crew.debug();
    monsters.debug();
    map.debug();
    std::cout << "**************************" << std::endl;
    // Attack
    std::vector< Location* > location_list = ActionGenerator::shuffled_location_list( map );

    // weapons.debug();
    // crew.debug();
    for (auto it = location_list.begin(); it != location_list.end(); ++it) {

        // GET TARGET LIST AT LOCATION
        std::vector< Monster* > targets = ActionGenerator::get_monster_targets_near( **it, map );

        // GET ALL CREW THAT CAN ATTACK HERE
        std::vector< Crew* > attackers = ActionGenerator::crew_that_can_attack( **it, crew );

        std::cout << "DEBUG-- " << "There are " << targets.size() << " target(s) and " << 
            attackers.size() << " attacker(s)" << " in the " << (*it)->getName() << std::endl;  
        
        // DEAL WITH TARGETS ONE AT A TIME
        for (int i=0; i<targets.size() && attackers.size()>0; ++i) {

            // GENERATE ATTACK TEAMS
            std::uniform_int_distribution<int> range( 0, attackers.size() );
            int team_size = range( mt_rand );

            if ( team_size == 0 ) {
                std::cout << "DEBUG-- " << "No Attack team for this enemy." << std::endl;
                continue;
            }


            std::cout << "DEBUG-- " << "Building attack team of size " << team_size <<
                " from " << attackers.size() << " available attackers." << std::endl;

            std::vector< Crew* > attack_team;
            for (int j=0; j<team_size; ++j) {
                attack_team.push_back( attackers[attackers.size()-1 ] );
                attackers.pop_back();
            }
            std::cout << "DEBUG-- " << "Team attacking " << targets[i]->getName() << 
                " is of size " << attack_team.size() << std::endl;
            
            // CALCULATE DAMAGES FROM ATTACK TEAM
            int directed_damage = 0;
            int splash_damage = 0;

            for (int i=0; i<team_size; ++i) {

                if ( attack_team[i]->hasWeapon() ) {

                    std::uniform_int_distribution<int> range( 0, 1 );
                    int use_weapon_choice = range( mt_rand );

                    if ( use_weapon_choice == 0 ) {

                        directed_damage += attack_team[i]->getStrength();

                    } else {

                        Weapon * attacker_weapon = attack_team[i]->getWeapon();
                        std::cout << "DEBUG-- Attacker USES " << attacker_weapon->getName() << 
                            std::endl;
                        
                        if ( attacker_weapon->isDeployable() ) {
                            attacker_weapon->deploy( **it );
                        }

                        if ( attacker_weapon->hasAreaEffect() )
                            splash_damage += 15;
                        else
                            directed_damage += 10;

                    }

                } else {

                    directed_damage += attack_team[i]->getStrength();

                }

                attack_team[i]->complete_turn();

            }

            std::cout << "DEBUG-- Attack Team deals " << directed_damage << " directed damage." << std::endl; 
            std::cout << "DEBUG-- Attack Team deals " << splash_damage << " splash damage." << std::endl; 

            // PERFORM THE ATTACK
            if ( (directed_damage + splash_damage) >= targets[i]->getConstitution() ) 
                targets[i]->kill();

        }
            // RANDOMIZE TEAM SIZE
            // MAKE TEAM FROM LAST 



    }

                    // for (auto it = list.begin(); it != list.end(); ++it) {

                    //     std::vector< Monster* > attack_options;
                    //     Location *crew_location = (*it)->getLocation();

                    //     // Get the attack options
                    //     if ( (*it)->hasWeapon() && (*it)->getWeapon()->isRanged() )
                    //         attack_options = ActionGenerator::get_monster_targets_ranged( *crew_location, map );
                    //     else
                    //         attack_options = ActionGenerator::get_monster_targets_near( *crew_location, map );
                        
                    //     if ( (*it)->hasWeapon() )
                    //         std::cout << (*it)->getName() << " has ranged weapon? " << (*it)->getWeapon()->isRanged() << std::endl;
                    //     std::cout << "There are " << attack_options.size() << " attack options" << std::endl;

                    //     std::uniform_int_distribution<int> range( 0, attack_options.size() );
                    //     int action_choice = range( mt_rand );
                    //     std::cout << " Selecting attack option: " << action_choice << std::endl;
                        
                    // }

    // std::cout << "--Wake Up Phase" << std::endl;
    // Wake Up

    // WAKE PREVIOUSLY STUNNED CREW

    // RESET TURN FOR NEXT ROUND
    for ( int i=0; i<crew.size(); ++i )
        static_cast< Crew* >( &crew[i] )->reset_turn();

}

void GameMaster::monster_turn() {

    // GROW, MOVE, ATTACK, WAKE

    std::cout << "Turn " << turn << " - Monsters" << std::endl;
    std::vector< Monster* > list = ActionGenerator::shuffled_monster_list( monsters );

    // Grow
    std::uniform_int_distribution<int> range( 0, 4 );
    int grow_choice = range( mt_rand );
    std::string grow_choice_str;
    if ( grow_choice == 0 ) {
        grow_choice_str = "FRAGMENT";
    } else if ( grow_choice == 1 ) {
        grow_choice_str = "EGG";
    } else if ( grow_choice == 2 ) {
        grow_choice_str = "BABY";
    } else {
        grow_choice_str = "ADULT";
    }
    
    for ( int i=0; i<monsters.size(); ++i ) {
        if ( static_cast< Monster* >( &monsters[i] )->getStage() == grow_choice_str )
            static_cast< Monster* >( &monsters[i] )->grow();
    }


    // std::cout << "--Movement Phase" << std::endl;
    // Move
    list = ActionGenerator::shuffled_monster_list( monsters );
    for (auto it = list.begin(); it != list.end(); ++it) {            
  
        if ( (*it)->getLocation() ) {      
            std::vector< Location* > move_to = ActionGenerator::get_movement( *it, map );
            // std::cout << "DEBUG - Desination list is " << move_to.size() << " long." << std::endl;
            std::uniform_int_distribution<int> range( 0, move_to.size()-1 );
            (*it)->enter( *move_to[ range( mt_rand ) ] );

            std::cout << (*it)->getName() << "(" << (*it)->getID() << ")";
            std::cout << " moved to " << (*it)->getLocation()->getName() << std::endl;

        }
    }

    // Attack
    std::vector< Location* > location_list = ActionGenerator::shuffled_location_list( map );
    for (auto it = location_list.begin(); it != location_list.end(); ++it) {

        // GET TARGET LIST AT LOCATION
        std::vector< Crew* > targets = ActionGenerator::get_crew_targets( **it, map );

        // GET ALL MONSTERS THAT CAN ATTACK HERE
        std::vector< Monster* > attackers = ActionGenerator::monsters_that_can_attack( **it, crew );

        std::cout << "DEBUG-- " << "There are " << targets.size() << " target(s) and " << 
            attackers.size() << " attacker(s)" << " in the " << (*it)->getName() << std::endl;  
        
        // DEAL WITH TARGETS ONE AT A TIME
        for (int i=0; i<targets.size() && attackers.size()>0; ++i) {

            // GENERATE ATTACK TEAMS
            std::uniform_int_distribution<int> range( 0, attackers.size() );
            int team_size = range( mt_rand );

            if ( team_size == 0 ) {
                std::cout << "DEBUG-- " << "No Attack team for this enemy." << std::endl;
                continue;
            }


            std::cout << "DEBUG-- " << "Building attack team of size " << team_size <<
                " from " << attackers.size() << " available attackers." << std::endl;

            std::vector< Monster* > attack_team;
            for (int j=0; j<team_size; ++j) {
                attack_team.push_back( attackers[attackers.size()-1 ] );
                attackers.pop_back();
            }
            std::cout << "DEBUG-- " << "Team attacking " << targets[i]->getName() << 
                " is of size " << attack_team.size() << std::endl;
            
            // CALCULATE DAMAGES FROM ATTACK TEAM
            int directed_damage = 0;

            for (int i=0; i<team_size; ++i) {

                directed_damage += attack_team[i]->getStrength();

                attack_team[i]->complete_turn();

            }

            std::cout << "DEBUG-- Attack Team deals " << directed_damage << " directed damage." << std::endl; 

            // PERFORM THE ATTACK
            if ( directed_damage >= targets[i]->getConstitution() ) 
                targets[i]->kill();

        }
            // RANDOMIZE TEAM SIZE
            // MAKE TEAM FROM LAST 

    }


    // Wake Up


    for ( int i=0; i<monsters.size(); ++i )
        static_cast< Monster* >( &monsters[i] )->reset_turn();

}

void GameMaster::crew_discovers_monsters() {

    std::cout << "Turn " << turn << " - Awful Green Things Discovered" << std::endl;
    // Move (1 or 2 crew up to allowed movement to discover monsters)
    // Attack (Hand to Hand only)

}

bool GameMaster::check_win_conditions() {

    int monsters_remaining = 0;    
    int crew_remaining = 0;

    for ( int i=0; i<monsters.size(); ++i )
        if ( static_cast< Actor* >( &monsters[i] )->isActive() )
            ++monsters_remaining;
    if ( monsters_remaining == 0 ) {
        std::cout << "CREW WINS THE GAME" << std::endl;
        return true;
    }

    for ( int i=0; i<crew.size(); ++i )
        if ( static_cast< Actor* >( &crew[i] )->isActive() )
            ++crew_remaining;
    if ( crew_remaining == 0 ) {
        std::cout << "MONSTERS WINS THE GAME" << std::endl;
        return true;
    }
    
    return false;

}