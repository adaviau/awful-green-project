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

    std::mt19937 mt_rand;

    void crew_placement();
    void monster_placement();
    void weapon_placement();
    void crew_discovers_monsters();

    void crew_turn();
    void monster_turn();

    bool check_win_conditions();

    void apply_attack( Actor&, std::vector<Crew*>& );
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

};

#endif