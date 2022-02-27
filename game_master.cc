#include <iostream>

#include "game_master.h"

GameMaster::GameMaster() : GameMaster( 500 ) { }

GameMaster::GameMaster( int turn_option ) : turn( 0 ), max_turns( turn_option ) {

    max_fragment_monsters = 15;
    max_egg_monsters = 10;
    max_baby_monsters = 3;
    max_adult_monsters = 3;

}

void GameMaster::init() {

    mt_rand = ActionGenerator::random_engine();

    Initializer::buildMap( map );
    Initializer::buildCrew( crew );
    Initializer::buildMonsters( monsters );
    Initializer::buildWeapons( weapons );
    Initializer::buildEffects( effects );

    crew_placement();
    monster_placement();
    weapon_placement();

}

void GameMaster::crew_placement() { 

    crew[0].enter( map[0] );
    crew[1].enter( map[2] );
    crew[2].enter( map[4] );
    crew[3].enter( map[1] );
    crew[4].enter( map[1] );

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
    Weapon * bottle_of_acid = static_cast< Weapon* >( &weapons[0] );
    bottle_of_acid->set_respawn_location( map[0] );
    // std::cout << "is fence deployable " << fence->isDeployable() << std::endl;
    // fence->deploy( map[8] );

}

void GameMaster::run_design_collateral() {

    monsters[0].enter( map[6] );
    monsters[1].enter( map[7] );
    monsters[2].enter( map[8] );

    crew[0].enter( map[6] );

    monsters.debug();
    crew.debug();

    map.debug();

    int expand_idx = 8;

    Actor * base_target = static_cast< Crew* >( &crew[0] );

    std::vector< Entity* > local = ActionGenerator::collateral_damage_local( *base_target, map );
    std::vector< Entity* > expanded = ActionGenerator::collateral_damage_expanded( map[ expand_idx ], map );


    std::cout << "There are " << local.size() << " Entities in Hall_1_1" << std::endl;

    std::cout << map[ expand_idx ].getName() << " has " 
                << ActionGenerator::get_expansion_locations( map[ expand_idx ], map ).size() 
                << " rooms expansion will extend to" << std::endl; 

    std::cout << "There are " << expanded.size() << " Entities in Expanded area from " << map[ expand_idx ].getName() << std::endl;


    Weapon * gas_grenade = static_cast< Weapon* >( &weapons[1] );
    Effect * regular_effect = gas_grenade->get_regular_effect();

    if ( regular_effect )
        std::cout << "Gas Grenade has a regular effect: " << regular_effect->getName()   << std::endl;
    else
        std::cout << "Gas Grenade has NO regular effect" << std::endl;




}

void GameMaster::run_design_fragment() {

    Monster * m = static_cast< Monster* >( &monsters[0] );

    monsters.debug();

    fragment_monster( *m );
    fragment_monster( *m );
    fragment_monster( *m );
    fragment_monster( *m );
    fragment_monster( *m );
    fragment_monster( *m );

    monsters.debug();

    for ( int i=0; i<monsters.size(); ++i )
        if ( static_cast< Monster* >( &monsters[i] )->getStage() == "FRAGMENT" )
            shrink_monster( *static_cast< Monster* >( &monsters[i] ) );

    monsters.debug();

}

void GameMaster::run_design_stun() {

    crew.debug();
    crew_turn();

    static_cast< Crew* >( &crew[0] )->stun();

    crew.debug();
    crew_turn();

    crew.debug();
    crew_turn();

}

void GameMaster::run_design_grow() {

    // for ( int i=0; i<10; ++i ) {

    //     monsters.debug();

    //     std::cout << std::endl << monster_limit_reached( "FRAGMENT" ) << std::endl;
    //     std::cout << monster_limit_reached( "EGG" ) << std::endl;
    //     std::cout << monster_limit_reached( "BABY" ) << std::endl;
    //     std::cout << monster_limit_reached( "ADULT" ) << std::endl;

    //     grow_monster( *( static_cast< Monster* >( &monsters[0] ) ) );

    // }

    // int alive_count = 0;
    // for ( int i=0; i<map.size(); ++i ) {
    //     alive_count += ActionGenerator::get_monster_targets_near( map[i], map ).size();
    // }
    // std::cout << " Monster Alive Count: " << alive_count << std::endl;

    // static_cast< Monster* >( &monsters[0] )->kill();
    
    // alive_count = 0;
    // for ( int i=0; i<map.size(); ++i ) {
    //     alive_count += ActionGenerator::get_monster_targets_near( map[i], map ).size();
    // }
    // std::cout << " Monster Alive Count: " << alive_count << std::endl;

    // monsters.debug();
    // std::cout << std::endl << monster_limit_reached( "FRAGMENT" ) << std::endl;
    // std::cout << monster_limit_reached( "EGG" ) << std::endl;
    // std::cout << monster_limit_reached( "BABY" ) << std::endl;
    // std::cout << monster_limit_reached( "ADULT" ) << std::endl;



    // monsters.debug();
    // grow_monsters();
    monsters.debug();

    for ( int i=0; i<100; ++i ) {
        grow_monsters();
        monsters.debug();
    }

}

