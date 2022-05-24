//
// Created by Francesco on 27/07/2021.
//

#include "../../Include/Objects/ObjectFactory.h"

std::shared_ptr<Object> ObjectFactory::createObject(Object::ObjectType type, const TextureHolder &textures) {

    std::shared_ptr<Object> object;

    switch (type) {
        case Object::stWeapon:
            object = std::make_shared<StWeapon>(textures);
    }

    return object;
}
