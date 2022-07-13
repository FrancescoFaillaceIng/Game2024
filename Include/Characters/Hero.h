//
// Created by Francesco on 18/06/2021.
//

#ifndef GAME_HERO_H
#define GAME_HERO_H

#include <string>
#include <memory>
#include "Characters.h"
#include "..\Inventory.h"

class Hero: public Characters{
public:
    enum HeroType{
        Melee,
        StRanged,
        AoeRanged,
    };

    Hero(Hero::HeroType heroType, const TextureHolder& textures);

    bool PickUpObject(std::shared_ptr<Object> object);
    void ChangeWeapon(std::shared_ptr<Weapon> newWeapon);

    bool Shoot();

    const std::shared_ptr<Weapon> &getWeapon() const;

    //sf::Text textHero_HP("HP ", font, 20);
    //textHero_HP.setFillColor(sf::Color::Green);

protected:
    HeroType heroType;

    std::shared_ptr<Weapon> weapon;
    std::shared_ptr<Inventory> inventory;

    sf::Vector2u windowSize;
    const TextureHolder& textures;
};


#endif //GAME_HERO_H