void GameMaster::run_design_weapons() {

    crew_discovers_monsters();
    Crew *andrew = static_cast< Crew* >( &crew[0] );
    Weapon *pool_queue = static_cast< Weapon* >( &weapons[4] );

    std::cout << "Number of weapon effect chits: " << effects.size() << std::endl;
    
    std::cout << "Is the Pool Queue tested: " << pool_queue->isTested() << std::endl;
    std::cout << "  Quene Effect: " << pool_queue->get_monster_effect() << std::endl;
    std::cout << "First one is: " << effects[0]->getName() << std::endl;
    std::cout << "  Available: " << effects[0]->is_available() << std::endl;

    pool_queue->assign_effect( *effects[0] );

    std::cout << "Is the Pool Queue tested: " << pool_queue->isTested() << std::endl;
    std::cout << "  Quene Effect: " << pool_queue->get_monster_effect() << std::endl;
    std::cout << "First one is: " << effects[0]->getName() << std::endl;
    std::cout << "  Available: " << effects[0]->is_available() << std::endl;

    ActionGenerator::get_available_effect( effects );
    std::cout << "Is the Pool Queue tested: " << pool_queue->isTested() << std::endl;
    std::cout << "  Quene Effect: " << pool_queue->get_monster_effect() << std::endl;
    std::cout << "First one is: " << effects[0]->getName() << std::endl;
    std::cout << "  Available: " << effects[0]->is_available() << std::endl;

    // pool_queue->remove_effect( );

    std::cout << "Is the Pool Queue tested: " << pool_queue->isTested() << std::endl;
    std::cout << "  Quene Effect: " << pool_queue->get_monster_effect() << std::endl;
    std::cout << "First one is: " << effects[0]->getName() << std::endl;
    std::cout << "  Available: " << effects[0]->is_available() << std::endl;

    map.debug();
    weapons.debug();
    crew.debug();

    std::cout << "EVENT- andrew picks up pool queue" << std::endl; 
    andrew->grab( *pool_queue ); 

    map.debug();
    weapons.debug();
    crew.debug();

    std::cout << "EVENT- andrew enters Engine Room" << std::endl; 
    andrew->enter( map[3] );

    map.debug();
    weapons.debug();
    crew.debug();

    std::cout << "EVENT- andrew drops pool queue" << std::endl; 
    andrew->drop();  

    map.debug();
    weapons.debug();
    crew.debug();

    std::cout << "Is the Pool Queue tested: " << pool_queue->isTested() << std::endl;
    std::cout << "  Quene Effect: " << pool_queue->get_monster_effect() << std::endl;
    std::cout << "First one is: " << effects[0]->getName() << std::endl;
    std::cout << "  Available: " << effects[0]->is_available() << std::endl<< std::endl;

    std::cout << "Andrew tries to pickup Pool Queue." << std::endl;
    andrew->grab( *pool_queue );
    std::cout << "Andrew is holding: " << andrew->getWeapon()->getName() << std::endl;

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
    crew.debug();
    std::cout << "------------------------- CREWMEN" << std::endl;
    
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

    std::cout << "VERBOSE- generating random location list" << std::endl;
    std::vector< Location* > location_list = ActionGenerator::shuffled_location_list( map );

    // weapons.debug();
    // crew.debug();
    for (auto it = location_list.begin(); it != location_list.end(); ++it) {

        // GET TARGET LIST AT LOCATION
        std::cout << "VERBOSE- generating target(s) list" << std::endl;
        std::vector< Monster* > targets = ActionGenerator::get_monster_targets_near( **it, map );

        if ( targets.size() < 1 ) {
            std::cout << "STATE-- " << "There are " << targets.size() << " target(s) in the " 
                        << (*it)->getName() << std::endl;
            continue;
        }

        // GET ALL CREW THAT CAN ATTACK HERE
        std::cout << "VERBOSE- generating attacker(s) list" << std::endl;
        std::vector< Crew* > attackers = ActionGenerator::crew_that_can_attack( **it, crew );

        std::cout << "STATE-- " << "There are " << targets.size() << " target(s) and " << 
            attackers.size() << " attacker(s)" << " in the " << (*it)->getName() << std::endl;  
        
        if ( attackers.size() < 1 ) {
            continue;
        }

        // DEAL WITH TARGETS ONE AT A TIME
        for (int i=0; i<targets.size() && attackers.size()>0; ++i) {

            if ( !targets[i]->isAlive() ) {

                std::cout << "DEBUG-- Targetted entity is already dead... Skipping to next target" << std::endl;
                continue;

            }

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
            
            // APPLY ATTACKS
            apply_crew_attack( *targets[i], attack_team );

        }

    }

    // std::cout << "--Wake Up Phase" << std::endl;
    // Wake Up

    // WAKE PREVIOUSLY STUNNED CREW

    // RESET TURN FOR NEXT ROUND
    for ( int i=0; i<crew.size(); ++i ) {

        Actor * cursor = static_cast< Actor* >( &crew[i] );

        if ( cursor->canWake() )
            cursor->wakeup();
        else 
            cursor->set_wakeable();
    
        cursor->reset_turn();

    }

}

