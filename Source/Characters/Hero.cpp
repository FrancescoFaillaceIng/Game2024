//
// Created by Francesco on 18/06/2021.
//

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

Hero::Hero(HeroType heroType, const TextureHolder& textures): textures(textures) {
    this->heroType = heroType;

    rect.setPosition(32, 32);
    rect.setSize(sf::Vector2f(31.7, 31.7));

    sprite.setTextureRect(sf::IntRect(0, 0, 31.7, 31.7));
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

const sf::Sprite &Hero::getSprite() {
    return Entity::getSprite();
}
