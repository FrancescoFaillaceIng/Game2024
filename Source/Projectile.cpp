//
// Created by erosp on 06/07/2021.
//

#include "..\Include\Projectile.h"

Textures::ID toTextureID(Projectile::ProjectileType projectileType) {
    switch (projectileType) {
        case Projectile::ProjectileType::aoeProjectile:
            return Textures::AoeProjectile;
        case Projectile::ProjectileType::stProjectile:
            return Textures::StProjectile;
    }
}

Projectile::Projectile(const TextureHolder& textures, ProjectileType projectileType): textures(textures), active(false),
counterWalk(0), projectileType(projectileType) {
    rect.setPosition(0, 0);
    texture = textures.get(toTextureID(projectileType));
    sprite.setTexture(texture);

    switch (projectileType) {
        case aoeProjectile:
            rect.setPosition(30, 30);
            rect.setSize(sf::Vector2f(30, 30));
            sprite.setTextureRect((sf::IntRect(0, 0, 58.5, 56)));
            attackDamage = 10;
            break;
        case stProjectile:
            rect.setPosition(18,  15);
            rect.setSize(sf::Vector2f(18, 15));
            sprite.setTextureRect((sf::IntRect(0, 0, 15, 15)));
            attackDamage = 5;
            break;
    }

    range = 400;
}

void Projectile::setPosition(const sf::Vector2f &position, Direction direction) {
    active = true;
    this->direction = direction;
    rect.move(position);
    sprite.setPosition(rect.getPosition());
    initialPos = rect.getPosition();
}

const sf::Sprite &Projectile::getSprite() {
    return Entity::getSprite();
}

void Projectile::update() {
    switch(direction) {
        case up:
            rect.move(0,-movementSpeed);
            break;
        case down:
            rect.move(0,movementSpeed);
            break;
        case left:
            rect.move(-movementSpeed,0);
            break;
        case right:
            rect.move(movementSpeed,0);
            break;
    }

    counterWalk++;
    if (counterWalk == 3)
        counterWalk = 0;

    if(projectileType == aoeProjectile)
        sprite.setTextureRect((sf::IntRect(counterWalk*58.5,0,58.5,56)));

    if(abs(rect.getPosition().x-initialPos.x) > range || abs(rect.getPosition().y-initialPos.y) > range)
        active = false;

    //keeps rect and sprite together
    sprite.setPosition(rect.getPosition());

}