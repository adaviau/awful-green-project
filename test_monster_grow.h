
void test_monster_grow() {

    Manifest monsters;
    Initializer::buildMonsters( monsters );

    for ( int i=0; i<monsters.size(); ++i ) {

        Monster * m = static_cast< Monster* >( &monsters[i] );
        std::cout << "Monster[" << m->getID() << "]: " 
                    << m->getName() << " is " << m->isAlive()
                    << std::endl;

    }

}