#ifndef GAME_MASTER_H
#define GAME_MASTER_H

#include <iostream>

#include "map.h"
#include "location.h"

#include "manifest.h"
#include "crew.h"
#include "monster.h"
#include "weapon.h"

#include "initializer.h"
#include "action_generator.h"

class GameMaster {

private:

    Map map;
    Manifest crew;
    Manifest monsters;
    Manifest weapons;
    std::vector< Effect* > effects;

    bool running;
    int turn;
    int max_turns;

    int max_fragment_monsters;
    int max_egg_monsters;
    int max_baby_monsters;
    int max_adult_monsters;

    bool friendly_fire;

    std::mt19937 mt_rand;

    void crew_placement();
    void monster_placement();
    void weapon_placement();
    void crew_discovers_monsters();

    void crew_turn();
    void monster_turn();

    bool check_win_conditions();

    bool monster_limit_reached( std::string );
    bool monster_can_grow( std::string );
    bool monster_can_grow( Monster& );
    void grow_monster( Monster& );
    void grow_monsters( );

    bool monster_can_shrink( std::string );
    bool monster_can_shrink( Monster& );

    void shrink_monster( Monster& );
    std::vector< Monster* > fragment_monster( Monster& );

    void apply_crew_attack( Actor&, std::vector< Crew* >& );    
    void apply_monster_attack( Actor&, std::vector< Monster* >& );
    int resolve_damage( Effect& );

public:
    GameMaster();
    GameMaster( int );

    void init();
    void run();

    int roll_dice( int );



    // PURE DEBUG

    void run_design();
    void run_design_weapons();
    void run_design_grow();
    void run_design_stun();
    
    void run_design_fragment();

};

#endif