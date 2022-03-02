#ifndef INITIALIZER_H
#define INITIALIZER_H

#include "game_master.h"

namespace Initializer {

    void build_complete_map( Map& );

    void build_complete_crew( Manifest& );

    void build_complete_monsters( Manifest&, int, int, int );

    void build_complete_weapons( Manifest& );

    void buildCrew( Manifest& );    


    void buildMonsters( Manifest& );
    void buildWeapons( Manifest& );

    void buildEffects( std::vector<Effect*>& );


    void build_test_map( Map& );

};

#endif