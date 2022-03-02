
#include "initializer.h"

void Initializer::build_complete_map( Map& m ) {

    Location sensor_1 ("SENSOR_1", 0, { 32 }, { 33, 34 }, { } );
    Location crew_quarters_1 ("CREW_QUARTERS_1", 1, { 32 }, { 33, 34 }, { } );
    Location captain_cabin ("CAPTAIN_CABIN", 2, { 18, 3 }, { }, { } );
    Location bridge_1 ("BRIDGE_1", 3, { 2, 19, 36 }, { 35 }, { } );
    Location main_cargo_hold ("MAIN_CARGO_HOLD", 4, { 36, 21, 22 }, { 35 }, { } );
    Location bridge_2 ("BRIDGE_2", 5, { 23, 41 }, { 40 }, { } );
    Location crew_quarters_2 ("CREW_QUARTERS_2", 6, { 41 }, { 40 }, { } );
    Location pool_room ("POOL_ROOM", 7, { 42 }, { 40 }, { } );
    Location fuel_pod_1 ("FUEL_POD_1", 8, { 42 }, { 40 }, { } );
    Location engine_room ("ENGINE_ROOM", 9, { 42, 25, 44 }, { 40, 43 }, { } );
    Location fuel_pod_2 ("FUEL_POD_2", 10, { 44 }, { 43 }, { } );
    Location crew_quarters_3 ("CREW_QUARTERS_3", 11, { 44 }, { 43 }, { } );
    Location sensor_2 ("SENSOR_2", 12, { 26 }, { }, { } );
    Location scout_bay ("SCOUT_BAY", 13, { 26, 14 }, { }, { } );
    Location cockboat_bay ("COCKBOAT_BAY", 14, { 38, 13, 15 }, { 37 }, { } );
    Location saucer_bay ("SAUCER_BAY", 15, { 14, 29, 30 }, { }, { } );
    Location atmosphere_probe_launch ("ATMOSPHERE_PROBE_LAUNCH", 16, { 30, 17 }, { }, { } );
    Location atmosphere_probe_control ("ATMOSPHERE_PROBE_CONTROL", 17, { 16, 32 }, { 33, 34 }, { } );
    Location computer ("COMPUTER", 18, { 2 }, { }, { } );
    Location officer_quarters ("OFFICER_QUARTERS", 19, { 3, 33 }, { 32, 34 }, { } );
    Location ward_room ("WARD_ROOM", 20, { 35 }, { 36 }, { } );
    Location galley ("GALLEY", 21, { 35, 4, 23 }, { 36 }, { } );
    Location ship_store ("SHIP_STORE", 22, { 4, 23 }, { }, { } );
    Location mess_deck ("MESS_DECK", 23, { 21, 22, 5, 37 }, { 39 }, { } );
    Location science_lab ("SCIENCE_LAB", 24, { 39 }, { 37 }, { } );
    Location aft_machine_shop ("AFT_MACHINE_SHOP", 25, { 9, 43 }, { 44 }, { } );
    Location crew_quarters_4 ("CREW_QUARTERS_4", 26, { 43, 12, 13 }, { 44 }, { } );
    Location hospital_ward ("HOSPITAL_WARD", 27, { 28 }, { }, { } );
    Location sick_bay ("SICK_BAY", 28, { 27, 37, 38 }, { 39 }, { } );
    Location damage_control ("DAMAGE_CONTROL", 29, { 15, 30, 34 }, { 33, 32 }, { } );
    Location machine_shop ("MACHINE_SHOP", 30, { 29, 15, 16, 31, 33 }, { 32, 34 }, { } );
    Location life_support_center ("LIFE_SUPPORT_CENTER", 31, { 30 }, { }, { } );
    Location hall_1_1 ("HALL_1_1", 32, { 0, 1, 17, 33 }, { 34 }, { 33, 34 } );
    Location hall_1_2 ("HALL_1_2", 33, { 19, 30, 32, 34 }, { }, { 32, 34 } );
    Location hall_1_3 ("HALL_1_3", 34, { 33, 35, 37, 29 }, { 36, 39, 32, 38 }, { 33, 32 } );
    Location hall_2_1 ("HALL_2_1", 35, { 36, 21, 34, 20 }, { 33, 32 }, { 36 } );
    Location hall_2_2 ("HALL_2_2", 36, { 3, 4, 35 }, { }, { 35 } );
    Location hall_3_1 ("HALL_3_1", 37, { 34, 23, 39, 28, 38 }, { 33, 32 }, { 38, 39 } );
    Location hall_3_2 ("HALL_3_2", 38, { 37, 28, 14 }, { 39 }, { 37, 39 } );
    Location hall_3_3 ("HALL_3_3", 39, { 24, 40, 43, 37 }, { 42, 44 }, { 37, 38 } );
    Location hall_4_1 ("HALL_4_1", 40, { 41, 42, 39 }, { 37 }, { 41, 42 } );
    Location hall_4_2 ("HALL_4_2", 41, { 5, 6, 40 }, { 42 }, { 40, 42 } );
    Location hall_4_3 ("HALL_4_3", 42, { 7, 8, 9, 40 }, { }, { 40, 41 } );
    Location hall_5_1 ("HALL_5_1", 43, { 39, 25, 44, 26 }, { 37 }, { 44 } );
    Location hall_5_2 ("HALL_5_2", 44, { 9, 10, 11, 43 }, { }, { 43 } );

    m.add(	sensor_1	);
    m.add(	crew_quarters_1	);
    m.add(	captain_cabin	);
    m.add(	bridge_1	);
    m.add(	main_cargo_hold	);
    m.add(	bridge_2	);
    m.add(	crew_quarters_2	);
    m.add(	pool_room	);
    m.add(	fuel_pod_1	);
    m.add(	engine_room	);
    m.add(	fuel_pod_2	);
    m.add(	crew_quarters_3	);
    m.add(	sensor_2	);
    m.add(	scout_bay	);
    m.add(	cockboat_bay	);
    m.add(	saucer_bay	);
    m.add(	atmosphere_probe_launch	);
    m.add(	atmosphere_probe_control	);
    m.add(	computer	);
    m.add(	officer_quarters	);
    m.add(	ward_room	);
    m.add(	galley	);
    m.add(	ship_store	);
    m.add(	mess_deck	);
    m.add(	science_lab	);
    m.add(	aft_machine_shop	);
    m.add(	crew_quarters_4	);
    m.add(	hospital_ward	);
    m.add(	sick_bay	);
    m.add(	damage_control	);
    m.add(	machine_shop	);
    m.add(	life_support_center	);
    m.add(	hall_1_1	);
    m.add(	hall_1_2	);
    m.add(	hall_1_3	);
    m.add(	hall_2_1	);
    m.add(	hall_2_2	);
    m.add(	hall_3_1	);
    m.add(	hall_3_2	);
    m.add(	hall_3_3	);
    m.add(	hall_4_1	);
    m.add(	hall_4_2	);
    m.add(	hall_4_3	);
    m.add(	hall_5_1	);
    m.add(	hall_5_2	);

}

