//
// Created by Francesco on 21/07/2022.
//

#include "../../Include/Objects/Potion.h"
Potion::Potion(float x, float y, const TextureHolder &textures): textures(textures) {
    this->objectType = potion;

    rect.setPosition(x, y);
    rect.setSize(sf::Vector2f(32, 32));

    sprite.setTextureRect(sf::IntRect(0, 0, rect.getSize().x, rect.getSize().y));
    sprite.setPosition(rect.getPosition());

    texture = textures.get(Textures::PotionText);
    sprite.setTexture(texture);
}
