//
// Created by erosp on 06/07/2021.
//

#ifndef MAIN_CPP_PROJECTILE_H
#define MAIN_CPP_PROJECTILE_H

#include "Entity.h"
#include "ResourceIdentifier.h"
#include "ResourceHolder.h"

class Projectile: public Entity {
public:
    enum ProjectileType {
        stProjectile,
        aoeProjectile
    };

    Projectile(const TextureHolder& textures, ProjectileType projectileType);
    virtual void setPosition (const sf::Vector2f& position, Direction direction);
    virtual const sf::Sprite& getSprite();
    void update();

    ProjectileType projectileType;
    bool active;
    int range;
    int attackDamage;

private:
    const TextureHolder& textures;
    int counterWalk;
    sf::Vector2f initialPos;

    int movementSpeed = 10;
};

#endif //MAIN_CPP_PROJECTILE_H