void GameMaster::monster_turn() {

    // GROW, MOVE, ATTACK, WAKE

    std::cout << "Turn " << turn << " - Monsters" << std::endl;
    std::vector< Monster* > list = ActionGenerator::shuffled_monster_list( monsters );

    // Grow
    grow_monsters();

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
        std::cout << "VERBOSE- generating target(s) list" << std::endl;
        std::vector< Crew* > targets = ActionGenerator::get_crew_targets( **it, map );

        if ( targets.size() < 1 ) {
            std::cout << "STATE-- " << "There are " << targets.size() << " target(s) in the " 
                        << (*it)->getName() << std::endl;
            continue;
        }

        // GET ALL MONSTERS THAT CAN ATTACK HERE
        std::cout << "VERBOSE- generating attacker(s) list" << std::endl;
        std::vector< Monster* > attackers = ActionGenerator::monsters_that_can_attack( **it, monsters );

        std::cout << "STATE-- " << "There are " << targets.size() << " target(s) and " << 
            attackers.size() << " attacker(s)" << " in the " << (*it)->getName() << std::endl;  
        
        if ( attackers.size() < 1 ) {
            continue;
        }
        
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
            
            // APPLY ATTACK
            apply_monster_attack( *targets[i], attack_team );

        }

    }

    // Wake wakeable OR make wakeable AND reset turn 
    // RESET TURN FOR NEXT ROUND
    for ( int i=0; i<monsters.size(); ++i ) {

        Actor * cursor = static_cast< Actor* >( &monsters[i] );

        if ( cursor->canWake() )
            cursor->wakeup();
        else 
            cursor->set_wakeable();
    
        cursor->reset_turn();

    }

}

void GameMaster::crew_discovers_monsters() {

    std::cout << "Turn " << turn << " - Awful Green Things Discovered" << std::endl;
    // Move (1 or 2 crew up to allowed movement to discover monsters)
    // Attack (Hand to Hand only)

    // Random number between 1 and 2

    // Find crew who can move to attack a monster

    // Move them to the area where the monster is

    // Apply the attack

}

bool GameMaster::check_win_conditions() {

    int monsters_remaining = 0;    
    int crew_remaining = 0;

    for ( int i=0; i<monsters.size(); ++i )
        if ( static_cast< Actor* >( &monsters[i] )->isAlive() )
            ++monsters_remaining;
    if ( monsters_remaining == 0 ) {
        std::cout << "CREW WINS THE GAME" << std::endl;
        return true;
    }

    for ( int i=0; i<crew.size(); ++i )
        if ( static_cast< Actor* >( &crew[i] )->isAlive() )
            ++crew_remaining;
    if ( crew_remaining == 0 ) {
        std::cout << "MONSTERS WINS THE GAME" << std::endl;
        return true;
    }
    
    return false;

}

