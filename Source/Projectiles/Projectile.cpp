//
// Created by Francesco on 26/11/2021.
//

#include "../../Include/Projectiles/Projectile.h"

Projectile::Projectile(): active(false) {

}

void Projectile::Update() {
        float x = rect.getPosition().x;
        float y = rect.getPosition().y;
        sprite.setPosition(x,y);
        switch (direction) {
            case up:
                rect.move(0, -Pspeed);
                break;
            case down:
                rect.move(0, +Pspeed);
                break;
            case left:
                rect.move(-Pspeed, 0);
                break;
            case right:
                rect.move(+Pspeed, 0);
                break;
        }
}

int Projectile::getPower() {
    return power;
}

int Projectile::getPspeed() {
    return Pspeed;
}

void Projectile::setProjectileType(Projectile::ProjectileType projectileType) {
    Projectile::projectileType = projectileType;
}


