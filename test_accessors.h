
void test_monster_accessor() {

    Manifest monsters;
    Initializer::buildMonsters( monsters );
    std::vector< Monster* > list = ActionGenerator::shuffled_monster_list( monsters );

    std::cout << "Monster Manifest Order:" << std::endl;
    for ( int i=0; i<monsters.size(); ++i )
        std::cout << "M[" << monsters[i].getID() << "]" << std::endl;

    std::cout << "Monster Shuffled Order:" << std::endl;
    // std::cout << "REACHED1 " << list.size() << "\n";
    for ( int i=0; i<list.size(); ++i )
        std::cout << "M[" << list[i]->getID() << "]" << std::endl;

    std::cout << "Monster Manifest Order:" << std::endl;
    for ( int i=0; i<monsters.size(); ++i )
        std::cout << "M[" << monsters[i].getID() << "]" << std::endl;
        
}

void test_crew_accessor() {

    Manifest crew;
    Initializer::buildCrew( crew );
    std::vector< Crew* > list = ActionGenerator::shuffled_crew_list( crew );

    std::cout << "Crew Manifest Order:" << std::endl;
    for ( int i=0; i<crew.size(); ++i )
        std::cout << "M[" << crew[i].getID() << "]" << std::endl;

    std::cout << "Crew Shuffled Order:" << std::endl;
    for ( int i=0; i<list.size(); ++i )
        std::cout << "C[" << list[i]->getID() << "]" << std::endl;

    std::cout << "Crew Manifest Order:" << std::endl;
    for ( int i=0; i<crew.size(); ++i )
        std::cout << "M[" << crew[i].getID() << "]" << std::endl;
        
}

void test_location_accessor() {
    
    Map map;
    Initializer::buildMap( map );
    std::vector< Location* > list = ActionGenerator::shuffled_location_list( map );

    std::cout << "Map Order:" << std::endl;
    for ( int i=0; i<map.size(); ++i )
        std::cout << "M[" << map[i].map_idx << "]" << std::endl;

    std::cout << "Location Shuffled Order:" << std::endl;
    for ( int i=0; i<list.size(); ++i )
        std::cout << "M[" << list[i]->map_idx << "]" << std::endl;

    std::cout << "Map Order:" << std::endl;
    for ( int i=0; i<map.size(); ++i )
        std::cout << "M[" << map[i].map_idx << "]" << std::endl;

}