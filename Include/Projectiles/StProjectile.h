//
// Created by Francesco on 23/05/2022.
//

#ifndef GAME_STPROJECTILE_H
#define GAME_STPROJECTILE_H

#include "Projectile.h"

class StProjectile: public Projectile{
public:
    StProjectile(const TextureHolder &textures, sf::Vector2f vector);

    int getPspeed() override;

private:
    const TextureHolder &textures;

};


#endif //GAME_STPROJECTILE_H
