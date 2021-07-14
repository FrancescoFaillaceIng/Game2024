//
// Created by erosp on 09/07/2021.
//

#ifndef MAIN_CPP_OBJECTFACTORY_H
#define MAIN_CPP_OBJECTFACTORY_H

#include "../ResourceHolder.h"
#include "../ResourceIdentifier.h"
#include "RangedWeapon.h"
#include "../Random.h"

class ObjectFactory: public Object {
public:
    std::shared_ptr<Object> createObject(Object::ObjectType objectType, const TextureHolder& textures);
    std::shared_ptr<Object> createObject(const TextureHolder& textures);

private:
    Object::ObjectType typeDrop();
};
#endif //MAIN_CPP_OBJECTFACTORY_H
