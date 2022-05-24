//
// Created by Francesco on 23/05/2022.
//

#include "../../Include/Projectiles/ProjectileFactory.h"

std::shared_ptr<Projectile> ProjectileFactory::createProjectile(Projectile::ProjectileType projectileType,
                                                                const TextureHolder &textures, sf::Vector2f vector) {
    std::shared_ptr<Projectile> projectile;

    switch (projectileType) {
        case Projectile::stProjectile:
            projectile = std::make_shared<StProjectile>(textures, vector);
            this->projectileType = stProjectile;
    }
    return projectile;
}