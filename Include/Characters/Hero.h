//
// Created by Francesco on 18/06/2021.
//

#ifndef GAME_HERO_H
#define GAME_HERO_H

#include <string>
#include <memory>
#include "Characters.h"
#include "..\Objects\StWeapon.h"
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
    void SearchForWeapon();

    bool Shoot();

    HeroType getHeroType() const;

    const std::shared_ptr<Weapon> &getWeapon() const;

    void setHeroType(HeroType heroType);

    void setWeapon(const std::shared_ptr<Weapon> &weapon);
    void setWindowSize(const sf::Vector2u &windowSize);

    const sf::Vector2u &getWindowSize() const;
    const TextureHolder &getTextures() const;

protected:
    HeroType heroType;

    std::shared_ptr<Weapon> weapon;

    sf::Vector2u windowSize;
    const TextureHolder& textures;

    Inventory inventory;
};


#endif //GAME_HERO_H
