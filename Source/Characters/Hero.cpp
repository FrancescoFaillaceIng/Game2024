//
// Created by Francesco on 18/06/2021.
//

#include "../../Include/Characters/Hero.h"

Hero::Hero(HeroType heroType) {
    sf::Texture textureHero;
    textureHero.loadFromFile(R"(Resources/HeroSprite.png)");
    sprite.setTexture(textureHero);
    rect.setOrigin(32 / 2, 32 / 2);
    rect.setSize(sf::Vector2f(32, 32));
    sprite.setOrigin(32 / 2, 32 / 2);
    sprite.setTextureRect(sf::IntRect(0,0,32,32));
    rect.setFillColor(sf::Color::Transparent);

    this->heroType = heroType;


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