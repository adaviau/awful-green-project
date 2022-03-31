#include <iostream>

#include "game_master.h"

int main( int argc, char *argv[] ) {

    int turn_count = 10000;
    if ( argc > 1 )
        turn_count = std::atoi( argv[1] );

    GameMaster gm( turn_count );
    gm.init();
    gm.run();

    return 0;

}