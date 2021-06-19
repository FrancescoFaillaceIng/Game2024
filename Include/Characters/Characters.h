//
// Created by Francesco on 18/06/2021.
//

#ifndef GAME_CHARACTERS_H
#define GAME_CHARACTERS_H

#include <SFML\System.hpp>
#include "..\Entity.h"
#include "..\Textures\ResourceHolder.h"
#include "..\Textures\ResourceIdentifier.h"

class Characters: public Entity{
public:
    int hp;
    int hpMax;
    int attackDamage;
    int speedBasic;
};


#endif //GAME_CHARACTERS_H
