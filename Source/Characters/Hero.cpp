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
            return Textures::AoeRanged;
    }
}

Hero::Hero(HeroType heroType, const TextureHolder& textures): textures(textures) {
    this->heroType = heroType;

    rect.setPosition(windowSize.x/2.f,windowSize.y/2.f);

    rect.setOrigin(32 / 2, 32 / 2);
    sprite.setOrigin(32 / 2, 32 / 2);
    sprite.setTextureRect(sf::IntRect(0,0,32,32));

    switch(heroType) {
        case Hero::HeroType::Melee:
            speedBasic = 5;
            hp = 200;
            hpMax = hp;
            attackDamage = 0;
            texture = textures.get(toTextureID(Melee));
            break;
        case Hero::HeroType::StRanged:
            speedBasic = 2;
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
