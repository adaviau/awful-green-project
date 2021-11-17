#include "crew.h"

Crew::Crew( std::string n, Location& l ) : Actor( n, CREW, l ) {

    alive = true;
    weapon = nullptr;
    setStats( 0, 0, 0 );

}