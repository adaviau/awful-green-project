#ifndef MONSTER_H
#define MONSTER_H

#include "actor.h"

class Monster : public Actor {

private:
    std::string stage;

public:
    Monster( std::string );
    Monster( std::string, Location& );
    std::string getStage();
    void setType( std::string );

    // void activate();
    void grow();
// active : bool
// stage : string
// getStage : string


};

#endif