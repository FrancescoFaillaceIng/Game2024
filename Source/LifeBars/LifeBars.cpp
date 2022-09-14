//
// Created by Francesco on 21/07/2022.
//

#include "../../Include/LifeBars/LifeBars.h"

LifeBars::LifeBars(float x, float y, const TextureHolder &textures): textures(textures) {

    rect.setPosition(x, y);
    rect.setSize(sf::Vector2f(500, 125));

    sprite.setTextureRect(sf::IntRect(0, 0, 500, 100));
    sprite.setPosition(rect.getPosition());

    texture = textures.get(Textures::LifeBarText);
    sprite.setTexture(texture);
}

void LifeBars::update(float x, float y, int herolife) {
    rect.setPosition(x, y);
    sprite.setPosition(rect.getPosition());

    switch (herolife) {
        case 100:
            sprite.setTextureRect(sf::IntRect(0, 0, 500, 100));
            break;
        case 80:
            sprite.setTextureRect(sf::IntRect(0, 100, 500, 100));
            break;
        case 60:
            sprite.setTextureRect(sf::IntRect(0, 200, 500, 100));
            break;
        case 40:
            sprite.setTextureRect(sf::IntRect(0, 300, 500, 100));
            break;
        case 20:
            sprite.setTextureRect(sf::IntRect(0, 400, 500, 100));
            break;
    }
}

const sf::Sprite &LifeBars::getSprite() const {
    return sprite;
}
