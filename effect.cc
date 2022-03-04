#include "effect.h"


static int UNIQUE_IDENTIFIER = 1000;

Effect::Effect() : id( ++UNIQUE_IDENTIFIER ), available( true ) { }

Effect::Effect( EFFECT_TYPE t ) : Effect() {

    set_type( t );

}

void Effect::set_type( EFFECT_TYPE t ) {

    type = t;
    name = std::to_string( id ) + " - " + init();

    // std::cout << "DEBUG- Constructor(Effect) - Name:" << name << std::endl; 

}

std::string Effect::init() {

    switch( type ) {
        
        case     _5_DICE_TO_KILL:
            dice_to_roll = 5;
            return "5 Dice to Kill";
        case     _4_DICE_TO_KILL:
            dice_to_roll = 4;
            return "4 Dice to Kill";
        case     _3_DICE_TO_KILL:
            dice_to_roll = 3;
            return "3 Dice to Kill";
        case     _5_DICE_TO_STUN:
            dice_to_roll = 5;
            return "5 Dice to Stun";
        case     _NO_EFFECT:
            dice_to_roll = 0;
            return "No Effect";
        case     _GROW:
            dice_to_roll = 0;
            return "Grow";
        case     _SHRINK:
            dice_to_roll = 0;
            return "Shrink";
        case     _1_DIE_FRAGMENTS:
            dice_to_roll = 1;
            return "1 Die Fragments";
        default:
            dice_to_roll = 0;
            return "Invalid Type";

    }

}
    
bool Effect::is_kill_type() {

    return  (type == _5_DICE_TO_KILL) || 
            (type == _4_DICE_TO_KILL) || 
            (type == _3_DICE_TO_KILL);

}
bool Effect::is_stun_type() {

    return  (type == _5_DICE_TO_STUN);

}
bool Effect::is_grow_type() {

    return  (type == _GROW);
    
}
bool Effect::is_shrink_type() {

    return  (type == _SHRINK);
    
}
bool Effect::is_frag_type() {

    return  (type == _1_DIE_FRAGMENTS);
    
}

bool Effect::is_available() {   return available;   }

void Effect::set_available() {  available = true;   }

void Effect::set_unavailable() {  available = false;   }

EFFECT_TYPE Effect::get_effect() {  return type;    }

int Effect::get_dice_count() {  return dice_to_roll;    }

std::string Effect::getName() {   return name;  }

int Effect::getID() {   return id;  }
