//
// Created by erosp on 24/07/2021.
//

#ifndef MAIN_CPP_OBJECT_H
#define MAIN_CPP_OBJECT_H

#include "../Entity.h"
#include "..\ResourceHolder.h"
#include "..\ResourceIdentifier.h"

class Object: public Entity {
public:
    enum ObjectType {
        stWeapon
    };

    Object();

    ObjectType objectType;

    bool active = true;
    bool equipped;
};

#endif //MAIN_CPP_OBJECT_H
