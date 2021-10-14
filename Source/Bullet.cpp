//
// Created by Francesco on 19/08/2021.
//

#include "../Include/Bullet.h"

Textures::ID toTextureID(Bullet::BulletType bulletType) {
    switch(bulletType) {
        case Bullet::BulletType::StBullet:
            return Textures::StBullet;
            case Bullet::BulletType::AoeBullet:
                return Textures::AoeBullet;
    }
}

Bullet::Bullet(const TextureHolder &textures, BulletType bulletType): textures(textures), active(false), bulletType(bulletType) {

    rect.setPosition(0, 0);
    texture = textures.get(toTextureID(bulletType));
    sprite.setTexture(texture);

    switch(bulletType) {
        //TODO controllare valori origin e size
        case StBullet:
            rect.setOrigin(30 / 2, 30 / 2);
            sprite.setOrigin(56 / 2, 56 / 2);
            rect.setSize(sf::Vector2f(30, 30));
            sprite.setTextureRect((sf::IntRect(0, 0, 56, 56)));
            attackDamage = 5;
            range = 400;
            movementSpeed = 10;
            break;
        case AoeBullet:
            rect.setOrigin(18 / 2,  15/ 2);
            sprite.setOrigin(18 / 2, 15 / 2);
            rect.setSize(sf::Vector2f(18, 15));
            sprite.setTextureRect((sf::IntRect(0, 0, 18, 15)));
            attackDamage = 10;
            range = 250;
            movementSpeed = 5;
            break;
    }
}
