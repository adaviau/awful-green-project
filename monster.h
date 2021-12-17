#ifndef MONSTER_H
#define MONSTER_H

#include "actor.h"

class Monster : public Actor {

private:
    std::string stage;
    void setType( std::string );

public:
    Monster( std::string );
    Monster( std::string, Location& );
    std::string getStage();

    void activate();
// active : bool
// stage : string
// getStage : string


};

#endif