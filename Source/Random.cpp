//
// Created by erosp on 09/07/2021.
//

#include "../Include/Random.h"

int generateRandom(int max) {

    int random = (rand() % max)+1;
    return random;
}