void GameMaster::apply_crew_attack( Actor& target, std::vector<Crew*>& attack_team ) {

    std::cout << "--Resolving Attack--" << std::endl;

    std::cout << "EVENT- Target is: " << target.getID() << " attack team is size: "
        << attack_team.size() << std::endl;  

    int hand_to_hand_strikes = 0;
    std::vector<Weapon*> tested_weapon;
    std::vector<Weapon*> untested_weapon;
    
    // MAKING ATTACK DECISIONS
    for (int i=0; i<attack_team.size(); ++i) {

        std::cout << "EVENT- " << attack_team[i]->getName() << " ";

        bool is_using_weapon = false;
        bool ranged_forced = (attack_team[i]->getLocation()->id != target.getLocation()->id);
        std::cout << "DEBUG- attacker location id:" << attack_team[i]->getLocation()->id 
                        << std::endl;        
        std::cout << "DEBUG- target location id:" << target.getLocation()->id 
                        << std::endl;
        if ( ranged_forced )
            std::cout << "DEBUG- ranged attack is forced." << std::endl;

        if ( attack_team[i]->hasWeapon() ) {

            std::uniform_int_distribution<int> range( 0, 1 );
            is_using_weapon = range( mt_rand );
            std::cout << " is armed, ";

            if ( is_using_weapon || ranged_forced ) {

                Weapon * weapon = attack_team[i]->getWeapon();
                std::cout << "uses the " << weapon->getName() << ". It has "; 

                if ( weapon->isTested() ) {
                    // USE weapon with KNOWN effect
                    tested_weapon.push_back( weapon );
                    std::cout << "known "; 

                } else {
                    // USE weapon with UNKNOWN effect
                    untested_weapon.push_back( weapon );
                    std::cout << "unknown "; 

                }

                std::cout << "effects "; 

                if ( weapon->isSingleUse() )
                    attack_team[i]->drop();

                if ( weapon->isRespawning() )
                    weapon->repawn();

            } else {
                // Has weapon BUT USE Hand-to-Hand
                hand_to_hand_strikes += attack_team[i]->getStrength();
                std::cout << "but attacks hand-to-hand.";

            }

        } else {
            // Does not have weapon USE Hand-to-Hand
            hand_to_hand_strikes += attack_team[i]->getStrength();
            std::cout << " is unarmed and attacks hand-to-hand."; 

        }

        std::cout << std::endl;

        attack_team[i]->complete_turn();
        std::cout  << "VERBOSE- " << attack_team[i]->getName() 
                    << " is now unavailable until next turn" << std::endl; 

    }
    
    // int damage_dir = 0;
    // int damage_loc = 0;
    // int damage_exp = 0;
    // int damage_loc_crew = 0;
    // int damage_exp_crew = 0;

    // int stun_dir = 0;
    // int stun_loc = 0;
    // int stun_exp = 0;
    // int stun_loc_crew = 0;
    // int stun_exp_crew = 0;

    // int grow_dir = 0;
    // int grow_loc = 0;
    // int grow_exp = 0;

    // int shrink_dir = 0;
    // int shrink_loc = 0;
    // int shrink_exp = 0;
    
    // int fragment_dir = 0;
    // int fragment_loc = 0;
    // int fragment_exp = 0;

    // CALCULATING THE HAND TO HAND ATTACKS
    // damage_dir += roll_dice( hand_to_hand_strikes );
    
    // CALCULATING UNKNOWN EFFECTS
    if ( untested_weapon.size() > 0 ) {

        Effect * temp_effect = ActionGenerator::get_available_effect( effects );
        untested_weapon[0]->assign_effect( *temp_effect );
        std::cout << "EVENT- Weapon(" << untested_weapon[0]->getName() << ") is assigned the "
                    << temp_effect->getName() << " effect." << std::endl;

        for (int i=0; i<untested_weapon.size(); ++i) {

            tested_weapon.push_back( untested_weapon[0] );


        }

    }

    std::vector< Monster* > new_fragments;

    Location * attack_location = target.getLocation();
    std::vector< Entity* > area_of_effect_actors = ActionGenerator::collateral_damage_local( target, map );
    std::vector< Entity* > expansion_zone_entities = ActionGenerator::collateral_damage_expanded( *attack_location, map );

    DamageProfile damage;
    damage.weapons_used = tested_weapon;
    damage.hand_to_hand_strikes = hand_to_hand_strikes;

    hit( target, DIRECTED, damage );

    if ( damage.has_area_effect() && area_of_effect_actors.size() )
        std::cout << "DEBUG- Area of effect damage is added." << std::endl;

    if ( damage.has_area_effect() )
        for ( auto it = area_of_effect_actors.begin(); it != area_of_effect_actors.end(); ++it ) 
            hit( **it, AREA_OF_EFFECT, damage );

    if ( damage.has_expanded_effect() && expansion_zone_entities.size() )
        std::cout << "DEBUG- Expanded effect damage is added." << std::endl;

    if ( damage.has_expanded_effect() )
        for ( auto it = expansion_zone_entities.begin(); it != expansion_zone_entities.end(); ++it ) 
            hit( **it, AREA_OF_EFFECT, damage );
    

    // Generate the List for all affected entities

        // // CALCULATING FULL DAMAGE PROFILE
        // for (int i=0; i<tested_weapon.size(); ++i) {

        //     Effect * effect = tested_weapon[i]->get_monster_effect();
        //     Effect * crew_effect = tested_weapon[i]->get_regular_effect();
        //     int roll_result = roll_dice( effect->get_dice_count() );

        //     if ( effect->is_kill_type() ) {

        //         if ( tested_weapon[i]->hasAreaEffect() ) {
        //             damage_loc += roll_result;
        //             if ( tested_weapon[i]->hasExpandingEffect() )
        //                 damage_exp += roll_result;
        //         } else {
        //             damage_dir += roll_result;
        //         }

        //     } else if ( effect->is_stun_type() ) {

        //         if ( tested_weapon[i]->hasAreaEffect() ) {
        //             stun_loc += roll_result;
        //             if ( tested_weapon[i]->hasExpandingEffect() )
        //                 stun_exp += roll_result;
        //         } else {
        //             stun_dir += roll_result;
        //         }

        //     } else if ( effect->is_grow_type() ) {

        //         if ( tested_weapon[i]->hasAreaEffect() ) {
        //             grow_loc += 1;
        //             if ( tested_weapon[i]->hasExpandingEffect() )
        //                 grow_exp += 1;
        //         } else {
        //             grow_dir += 1;
        //         }
            
        //     } else if ( effect->is_shrink_type() ) {

        //         if ( tested_weapon[i]->hasAreaEffect() ) {
        //             shrink_loc += 1;
        //             if ( tested_weapon[i]->hasExpandingEffect() )
        //                 shrink_exp += 1;
        //         } else {
        //             shrink_dir += 1;
        //         }
            
        //     } else if ( effect->is_frag_type() ) {

        //         if ( tested_weapon[i]->hasAreaEffect() ) {
        //             fragment_loc += roll_result;
        //             if ( tested_weapon[i]->hasExpandingEffect() )
        //                 fragment_exp += roll_result;
        //         } else {
        //             fragment_dir += roll_result;
        //         }

        //     }

        //     if ( crew_effect && crew_effect->is_kill_type() ) {

        //         if ( tested_weapon[i]->hasAreaEffect() ) {
        //             damage_loc_crew += roll_result;
        //             if ( tested_weapon[i]->hasExpandingEffect() )
        //                 damage_exp_crew += roll_result;
        //         } else {
        //             damage_dir += roll_result;
        //         }

        //     } else if ( crew_effect && crew_effect->is_stun_type() ) {

        //         if ( tested_weapon[i]->hasAreaEffect() ) {
        //             stun_loc_crew += roll_result;
        //             if ( tested_weapon[i]->hasExpandingEffect() )
        //                 damage_exp += roll_result;
        //         } else {
        //             stun_exp_crew += roll_result;
        //         }

        //     }

        // }

        // // VERBOSE DESCRIPTION
        // {
        // std::cout << "ATTACK RESOLUTION________________________________________" << std::endl;
        // std::cout << "int damage_dir = " << damage_dir << std::endl;
        // std::cout << "int damage_loc = " << damage_loc << std::endl;
        // std::cout << "int damage_exp = " << damage_exp << std::endl;

        // std::cout << "int stun_dir = " << stun_dir << std::endl;
        // std::cout << "int stun_loc = " << stun_loc << std::endl;
        // std::cout << "int stun_exp = " << stun_exp << std::endl;

        // std::cout << "int grow_dir = " << grow_dir << std::endl;
        // std::cout << "int grow_loc = " << grow_loc << std::endl;
        // std::cout << "int grow_exp = " << grow_exp << std::endl;

        // std::cout << "int shrink_dir = " << shrink_dir << std::endl;
        // std::cout << "int shrink_loc = " << shrink_loc << std::endl;
        // std::cout << "int shrink_exp = " << shrink_exp << std::endl;

        // std::cout << "int fragment_dir = " << fragment_dir << std::endl;
        // std::cout << "int fragment_loc = " << fragment_loc << std::endl;
        // std::cout << "int fragment_exp = " << fragment_exp << std::endl;
        // std::cout << "_________________________________________________________" << std::endl;
        // }

        // APPLY DAMAGE

        // {
        // int target_constitution = target.getConstitution();
        // Monster *  target_monster = static_cast< Monster* >( &target );

        // // GROW
        // if ( grow_dir || grow_loc || grow_exp ) {

        //     grow_monster( *target_monster );

        // }
        // // SHRINK
        // if ( shrink_dir || shrink_loc || shrink_exp ) {

        //     shrink_monster( *target_monster );

        // }
        // // KILL
        // if ( target_constitution <= damage_dir + damage_loc + damage_exp ) {

        //     target_monster->kill();
        //     std::cout << "STATE- Monster(" << target_monster->getName() << ", " << target_monster->getID() 
        //                 << ") has been killed." << std::endl;

        // // FRAGMENT
        // } else if ( fragment_dir || fragment_loc || fragment_exp ) {

        //     new_fragments = fragment_monster( *target_monster );

        // // STUN
        // } else if ( target_constitution <= stun_dir + stun_loc + stun_exp ) {
            
        //     target_monster->stun();
        //     for ( int f=0; f<new_fragments.size(); ++f )
        //         new_fragments[f]->stun();

        // }
        // }

    // Remove Effect for Multi-Unknown condition
    if ( untested_weapon.size() > 1 ) {
        untested_weapon[0]->remove_effect();
        std::cout << "EVENT- Weapon(" << untested_weapon[0] << ") effect "
            << " was removed for multiple unknown effect case." 
            << std::endl;
    }

    std::cout << "Complete Attack" << std::endl;

}

