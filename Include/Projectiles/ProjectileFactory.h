//
// Created by Francesco on 23/05/2022.
//

#ifndef GAME_PROJECTILEFACTORY_H
#define GAME_PROJECTILEFACTORY_H

#include "StProjectile.h"

class ProjectileFactory: public Projectile{
public:
    std::shared_ptr<Projectile> createProjectile(Projectile::ProjectileType projectileType, const TextureHolder &textures,
                                                 sf::Vector2f vector);

};


#endif //GAME_PROJECTILEFACTORY_H
