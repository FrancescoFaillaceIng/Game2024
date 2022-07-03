//
// Created by Francesco on 26/11/2021.
//

#ifndef GAME_PROJECTILE_H
#define GAME_PROJECTILE_H

#include "../Entity.h"
#include "../Characters/Hero.h"

#include "../ResourceIdentifier.h"
#include "../ResourceHolder.h"

class Projectile: public Entity{
public:
    enum ProjectileType {
        aoeProjectile,
        stProjectile
    };

    Projectile();

    virtual void Update();
    int getPower();
    virtual int getPspeed();

    ProjectileType projectileType;

    bool active = true;
    int Pspeed, power;
};


#endif //GAME_PROJECTILE_H