Entity * GameMaster::hit( Entity& e, DAMAGE_TYPE type, DamageProfile& p ) {

    int kill = 0;
    int stun = 0;
    int shrink = 0;
    int grow = 0;
    int fragment = 0;

    p.roll();

    if ( e.getType() == MONSTER ) {
        
        switch ( type ) {

            case DIRECTED:
                kill += p.damage_dir;
                stun += p.stun_dir;
                shrink += p.shrink_dir;
                grow += p.grow_dir;
                fragment += p.fragment_dir;

            case AREA_OF_EFFECT:
                kill += p.damage_loc;
                stun += p.stun_loc;
                shrink += p.shrink_loc;
                grow += p.grow_loc;
                fragment += p.fragment_loc;

            case EXPANDED_AREA:
                kill += p.damage_exp;
                stun += p.stun_exp;
                shrink += p.shrink_exp;
                grow += p.grow_exp;
                fragment += p.fragment_exp;

        }

        Monster * target = static_cast< Monster* >( &e );
        int target_constitution = target->getConstitution();
        std::vector< Monster* > new_fragments;

        // GROW
        if ( grow ) {

            grow_monster( *target );
            std::cout << "STATE- Monster(" << target->getName() << ", " << target->getID() 
                        << ") has grown." << std::endl;

        }
        // SHRINK
        if ( shrink ) {

            shrink_monster( *target );
            std::cout << "STATE- Monster(" << target->getName() << ", " << target->getID() 
                        << ") has shrunk." << std::endl;

        }
        // KILL
        if ( target_constitution <= kill ) {

            target->kill();
            std::cout << "STATE- Monster(" << target->getName() << ", " << target->getID() 
                        << ") has been killed." << std::endl;

        // FRAGMENT
        } else if ( fragment ) {

            new_fragments = fragment_monster( *target );
            std::cout << "STATE- Monster(" << target->getName() << ", " << target->getID() 
                        << ") has blown up." << std::endl;

        // STUN
        } else if ( target_constitution <= stun ) {
            
            target->stun();
            std::cout << "STATE- Monster(" << target->getName() << ", " << target->getID() 
                        << ") has been stunned." << std::endl;
            for ( int f=0; f<new_fragments.size(); ++f )
                new_fragments[f]->stun();

        } else {

            std::cout << "STATE- Monster(" << target->getName() << ", " << target->getID() 
                        << ") survived attack unscathed." << std::endl;

        }


    } else if ( e.getType() == CREW ) {
        
        switch ( type ) {

            case DIRECTED:
                kill += p.damage_dir;

            case AREA_OF_EFFECT:
                kill += p.damage_loc_crew;
                stun += p.stun_loc_crew;

            case EXPANDED_AREA:
                kill += p.damage_exp_crew;
                stun += p.stun_exp_crew;

        }

        Crew * target = static_cast< Crew* >( &e );
        int target_constitution = target->getConstitution();
        
        if ( target_constitution <= kill ) {

            target->kill();
            std::cout << "STATE- Crew(" << target->getName() << ", " << target->getID() 
                        << ") has been killed." << std::endl;

        // FRAGMENT
        } else if ( target_constitution <= stun ) {
            
            target->stun();            
            std::cout << "STATE- Crew(" << target->getName() << ", " << target->getID() 
                        << ") has been stunned." << std::endl;

        } else {

            std::cout << "STATE- Crew(" << target->getName() << ", " << target->getID() 
                        << ") survived attack unscathed." << std::endl;

        }

    }

    return nullptr;

}


