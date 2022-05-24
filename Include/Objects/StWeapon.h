//
// Created by erosp on 24/07/2021.
//

#ifndef MAIN_CPP_STWEAPON_H
#define MAIN_CPP_STWEAPON_H

#include "Weapon.h"

class StWeapon: public Weapon {
public:
    StWeapon(const TextureHolder &textures);

    bool use();

private:
    const TextureHolder &textures;

};

#endif //MAIN_CPP_STWEAPON_H
