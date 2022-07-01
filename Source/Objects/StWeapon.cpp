//
// Created by erosp on 24/07/2021.
//

#include "../../Include/Objects/StWeapon.h"

StWeapon::StWeapon(const TextureHolder& textures): textures(textures){
    this->objectType = stWeapon;

    rect.setPosition(192, 192);
    rect.setSize(sf::Vector2f(32, 18));

    sprite.setTextureRect(sf::IntRect(0, 0, rect.getSize().x, rect.getSize().y));
    sprite.setPosition(rect.getPosition());

    texture = textures.get(Textures::StWeapon);
    sprite.setTexture(texture);
}

bool StWeapon::use() {
    return true;
}