void GameMaster::apply_monster_attack( Actor& target, std::vector<Monster*>& attack_team ) {

    std::cout << "--Resolving Monster Attack--" << std::endl;

    std::cout << "EVENT- Target is: " << target.getID() << " attack team is size: "
        << attack_team.size() << std::endl;  

    int hand_to_hand_strikes = 0;
    
    // MAKING ATTACK DECISIONS
    for (int i=0; i<attack_team.size(); ++i) {
        
        // USE physical attack
        hand_to_hand_strikes += attack_team[i]->getStrength();

        attack_team[i]->complete_turn();
        std::cout  << "VERBOSE- " << attack_team[i]->getName() 
                    << " is now unavailable until next turn" << std::endl;

    }
    
    int damage_dir = 0;

    // CALCULATING THE HAND TO HAND ATTACKS
    damage_dir += roll_dice( hand_to_hand_strikes );

    std::cout << "ATTACK RESOLUTION________________________________________" << std::endl;
    std::cout << "int damage_dir = " << damage_dir << std::endl;
    std::cout << "_________________________________________________________" << std::endl;

    Location * attack_location = target.getLocation();
    std::vector< Entity* > area_of_effect_actors = ActionGenerator::collateral_damage_local( target, map );
    std::vector< Entity* > expansion_zone_entities = ActionGenerator::collateral_damage_expanded( *attack_location, map );

    DamageProfile damage;
    damage.hand_to_hand_strikes = hand_to_hand_strikes;

    hit( target, DIRECTED, damage );

    Crew *  target_crew = static_cast< Crew* >( &target );

    // IF KILLED
    if ( !target_crew->isAlive() ) {
        
        std::uniform_int_distribution<int> range( 0, attack_team.size()-1 );
        int idx_affected_monster = range( mt_rand );

        Effect * effect = ActionGenerator::get_available_effect( effects ); 
        int roll_result = roll_dice( effect->get_dice_count() );

        Monster * affected_monster = attack_team[ idx_affected_monster ];

        if ( target_crew->isRobot() && effect ) {
       
            std::cout << "STATE- Monster(" << affected_monster->getName() << ", " << affected_monster->getID() 
                                << ") eats the Robot." << std::endl;

            std::cout << "VERBOSE- Effect(" << effect->getName() << ")" << std::endl;

            if ( effect->is_kill_type() ) {

                if ( roll_result <= affected_monster->getConstitution() ) {
                    affected_monster->kill();
                    std::cout << "STATE- Monster(" << affected_monster->getName() << ", " << affected_monster->getID() 
                                << ") has been killed." << std::endl;
                }

            } else if ( effect->is_stun_type() ) {

                if ( roll_result <= affected_monster->getConstitution() ) {
                    affected_monster->stun();
                    std::cout << "STATE- Monster(" << affected_monster->getName() << ", " << affected_monster->getID() 
                                << ") has been stunned." << std::endl;
                }
        
            } else if ( effect->is_grow_type() ) {

                grow_monster( *affected_monster );
            
            } else if ( effect->is_shrink_type() ) {

                shrink_monster( *affected_monster );
            
            } else if ( effect->is_frag_type() ) {

                fragment_monster( *affected_monster );

            }
        
        } else { 
            
            std::cout << "STATE- Monster(" << affected_monster->getName() << ", " << affected_monster->getID() 
                                << ") eats the crewman and grows." << std::endl;
            grow_monster( *affected_monster );

        }

    }

    std::cout << "Complete Attack" << std::endl;

}



