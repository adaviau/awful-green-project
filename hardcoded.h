
void buildMap( Map& m ) {

    Location bridge( "Bridge", 0 );
    bridge.add_connection( 6 );
    bridge.add_sightline( 7 );
    bridge.add_sightline( 8 );
    m.add( bridge );

    Location portside( "Portside", 1 );
    portside.add_connection( 7 );
    portside.add_sightline( 6 );
    portside.add_sightline( 8 );
    m.add( portside );

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

    Location starboard( "Starboard", 5 );
    starboard.add_connection( 7 );
    starboard.add_sightline( 6 );
    starboard.add_sightline( 8 );
    m.add( starboard );

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

void buildCrew( Manifest& m ) {

    Entity andrew( "Andrew", CREW );
    Entity denis( "Denis", CREW );
    Entity allison( "Allison", CREW );
    Entity victoria( "Victoria", CREW );

    m.add( andrew );
    m.add( denis );
    m.add( allison );
    m.add( victoria );

}

void buildMonsters( Manifest& m ) {

    Monster fragment( "FRAGMENT" );
    Monster egg( "EGG" );
    Monster baby( "BABY" );
    Monster adult( "ADULT" );

    m.add( fragment );
    m.add( egg );
    m.add( baby );
    m.add( adult );

}

void buildWeapons( Manifest& m ) {

    Weapon laser( "Laser" );
    Weapon rifle( "Rifle" );
    Weapon handgun( "Handgun" );
    Weapon pool_queue( "Pool Queue" );

    m.add( laser );
    m.add( rifle );
    m.add( handgun );
    m.add( pool_queue );

}