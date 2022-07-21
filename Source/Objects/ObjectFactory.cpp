//
// Created by Francesco on 27/07/2021.
//

#include "../../Include/Objects/ObjectFactory.h"

std::shared_ptr<Object> ObjectFactory::createObject(Object::ObjectType type, float x, float y, const TextureHolder &textures) {

    std::shared_ptr<Object> object;

    switch (type) {
        case Object::stWeapon:
            object = std::make_shared<StWeapon>(x, y, textures);
            break;
        case Object::coins:
            object = std::make_shared<Coins>(x, y, textures);
            break;
        case Object::potion:
            object = std::make_shared<Potion>(x, y, textures);
    }

    return object;
}