// Return true if limit is reached
bool GameMaster::monster_limit_reached( std::string stage ) {

    int count = 0;
    int max_count = -1;

    if ( stage == "FRAGMENT" )
        max_count = max_fragment_monsters;
    else if ( stage == "EGG" )
        max_count = max_egg_monsters;
    else if ( stage == "BABY" )
        max_count = max_baby_monsters;
    else if ( stage == "ADULT" ) 
        max_count = max_adult_monsters;

    for ( int i=0; i<monsters.size(); ++i ) {

        // FLAG this can be changed to get shuffled list
        Monster * cursor = static_cast< Monster* >( &monsters[i] );
        if ( cursor->isAlive() && stage == cursor->getStage() )
            ++count;

    }

    std::cout << "DEBUG- for " << stage << " stage, count: " << count << " max: " << max_count
                << std::endl;

    return count >= max_count;

}

// return true if stage can grow
bool GameMaster::monster_can_grow( std::string stage ) {

    if ( stage == "FRAGMENT" )
        return !monster_limit_reached( "BABY" );
    else if ( stage == "EGG" )
        return !monster_limit_reached( "BABY" );
    else if ( stage == "BABY" )
        return !monster_limit_reached( "ADULT" );
    else if ( stage == "ADULT" ) 
        return !monster_limit_reached( "EGG" );

    return false;

}

bool GameMaster::monster_can_grow( Monster& monster ) {

    return monster_can_grow( monster.getStage() );

}

bool GameMaster::monster_can_shrink( std::string stage ) {

    if ( stage == "ADULT" )
        return !monster_limit_reached( "BABY" );
    else if ( stage == "BABY" )
        return !monster_limit_reached( "EGG" );
    else if ( stage == "FRAGMENT" )
        return !monster_limit_reached( "EGG" );

    return false;

}

bool GameMaster::monster_can_shrink( Monster& monster ) {

    return monster_can_shrink( monster.getStage() );

}