void Initializer::build_test_map( Map& m ) {

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

void Initializer::build_complete_crew( Manifest& m ) {

    Crew * captain_yid = new Crew( "CAPTAIN_YID");
    Crew * _1st_ofcr = new Crew( "1ST_OFCR");
    Crew * comm_ofcr = new Crew( "COMM_OFCR");
    Crew * ops_ofcr = new Crew( "OPS_OFCR");
    Crew * enginner_ofcr = new Crew( "ENGINNER_OFCR");
    Crew * supply_ofcr = new Crew( "SUPPLY_OFCR");
    Crew * doc = new Crew( "DOC");
    Crew * medic = new Crew( "MEDIC");
    Crew * sparks = new Crew( "SPARKS");
    Crew * sarge = new Crew( "SARGE");
    Crew * marine_1 = new Crew( "MARINE");
    Crew * marine_2 = new Crew( "MARINE");
    Crew * cook = new Crew( "COOK");
    Crew * yeoman = new Crew( "YEOMAN");
    Crew * tech = new Crew( "TECH");
    Crew * engineer = new Crew( "ENGINEER");
    Crew * machinist = new Crew( "MACHINIST");
    Crew * coxswain = new Crew( "COXSWAIN");
    Crew * pilot_1 = new Crew( "PILOT");
    Crew * pilot_2 = new Crew( "PILOT");
    Crew * robot = new Crew( "ROBOT");
    Crew * mascot = new Crew( "MASCOT");

    captain_yid->setStats( 3 , 27 , 3 );
    _1st_ofcr->setStats( 3 , 19 , 2 );
    comm_ofcr->setStats( 4 , 11 , 1 );
    ops_ofcr->setStats( 3 , 12 , 1 );
    enginner_ofcr->setStats( 3 , 12 , 1 );
    supply_ofcr->setStats( 2 , 11 , 1 );
    doc->setStats( 4 , 11 , 1 );
    medic->setStats( 4 , 11 , 1 );
    sparks->setStats( 3 , 16 , 1 );
    sarge->setStats( 3 , 21 , 3 );
    marine_1->setStats( 3 , 19 , 2 );
    marine_2->setStats( 3 , 18 , 2 );
    cook->setStats( 3 , 21 , 1 );
    yeoman->setStats( 3 , 15 , 1 );
    tech->setStats( 4 , 11 , 1 );
    engineer->setStats( 2 , 13 , 2 );
    machinist->setStats( 2 , 14 , 2 );
    coxswain->setStats( 3 , 18 , 2 );
    pilot_1->setStats( 3 , 15 , 1 );
    pilot_2->setStats( 3 , 12 , 1 );
    robot->setStats( 1 , 44 , 4 );
    robot->set_robot();
    mascot->setStats( 4 , 8 , 1 );
    mascot->set_mascot();

    m.add( *captain_yid );
    m.add( *_1st_ofcr );
    m.add( *comm_ofcr );
    m.add( *ops_ofcr );
    m.add( *enginner_ofcr );
    m.add( *supply_ofcr );
    m.add( *doc );
    m.add( *medic );
    m.add( *sparks );
    m.add( *sarge );
    m.add( *marine_1 );
    m.add( *marine_2 );
    m.add( *cook );
    m.add( *yeoman );
    m.add( *tech );
    m.add( *engineer );
    m.add( *machinist );
    m.add( *coxswain );
    m.add( *pilot_1 );
    m.add( *pilot_2 );
    m.add( *robot );
    m.add( *mascot );

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

void Initializer::build_complete_monsters( Manifest& m, int e, int b, int a ) {

    int eggs_to_place = e;
    int babies_to_place = b;
    int adults_to_place = a;

    for ( int i=0; i<eggs_to_place; ++i ) {

        Monster * egg = new Monster( "EGG" );
        m.add( *egg );

    }

    for ( int i=0; i<babies_to_place; ++i ) {

        Monster * baby = new Monster( "BABY" );
        m.add( *baby );

    }

    for ( int i=0; i<adults_to_place; ++i ) {

        Monster * adult = new Monster( "ADULT" );
        m.add( *adult );

    }

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
