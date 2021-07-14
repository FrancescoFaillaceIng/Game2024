//
// Created by erosp on 09/07/2021.
//

#include "../../Include/Objects/ObjectFactory.h"

std::shared_ptr<Object> ObjectFactory::createObject(Object::ObjectType objectType, const TextureHolder& textures) {
    std::shared_ptr<Object> object;
    switch (objectType) {
        case ObjectType::rangedWeapon:
            object = std::make_shared<RangedWeapon>(textures, RangedWeapon::RangedWeaponType::stWeapon);
            break;
    }
    return object;
}

std::shared_ptr<Object> ObjectFactory::createObject(const TextureHolder &textures) {
    std::shared_ptr<Object> object;
    Object::ObjectType objectType = typeDrop();

    if(objectType == 0 || objectType == 1) { // || type == 2 || type == 3) {
        object = createObject(objectType, textures);
    }
    return object;
}

Object::ObjectType ObjectFactory::typeDrop() {

    int random = generateRandom(100);
    Object::ObjectType typeSelected ;

    typeSelected = rangedWeapon;
    /*
    //15% to drop healpack
    if(random < 15) {
        typeSelected = healPack;
    } //50% to drop weapon
    else if(random < 65) {
        typeSelected = rangedWeapon;
    }
*/
    return typeSelected;
}