// Remove the prevention checks for this function because they are redundant
void GameMaster::grow_monster( Monster& monster ) {

    std::cout << "VERBOSE- Attempting to grow Monster(" << monster.getID() << ")"
                    << std::endl;

    bool can_grow = monster_can_grow( monster );

    if ( !can_grow ) {
        std::cout << "VERBOSE- Monster limit reached. Monster(" << monster.getID() << ")"
                    << " cannot grow" << std::endl;
        return;
    }

    if ( monster.getStage() == "ADULT" ) {

        std::cout << "VERBOSE- Adult Monster attemping to lay an EGG " << std::endl;
        
        Entity * created_egg = new Monster( "EGG" );      
        created_egg->enter( *monster.getLocation() );
        monsters.add( *created_egg );

        std::cout << "VERBOSE- Monster layed an egg" << std::endl;
        

    } else {

        monster.grow();

    }

}

void GameMaster::grow_monsters( ) {

    std::cout << "VERBOSE- Generate growth options" << std::endl;
    std::vector< std::string > options = ActionGenerator::get_growth_options( monsters );
    std::cout << "VERBOSE- Found " << options.size() << " options" << std::endl;

    for ( int i=0; i<options.size(); ++i ) {

        std::cout << "VERBOSE- Checking if " << options[i] << " can grow" << std::endl;
        if ( monster_can_grow( options[i] ) ) {
        
            std::cout << "VERBOSE- Growing " << options[i] << " is allowed" << std::endl;
            std::vector< Monster* > growth_targets; 
            growth_targets = ActionGenerator::get_monsters_of_stage( options[i], monsters );
            for ( int j=0; j<growth_targets.size(); ++j ) {

                grow_monster( *growth_targets[j] );
            
            }

            return;

        } else {

            std::cout << "VERBOSE- " << options[i] << " is maxed. Trying another option" 
                        << std::endl;

        }

    }

    std::cout << "VERBOSE- No growing could be performed" << std::endl;

}


void GameMaster::shrink_monster( Monster& monster ) {

    std::cout << "VERBOSE- Attempting to shrink Monster(" << monster.getID() << ")"
                    << std::endl;

    bool can_shrink = monster_can_shrink( monster );

    if ( !can_shrink ) {
        std::cout << "VERBOSE- Monster limit reached. Monster(" << monster.getID() << ")"
                    << " cannot shrink" << std::endl;
        return;
    }

    monster.shrink();

}

std::vector< Monster* > GameMaster::fragment_monster( Monster& monster ) {

    int number_of_pieces = roll_dice(1);
    std::vector< Monster* > output;

    std::cout << "VERBOSE- Attempting to fragment Monster(" << monster.getID() << ")"
                    << " into " << number_of_pieces << " pieces." << std::endl;
            
    std::cout << "EVENT- Monster(" << monster.getName() << ", " << monster.getID() << ") is blown apart ";
    
    int i;

    for ( i=0; i<number_of_pieces && !monster_limit_reached( "FRAGMENT" ); ++i ) {

        Monster * created_fragment = new Monster( "FRAGMENT" );      
        created_fragment->enter( *monster.getLocation() );
        monsters.add( *created_fragment );
        output.push_back( created_fragment );

    }

    std::cout << "into " << i << " pieces." << std::endl;

    monster.kill();

    return output;

}

// int GameMaster::resolve_attack(  ) {

//     int total_dice = 3;
//     return roll_dice( total_dice );

// }

int GameMaster::roll_dice( int n ) {

    if ( n<1 )
        return 0;

    std::uniform_int_distribution<int> range( 1, 6 );
    return range( mt_rand ) + roll_dice( n-1 );

}


//              for (int i=0; i<team_size; ++i) {

//                 if ( attack_team[i]->hasWeapon() ) {

//                     std::uniform_int_distribution<int> range( 0, 1 );
//                     int use_weapon_choice = range( mt_rand );

//                     if ( use_weapon_choice == 0 ) {

//                         directed_damage += attack_team[i]->getStrength();

//                     } else {

//                         Weapon * attacker_weapon = attack_team[i]->getWeapon();
//                         std::cout << "DEBUG-- Attacker USES " << attacker_weapon->getName() << 
//                             std::endl;
                        
//                         if ( attacker_weapon->isDeployable() ) {
//                             attacker_weapon->deploy( **it );
//                         }

//                         if ( attacker_weapon->hasAreaEffect() )
//                             splash_damage += 15;
//                         else
//                             directed_damage += 10;

//                     }

//                 } else {

//                     directed_damage += attack_team[i]->getStrength();

//                 }

//                 attack_team[i]->complete_turn();

//             }