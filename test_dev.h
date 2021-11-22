
void test1_1() {

    Map map;
    Manifest crew;
    Manifest monsters;
    Manifest weapons;

    Initializer::buildMap( map );
    Initializer::buildCrew( crew );
    Initializer::buildMonsters( monsters );
    Initializer::buildWeapons( weapons );

    Crew * andrew = static_cast<Crew*>( &crew[0] );
    Crew * denis = static_cast<Crew*>( &crew[1] );

    andrew->enter( map[0] );
    map.debug();

    denis->enter( map[0] );


}

void test3() {

    Map map;
    Initializer::buildMap( map );

    Manifest crew;

    Crew andrew( "andrew" );
    crew.add( andrew );
    andrew.enter( map[0] );

    Manifest monsters;
    Monster egg( "EGG" );
    monsters.add( egg );
    egg.enter( map[0] );

    Manifest weapons;
    Weapon pistol( "pistol" );
    weapons.add( pistol );
    pistol.enter( map[0] );

    map.debug();

    andrew.exit();

    map.debug();

    andrew.enter( map[0] );


}

void test2() {

    Manifest crew;

    Crew andrew( "Andrew" );
    andrew.setStats( 1, 1, 1 ); 
    crew.add( andrew );


    std::cout << "Crewman: " << crew[0].getName() << "\n";
    
    Crew * ptr = static_cast< Crew * >( &crew[0] );
    std::cout << "Crewman: " << ptr->getName() << "\n";
    std::cout << "Crewman: " << ptr->getMovement() << "\n";
    ptr->setStats( 1, 1, 1 ); 
    std::cout << "Crewman: " << ptr->getName() << "\n";
    std::cout << "Crewman: " << ptr->getMovement() << "\n";

    std::cout << "Crewman: " << andrew.getName() << "\n";
    std::cout << "Crewman: " << andrew.getMovement() << "\n";

    ptr = nullptr;
    ptr = static_cast< Crew * >( &crew[0] );
    std::cout << "Crewman: " << ptr->getName() << "\n";
    std::cout << "Crewman: " << ptr->getMovement() << "\n";
    

}

void test1() {
    Map map;
    Manifest crew;
    Manifest monsters;
    Manifest weapons;

    Initializer::buildMap( map );
    Initializer::buildCrew( crew );
    Initializer::buildMonsters( monsters );
    Initializer::buildWeapons( weapons );
    
    // Entity * andrew = &crew[0];
    // Entity * allison = &crew[2];
    Crew * victoria = static_cast<Crew*>( &crew[3] );
    std::cout << "Victoria can move " << victoria->getMovement() << " places\n";
    

    // andrew->enter( map[0] );
    // allison->enter( map[7] );
    // victoria->enter( map[0] );

    // victoria->enter( map[0] );
    // victoria->exit( map[0] );
    victoria->enter( map[0] );
    victoria->enter( map[6] );
    victoria->exit();
    victoria->enter( map[6] );

    Monster * egg = static_cast<Monster*>( &monsters[1] );
    egg->enter( map[6] );
    std::cout << "Type: " << egg->getName() << "\n";

    std::cout << "Monster[" << egg->getName() << "] Can Move: " << egg->getMovement() << "\n";
    std::cout << "Monster[" << egg->getName() << "] ID: " << egg->getID() << "\n";
    
    // Monster m = Monster( "BABY", map[0] );
    // Monster * temp = &m;

    // std::cout << "Stage: " << temp->getStage() << "\n";
    // std::cout << "Stunned: " << temp->isStunned() << "\n";

    // Entity * e = temp;

    // std::cout << "Stage: " << e->getName() << "\n";

    // Monster * new_temp = static_cast<Monster*>( e );
    // std::cout << "Stage: " << new_temp->getStage() << "\n";
    // std::cout << "Stunned: " << new_temp->isStunned() << "\n";

    // bool boolean = false;
    // std::cout << "Bool: " << boolean << "\n";

    std::cout << "Is Victoria in " << map[6].getName() << " : " << map[6].find_entity( *victoria ) << "\n";

    map.debug(); 
    crew.debug();
    std::cout << "MONSTERS\n";
    monsters.debug();
    weapons.debug();

    Weapon * pistol = static_cast<Weapon*>( &weapons[2] );
    pistol->drop( map[6] );

    weapons.debug();
    map.debug(); 

    victoria->grab( *pistol );

    weapons.debug();
    map.debug(); 

    victoria->drop();
    
    weapons.debug();
    map.debug(); 

    // std::vector< Location* > places = ActionGenerator::get_connected_locations( map[6], map );
    // std::cout << "number of places: " << places.size() << "\n";
    std::cout << "Victoria can move " << victoria->getMovement() << " places\n";
    // victoria->setStats( 2, 1, 1 );
    Entity * ttt = &crew[3];
    Crew * victoria2 = static_cast<Crew*>( ttt );
    std::cout << "Victoria can move " << victoria2->getMovement() << " places\n";
    std::vector< Location* > ret = ActionGenerator::get_movement( victoria2, map );
    std::cout << "Return Size: " << ret.size() << "\n";
    for (int i=0; i<ret.size(); ++i)
        std::cout << "Arr: " << ret[i] << "\n";

    std::cout << "This is hilarious " << victoria2->getLocation()->getName() << "\n";

    std::vector< Location* > ret2 = ActionGenerator::get_line_of_sight_locations( *victoria2->getLocation(), map );
    for (int i=0; i<ret2.size(); ++i)
        std::cout << "Arr: " << ret2[i] << "\n";
    
    std::cout << "Monster Targets " << victoria2->getLocation()->getName() << "\n";

    std::vector< Monster* > ret4 = ActionGenerator::get_monster_targets_ranged( *victoria2->getLocation(), map );
    for (int i=0; i<ret4.size(); ++i)
        std::cout << "Arr: " << ret4[i] << "\n";

    // std::vector< Entity* > ret3 = ActionGenerator::get_entities( WEAPON, *victoria2->getLocation(), map );
    // for (int i=0; i<ret3.size(); ++i)
    //     std::cout << "Arr: " << ret3[i] << "\n";
}