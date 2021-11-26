//
// Created by Francesco on 14/10/2021.
//

#include "../Include/Random.h"

int GenerateRandom(int max) {

    int random = (rand() % max)+1;
    return random;
}