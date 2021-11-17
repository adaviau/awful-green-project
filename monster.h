#ifndef MONSTER_H
#define MONSTER_H

#include "actor.h"

class Monster : public Actor {

private:
    std::string stage;
    bool active;
    void setType( std::string );

public:
    Monster( std::string );
    Monster( std::string, Location& );
    bool isActive();
    std::string getStage();

    
// active : bool
// stage : string

// isActive() : bool
// getStage : string


};

#endif