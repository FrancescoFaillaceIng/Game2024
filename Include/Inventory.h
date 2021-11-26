//
// Created by Francesco on 10/11/2021.
//

#ifndef GAME_INVENTORY_H
#define GAME_INVENTORY_H

#include "ResourceHolder.h"
#include "Objects/Object.h"
#include <iostream>

class Inventory {
public:
    Inventory();

    bool addItem(std::shared_ptr<Object> item);
    std::shared_ptr<Object> getElement(Object::ObjectType objectType);
    std::shared_ptr<Object> findElement(Object::ObjectType objectType);

private:
    int iter;
    std::vector<std::shared_ptr<Object>> slots;
};


#endif //GAME_INVENTORY_H
