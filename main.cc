#include <iostream>

#include "location.h"
#include "manifest.h"
#include "map.h"

#include "crew.h"
#include "monster.h"
#include "weapon.h"

#include "hardcoded.h"


int main() {

    Map map;
    Manifest crew;
    Manifest monsters;
    Manifest weapons;

    buildMap( map );
    buildCrew( crew );
    buildMonsters( monsters );
    buildWeapons( weapons );
    
    Entity * andrew = &crew[0];
    Entity * allison = &crew[2];
    Entity * victoria = &crew[3];

    andrew->enter( map[0] );
    allison->enter( map[7] );
    victoria->enter( map[0] );

    victoria->enter( map[0] );
    victoria->exit( map[0] );
    victoria->enter( map[0] );
    victoria->enter( map[6] );
    victoria->exit( map[0] );

    weapons[0].enter( map[0] );

    Monster * egg = static_cast<Monster*>( &monsters[1] );

    std::cout << "Type: " << egg->getName() << "\n";

    Monster m = Monster( "BABY", map[0] );
    Monster * temp = &m;

    std::cout << "Stage: " << temp->getStage() << "\n";
    std::cout << "Stunned: " << temp->isStunned() << "\n";

    Entity * e = temp;

    std::cout << "Stage: " << e->getName() << "\n";

    Monster * new_temp = static_cast<Monster*>( e );
    std::cout << "Stage: " << new_temp->getStage() << "\n";
    std::cout << "Stunned: " << new_temp->isStunned() << "\n";

    bool boolean = false;
    std::cout << "Bool: " << boolean << "\n";

    std::cout << "Is Victoria in " << map[6].getName() << " : " << map[6].find_entity( *victoria ) << "\n";

    // map.debug(); 
    // crew.debug();
    // monsters.debug();
    // weapons.debug();

    return 0;

}