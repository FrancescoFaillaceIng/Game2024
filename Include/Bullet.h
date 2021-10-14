//
// Created by Francesco on 19/08/2021.
//

#ifndef GAME_BULLET_H
#define GAME_BULLET_H

#include "cmath"

#include "Entity.h"
#include "ResourceHolder.h"
#include "ResourceIdentifier.h"

class Bullet: public Entity{
public:
    enum BulletType{
        StBullet,
        AoeBullet
    };

    Bullet(const TextureHolder& textures, BulletType bulletType);

public:
    BulletType bulletType;
    bool active;
    int range;
    int attackDamage;

private:
    const TextureHolder& textures;

    int movementSpeed;
};


#endif //GAME_BULLET_H
