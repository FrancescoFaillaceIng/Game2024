//
// Created by Francesco on 27/07/2021.
//

#ifndef GAME_OBJECTFACTORY_H
#define GAME_OBJECTFACTORY_H

#include "StWeapon.h"
#include "../ResourceHolder.h"
#include "../ResourceIdentifier.h"

class ObjectFactory: public Object{
public:
    std::shared_ptr<Object> createObject(Object::ObjectType type, const TextureHolder&textures);
};


#endif //GAME_OBJECTFACTORY_H
