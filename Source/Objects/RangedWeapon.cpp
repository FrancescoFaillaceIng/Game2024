//
// Created by erosp on 07/07/2021.
//

#include "../../Include/Objects/RangedWeapon.h"

Textures::ID toTextureID(RangedWeapon::RangedWeaponType rangedWeaponType) {
    switch (rangedWeaponType) {
        case RangedWeapon::RangedWeaponType::aoeWeapon:
            return Textures::AoeWeapon;
        case RangedWeapon::RangedWeaponType::stWeapon:
            return Textures::StWeapon;
    }
}

RangedWeapon::RangedWeapon(const TextureHolder &textures, RangedWeapon::RangedWeaponType rangedWeaponType): textures(textures), weaponType(rangedWeaponType) {
    equipped = false;
    this->objectType = Object::ObjectType::rangedWeapon;

    switch (rangedWeaponType) {
        case RangedWeaponType::aoeWeapon:
            projectileType = Projectile::ProjectileType::aoeProjectile;
            weaponType = aoeWeapon;
            break;
        case RangedWeaponType::stWeapon:
            projectileType = Projectile::ProjectileType::stProjectile;
            rangedWeaponType = stWeapon;
            break;
    }

    counterLifeTime = 1;
    range = 400;
    power = 10;

    texture = textures.get(toTextureID(rangedWeaponType));
    sprite.setTexture(texture);

    rect.setPosition(sf::Vector2f(300,300));
    rect.setOrigin(32/2,23/2);
    sprite.setOrigin(32/2,23/2);
    rect.setSize(sf::Vector2f(32,23));
    sprite.setPosition(rect.getPosition());
}

void RangedWeapon::update() {
    Weapon::update();
}

void RangedWeapon::changeType(RangedWeapon::RangedWeaponType rangedWeaponType) {
    switch (rangedWeaponType) {
        case RangedWeaponType::aoeWeapon:
            weaponType = aoeWeapon;
            projectileType = Projectile::ProjectileType::aoeProjectile;
            break;
        case RangedWeaponType::stWeapon:
            weaponType = stWeapon;
            projectileType = Projectile::ProjectileType::stProjectile;
            break;
    }

    texture = textures.get(toTextureID(rangedWeaponType));
    sprite.setTexture(texture);
}