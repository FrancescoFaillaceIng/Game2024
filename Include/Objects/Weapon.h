//
// Created by erosp on 24/07/2021.
//

#ifndef MAIN_CPP_WEAPON_H
#define MAIN_CPP_WEAPON_H

#include "Object.h"

class Weapon: public Object {
public:
    enum WeaponType {
        stWeapon
    };

    Weapon();

    WeaponType weaponType;
};
#endif //MAIN_CPP_WEAPON_H
