//
// Created by erosp on 07/07/2021.
//

#include "../../Include/Objects/Weapon.h"

Weapon::Weapon() {}

void Weapon::update() {
    rect.setPosition(position);
    sprite.setPosition(rect.getPosition());
}

bool Weapon::use() {
    return false;
}