//
// Created by Francesco on 18/06/2021.
//

#include <memory>
#include "../../Include/Characters/Hero.h"

Textures::ID toTextureID(Hero::HeroType heroType) {
    switch(heroType) {
        case Hero::HeroType::Melee:
            return Textures::MeleeHero;
        case Hero::HeroType::StRanged:
            return Textures::StHero;
        case Hero::HeroType::AoeRanged:
            return Textures::AoeHero;
    }
}

Hero::Hero(Hero::HeroType heroType, const TextureHolder& textures): textures(textures) {

    rect.setPosition(100, 100);
    rect.setSize(sf::Vector2f(32, 32));

    sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    sprite.setPosition(rect.getPosition());

    switch(heroType) {
        case Hero::HeroType::Melee:
            speedBasic = 5;
            hp = 200;
            hpMax = hp;
            attackDamage = 0;
            texture = textures.get(toTextureID(Melee));
            break;
        case Hero::HeroType::StRanged:
            speedBasic = 4;
            hp = 200;
            hpMax = hp;
            attackDamage = 0;
            texture = textures.get(toTextureID(StRanged));
            break;
        case Hero::HeroType::AoeRanged:
            speedBasic = 3;
            hp = 200;
            hpMax = hp;
            attackDamage = 0;
            texture = textures.get(toTextureID(AoeRanged));
            break;
    }
    sprite.setTexture(texture);
}

bool Hero::PickUpObject(std::shared_ptr<Object> object) {
    std::shared_ptr<Weapon> WeaponPicked = std::dynamic_pointer_cast<Weapon>(object);
    if(WeaponPicked) {
        ChangeWeapon(WeaponPicked);
        return true;
    } else {
        return false;
    }
}

void Hero::ChangeWeapon(std::shared_ptr<Weapon> newWeapon) {
    if(newWeapon) {
        if(inventory.addItem(this->weapon)) {
            this->weapon = newWeapon;
            this->weapon->equipped = true;
        }
    }
}

void Hero::SearchForWeapon() {
    std::shared_ptr<Object> obj = inventory.getElement(Object::stWeapon);
    std::shared_ptr<StWeapon> newWeapon = std::dynamic_pointer_cast<StWeapon>(obj);
    if(newWeapon != nullptr) {
        ChangeWeapon(newWeapon);
    }
}

bool Hero::Shoot() {
    if(weapon == nullptr) {
        std::cout<<"you don't have a weapon"<<std::endl;
        return false;
    }else return true;
}

const std::shared_ptr<Weapon> &Hero::getWeapon() const {
    return weapon;
}

void Hero::setWeapon(const std::shared_ptr<Weapon> &weapon) {
    Hero::weapon = weapon;
}

const sf::Vector2u &Hero::getWindowSize() const {
    return windowSize;
}

void Hero::setWindowSize(const sf::Vector2u &windowSize) {
    Hero::windowSize = windowSize;
}

const TextureHolder &Hero::getTextures() const {
    return textures;
}

Hero::HeroType Hero::getHeroType() const {
    return heroType;
}

void Hero::setHeroType(Hero::HeroType heroType) {
    Hero::heroType = heroType;
}


