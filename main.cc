#include <iostream>

#include "game_master.h"

#include "test_dev.h"
// #include "test_map.h"
#include "test_battle.h"
#include "test_monster_grow.h"
#include "test_accessors.h"


int main() {

    // test_crew_attack_monster();

    // test_monster_grow();
    // test_monster_accessor();
    // test_crew_accessor();
    // test_location_accessor();
    // test1();
    // test2();
    // test3();
    // test1_1();

    GameMaster gm;
    gm.init();
    gm.run();

    return 0;

}