//
// Created by Francesco on 18/06/2021.
//

#ifndef GAME_CHARACTERS_H
#define GAME_CHARACTERS_H

#include <SFML\System.hpp>
#include "..\Entity.h"
#include "..\ResourceHolder.h"
#include "..\ResourceIdentifier.h"

class Characters: public Entity{
public:
    int hp;
    int hpMax;
    int attackDamage;
    int speedBasic;
    int counterWalking = 0;
    bool isMovingUp, isMovingDown, isMovingLeft, isMovingRight;

    Characters();
    virtual void Update();

};


#endif //GAME_CHARACTERS_H
