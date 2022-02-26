
#include "initializer.h"

void Initializer::buildMap( Map& m ) {

    Location bridge( "Bridge", 0 );
    bridge.add_connection( 6 );
    bridge.add_sightline( 7 );
    bridge.add_sightline( 8 );
    m.add( bridge );

    Location starboard( "Starboard", 1 );
    starboard.add_connection( 7 );
    starboard.add_sightline( 6 );
    starboard.add_sightline( 8 );
    m.add( starboard );

    Location fuel_2( "Fuel_2", 2 );
    fuel_2.add_connection( 1 );
    fuel_2.add_connection( 8 );
    fuel_2.add_sightline( 6 );
    fuel_2.add_sightline( 7 );
    m.add( fuel_2 );

    Location engine_room( "Engine_Room", 3 );
    engine_room.add_connection( 8 );
    engine_room.add_sightline( 6 );
    engine_room.add_sightline( 7 );
    m.add( engine_room );

    Location fuel_1( "Fuel_1", 4 );
    fuel_1.add_connection( 5 );
    fuel_1.add_connection( 8 );
    fuel_1.add_sightline( 6 );
    fuel_1.add_sightline( 7 );
    m.add( fuel_1 );

    Location portside( "Portside", 5 );
    portside.add_connection( 7 );
    portside.add_sightline( 6 );
    portside.add_sightline( 8 );
    m.add( portside );

    Location hall_1_1( "Hall_1_1", 6 );
    hall_1_1.add_connection( 0 );
    hall_1_1.add_connection( 7 );
    hall_1_1.add_sightline( 8 );
    hall_1_1.add_expansion( 7 );
    hall_1_1.add_expansion( 8 );
    m.add( hall_1_1 );

    Location hall_1_2( "Hall_1_2", 7 );
    hall_1_2.add_connection( 6 );
    hall_1_2.add_connection( 1 );
    hall_1_2.add_connection( 5 );
    hall_1_2.add_connection( 8 );
    hall_1_2.add_expansion( 6 );
    hall_1_2.add_expansion( 8 );
    m.add( hall_1_2 );

    Location hall_1_3( "Hall_1_3", 8 );
    hall_1_3.add_connection( 7 );
    hall_1_3.add_connection( 2 );
    hall_1_3.add_connection( 3 );
    hall_1_3.add_connection( 4 );
    hall_1_3.add_sightline( 6 );
    hall_1_3.add_expansion( 6 );
    hall_1_3.add_expansion( 7 );
    m.add( hall_1_3 );

}

void Initializer::buildCrew( Manifest& m ) {

    Crew * andrew = new Crew( "Andrew" );
    Crew * denis = new Crew( "Denis" );
    Crew * evan = new Crew( "Evan" );
    Crew * victoria = new Crew( "Victoria" );
    Crew * robot = new Crew( "Leadfoot" );

    std::cout << "Default Vic can move " << victoria->getMovement() << " places\n";
    victoria->setStats( 3, 27, 1 );
    andrew->setStats( 2, 19, 2 );
    evan->setStats( 1, 15, 3 );
    denis->setStats( 1, 11, 4 );
    robot->setStats( 4, 44, 1 );
    robot->set_robot();
    std::cout << "Set Vic can move " << victoria->getMovement() << " places\n";

    // andrew->stun();
    // allison->stun();
    // denis->stun();
    // victoria->stun();

    m.add( *andrew );
    m.add( *denis );
    m.add( *evan );
    m.add( *victoria );
    m.add( *robot );

}

void Initializer::buildMonsters( Manifest& m ) {

    Monster * fragment = new Monster( "FRAGMENT" );
    Monster * egg = new Monster( "EGG" );
    Monster * baby = new Monster( "BABY" );
    Monster * adult = new Monster( "ADULT" );

    // adult->stun();

    m.add( *fragment );
    m.add( *egg );
    m.add( *baby );
    m.add( *adult );

}

void Initializer::buildWeapons( Manifest& m ) {

    Weapon * bottle_of_acid = new Weapon( "Bottle of Acid" );
    bottle_of_acid->set_single_use();
    bottle_of_acid->set_respawning();
    bottle_of_acid->set_ranged();
    Weapon * gas_grenade = new Weapon( "Gas Grenade" );
    gas_grenade->set_ranged();
    gas_grenade->set_area_of_effect();
    gas_grenade->set_expanding();
    gas_grenade->set_regular_effect( *( new Effect( _5_DICE_TO_STUN ) ) );
    Weapon * fire_extinguisher = new Weapon( "Fire Extinguisher" );
    fire_extinguisher->set_area_of_effect();
    fire_extinguisher->set_ranged();
    Weapon * stun_pistol = new Weapon( "Stun Pistol" );
    stun_pistol->set_ranged();
    Weapon * knife = new Weapon( "Knife" );
    Weapon * pool_queue = new Weapon( "Pool Queue" );

    m.add( *bottle_of_acid );
    m.add( *gas_grenade );
    m.add( *stun_pistol );
    m.add( *knife );
    m.add( *pool_queue );

}

void Initializer::buildEffects( std::vector<Effect*>& m ) {

    m.push_back( new Effect( _5_DICE_TO_KILL ) );
    m.push_back( new Effect( _5_DICE_TO_KILL ) );

    m.push_back( new Effect( _4_DICE_TO_KILL ) );
    m.push_back( new Effect( _4_DICE_TO_KILL ) );

    m.push_back( new Effect( _3_DICE_TO_KILL ) );
    m.push_back( new Effect( _3_DICE_TO_KILL ) );

    m.push_back( new Effect( _5_DICE_TO_STUN ) );

    m.push_back( new Effect( _NO_EFFECT ) );
    m.push_back( new Effect( _NO_EFFECT ) );

    m.push_back( new Effect( _GROW ) );

    m.push_back( new Effect( _SHRINK ) );

    m.push_back( new Effect( _1_DIE_FRAGMENTS ) );
    m.push_back( new Effect( _1_DIE_FRAGMENTS ) );
    m.push_back( new Effect( _1_DIE_FRAGMENTS ) );

}
