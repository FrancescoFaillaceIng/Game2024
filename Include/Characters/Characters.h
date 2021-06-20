//
// Created by Francesco on 18/06/2021.
//

#ifndef GAME_CHARACTERS_H
#define GAME_CHARACTERS_H

#include <SFML\System.hpp>
#include "..\Entity.h"

class Characters: public Entity{
public:
    int hp;
    int hpMax;
    int attackDamage;
    int speedBasic;
    int counterWalking = 0;

    Characters();
    virtual void UpdateMovement();
    virtual const sf::Sprite &getSprite() override;
};


#endif //GAME_CHARACTERS_H
