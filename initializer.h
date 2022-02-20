#ifndef INITIALIZER_H
#define INITIALIZER_H

#include "game_master.h"

namespace Initializer {

    void buildMap( Map& );
    void buildCrew( Manifest& );    
    void buildMonsters( Manifest& );
    void buildWeapons( Manifest& );

    void buildEffects( std::vector<Effect*>& );

};

#endif