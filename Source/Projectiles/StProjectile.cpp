//
// Created by Francesco on 23/05/2022.
//

#include "../../Include/Projectiles/StProjectile.h"

StProjectile::StProjectile(const TextureHolder &textures, sf::Vector2f vector): textures(textures) {
    setProjectileType(stProjectile);

    Pspeed = 10;
    power = 4;

    rect.setPosition(vector);
    rect.setSize(sf::Vector2f(10, 10));

    sprite.setTextureRect(sf::IntRect(0, 0, 15, 15));
    sprite.setPosition(rect.getPosition());

    texture = textures.get(Textures::StProjectile);
    sprite.setTexture(texture);
}