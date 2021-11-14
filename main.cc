#include <iostream>

#include "location.h"
#include "entity.h"
#include "manifest.h"
#include "map.h"

void buildMap( Map& m ) {

    Location kitchen( "Kitchen", 0 );
    Location bathroom( "Bathroom", 1 );
    Location basement( "Basement", 2 );
    m.add( kitchen );
    m.add( bathroom );
    m.add( basement );

}

void buildManifest( Manifest& m ) {

    Entity andrew( "Andrew", CREW );
    Entity denis( "Denis", CREW );
    m.add( andrew );
    m.add( denis );

}

int main() {

    Map map;
    Manifest crew;
    buildMap( map );
    buildManifest( crew );

    Entity * andrew = &crew[0];
    Location * kitchen = &map[0];

    andrew->enter( *kitchen );

    map.debug();
    crew.debug();

    return 0;

}