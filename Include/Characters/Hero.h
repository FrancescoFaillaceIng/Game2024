//
// Created by Francesco on 18/06/2021.
//

#ifndef GAME_HERO_H
#define GAME_HERO_H

#include <string>
#include "Characters.h"
#include "../Objects/StWeapon.h"

class Hero: public Characters{
public:
    enum HeroType{
        Melee,
        StRanged,
        AoeRanged,
    };
    Hero(HeroType heroType, const TextureHolder& textures);

    virtual const sf::Sprite &getSprite() override;
    bool PickUpObject(std::shared_ptr<Object> object);
    void ChangeWeapon(std::shared_ptr<Weapon> newWeapon);

    HeroType heroType;
    std::shared_ptr<Weapon> weapon;

    sf::Vector2u windowSize;
    const TextureHolder& textures;
};


#endif //GAME_HERO_H
