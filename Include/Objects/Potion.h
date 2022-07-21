//
// Created by Francesco on 21/07/2022.
//

#ifndef GAME_POTION_H
#define GAME_POTION_H

#include "Object.h"

class Potion: public Object{
public:
    Potion(float x, float y, const TextureHolder &textures);

protected:
    const TextureHolder &textures;
};


#endif //GAME_POTION_H
