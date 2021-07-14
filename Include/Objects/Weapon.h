//
// Created by erosp on 07/07/2021.
//

#ifndef MAIN_CPP_WEAPON_H
#define MAIN_CPP_WEAPON_H

#include "Object.h"

class Weapon: public Object {
public:
    Weapon();
    void update() override;
    bool use() override;

    int range;
    int power;
};
#endif //MAIN_CPP_WEAPON_H
