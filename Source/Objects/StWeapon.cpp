//
// Created by erosp on 24/07/2021.
//

#include "../../Include/Objects/StWeapon.h"

StWeapon::StWeapon(const TextureHolder& textures): textures(textures){
    this->objectType = stWeapon;

    rect.setPosition(64, 64);
    rect.setSize(sf::Vector2f(31.7, 31.7));

    sprite.setTextureRect(sf::IntRect(0, 0, 31.7, 31.7));
    sprite.setPosition(rect.getPosition());

    texture = textures.get(Textures::StWeapon);
    sprite.setTexture(texture);
}

const sf::Sprite &StWeapon::getSprite() {
    return Entity::getSprite();
}