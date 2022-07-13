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

    void setProjectileType(ProjectileType projectileType);

    void Update();
    int getPower();
    int getPspeed();

    bool active = true;

protected:
    ProjectileType projectileType;

    int Pspeed, power;
};


#endif //GAME_PROJECTILE_H
