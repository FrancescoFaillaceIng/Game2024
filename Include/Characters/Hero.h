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
    Hero(HeroType heroType, const TextureHolder& textures);

    virtual const sf::Sprite &getSprite() override;
    HeroType heroType;

    sf::Vector2u windowSize;
    const TextureHolder& textures;
};


#endif //GAME_HERO_H
