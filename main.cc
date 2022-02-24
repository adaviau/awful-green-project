#include <iostream>

#include "game_master.h"

#include "test_dev.h"
#include "test_weapon_effects.h"
// #include "test_map.h"
#include "test_battle.h"
#include "test_monster_grow.h"
#include "test_weapon_grabs.h"
#include "test_accessors.h"


int main( int argc, char *argv[] ) {

    int turn_count = 50;
    if ( argc > 1 )
        turn_count = std::atoi( argv[1] );

    // test_crew_attack_monster();

    // test_weapon_effects();

    // test_monster_grow();
    // test_monster_accessor();
    // test_crew_accessor();
    // test_location_accessor();
    // test_weapon_grabs();
    // test1();
    // test2();
    // test3();
    // test1_1();

    GameMaster gm( turn_count );
    gm.init();
    gm.run_design_fragment();

    return 0;

}