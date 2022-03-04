#ifndef EFFECT_H
#define EFFECT_H

#include <string>
#include <iostream>

enum EFFECT_TYPE { 
    _5_DICE_TO_KILL,
    _4_DICE_TO_KILL,
    _3_DICE_TO_KILL,
    _5_DICE_TO_STUN,
    _NO_EFFECT,
    _GROW,
    _SHRINK,
    _1_DIE_FRAGMENTS
};

class Effect {

private:
    int id;
    bool available;
    std::string name;
    EFFECT_TYPE type;
    std::string init();

    int dice_to_roll;

public:

    Effect();
    Effect( EFFECT_TYPE );

    bool is_kill_type();
    bool is_stun_type();
    bool is_grow_type();
    bool is_shrink_type();
    bool is_frag_type();

    bool is_available();

    void set_available();
    void set_unavailable();
    void set_type( EFFECT_TYPE );

    EFFECT_TYPE get_effect();
    int get_dice_count();
    std::string getName();
    int getID();

};

#endif