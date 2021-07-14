//
// Created by erosp on 07/07/2021.
//

#ifndef MAIN_CPP_OBJECT_H
#define MAIN_CPP_OBJECT_H

#include "../Entity.h"

class Object: public Entity {
public:
    enum ObjectType {
        rangedWeapon,
        meleeWeapon
    };

    Object();
    virtual bool use();
    virtual void get();
    virtual void setPosition(sf::Vector2f vector);
    virtual void update();

    int counterLifeTime = 2;
    ObjectType objectType;
    bool equipped;
    bool active = true;
    sf::Vector2f position;
};
#endif //MAIN_CPP_OBJECT_H
