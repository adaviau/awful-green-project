
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
    m.add( hall_1_1 );

    Location hall_1_2( "Hall_1_2", 7 );
    hall_1_2.add_connection( 6 );
    hall_1_2.add_connection( 1 );
    hall_1_2.add_connection( 5 );
    hall_1_2.add_connection( 8 );
    m.add( hall_1_2 );

    Location hall_1_3( "Hall_1_3", 8 );
    hall_1_3.add_connection( 7 );
    hall_1_3.add_connection( 2 );
    hall_1_3.add_connection( 3 );
    hall_1_3.add_connection( 4 );
    hall_1_3.add_sightline( 6 );
    m.add( hall_1_3 );

}

void Initializer::buildCrew( Manifest& m ) {

    Crew * andrew = new Crew( "Andrew" );
    Crew * denis = new Crew( "Denis" );
    Crew * allison = new Crew( "Allison" );
    Crew * victoria = new Crew( "Victoria" );
    std::cout << "Default Vic can move " << victoria->getMovement() << " places\n";
    victoria->setStats( 1, 1, 1 );
    andrew->setStats( 2, 1, 1 );
    denis->setStats( 2, 1, 1 );
    std::cout << "Set Vic can move " << victoria->getMovement() << " places\n";

    allison->stun();
    denis->stun();
    victoria->stun();

    m.add( *andrew );
    m.add( *denis );
    m.add( *allison );
    m.add( *victoria );

}

void Initializer::buildMonsters( Manifest& m ) {

    Monster * fragment = new Monster( "FRAGMENT" );
    Monster * egg = new Monster( "EGG" );
    Monster * baby = new Monster( "BABY" );
    Monster * adult = new Monster( "ADULT" );

    adult->activate();
    adult->stun();

    m.add( *fragment );
    m.add( *egg );
    m.add( *baby );
    m.add( *adult );

}

void Initializer::buildWeapons( Manifest& m ) {

    Weapon * laser = new Weapon( "Laser" );
    Weapon * rifle = new Weapon( "Rifle" );
    Weapon * pistol = new Weapon( "Pistol" );
    Weapon * electric_fence = new Weapon( "Electic Fence" );
    Weapon * pool_queue = new Weapon( "Pool Queue" );

    electric_fence->set_deployable();

    m.add( *laser );
    m.add( *rifle );
    m.add( *pistol );
    m.add( *electric_fence );
    m.add( *pool_queue );

}
