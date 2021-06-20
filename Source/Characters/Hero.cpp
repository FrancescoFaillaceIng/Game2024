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

Hero::Hero(HeroType heroType, const TextureHolder& textures) {
    sf::Texture textureHero;
    textureHero.loadFromFile(R"(Resources/HeroSprite.png)");
    sprite.setTexture(textureHero);
    rect.setOrigin(32 / 2, 32 / 2);
    rect.setSize(sf::Vector2f(32, 32));
    sprite.setOrigin(32 / 2, 32 / 2);
    sprite.setTextureRect(sf::IntRect(0,0,32,32));
    rect.setFillColor(sf::Color::Transparent);

    texture = textures.get(toTextureID(heroType));
    sprite.setTexture(texture);

    switch(heroType) {
        case Hero::HeroType::Melee:
            speedBasic = 5;
            hp = 200;
            hpMax = hp;
            attackDamage = 0;
            //texture = textures.get(toTextureID(heroType));
            //sprite.setTexture(texture);
            break;
        case Hero::HeroType::StRanged:
            speedBasic = 2;
            hp = 200;
            hpMax = hp;
            attackDamage = 0;
            break;
        case Hero::HeroType::AoeRanged:
            speedBasic = 3;
            hp = 200;
            hpMax = hp;
            attackDamage = 0;
            break;
    }
}

const sf::Sprite &Hero::getSprite() {
    return Entity::getSprite();
}
