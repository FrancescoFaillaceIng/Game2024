//
// Created by Francesco on 21/07/2022.
//

#ifndef GAME_COINS_H
#define GAME_COINS_H

#include "Object.h"

class Coins: public Object{
public:
    Coins(float x, float y, const TextureHolder &textures);

protected:
    const TextureHolder &textures;
};


#endif //GAME_COINS_H
