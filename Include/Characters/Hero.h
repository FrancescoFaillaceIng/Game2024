//
// Created by Francesco on 18/06/2021.
//

#ifndef GAME_HERO_H
#define GAME_HERO_H

#include <string>
#include "Characters.h"

class Hero: public Characters{
public:
    enum HeroType{
        Melee,
        StRanged,
        AoeRanged,
    };
    Hero(HeroType heroType);

    HeroType heroType;
};


#endif //GAME_HERO_H
