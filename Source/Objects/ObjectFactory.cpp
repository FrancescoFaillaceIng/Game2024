//
// Created by Francesco on 27/07/2021.
//

#include "../../Include/Objects/ObjectFactory.h"

std::shared_ptr<Object> ObjectFactory::createObject(Object::ObjectType type, const TextureHolder &textures) {

    std::shared_ptr<Object> object;

    if ( type == Object::ObjectType::stWeapon ) {
        object = std::make_shared<StWeapon>(textures);
    }

    return object;
}
