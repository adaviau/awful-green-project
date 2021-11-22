#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "map.h"
#include "crew.h"
#include "monster.h"
#include "weapon.h"


namespace Validator {

    int has_monster( Location& );
    int has_crewman( Location& );
    int has_weapon( Location& );
    int has_adult_or_baby( Location& );
    int has_active_fence( Location& );

    // Entity* get_by_id( GameManager&, int );

};

#endif