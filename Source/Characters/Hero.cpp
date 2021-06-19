//
// Created by Francesco on 18/06/2021.
//

#include "../../Include/Characters/Hero.h"

Textures::ID toTextureID(Hero::HeroType heroType) {
    switch(heroType) {
        /*case Hero::HeroType::close:
            return Textures::???;*/
        case Hero::HeroType::StRanged:
            return Textures::stHero;
        case Hero::HeroType::AoeRanged:
            return Textures::aoeHero;
    }
}

/*Hero::Hero(HeroType heroType, float x, float y) {
    this->heroType = heroType;

    rect.setOrigin(32 / 2, 32 / 2);
    sprite.setOrigin(32 / 2, 32 / 2);
    sprite.setTextureRect(sf::IntRect(0,0,32,32));

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
            texture = textures.get(toTextureID(heroType));
            sprite.setTexture(texture);
            break;
        case Hero::HeroType::AoeRanged:
            speedBasic = 3;
            hp = 200;
            hpMax = hp;
            attackDamage = 0;
            texture = textures.get(toTextureID(heroType));
            sprite.setTexture(texture);
            break;
    }
}
 */