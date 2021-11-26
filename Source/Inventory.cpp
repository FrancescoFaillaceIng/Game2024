//
// Created by Francesco on 10/11/2021.
//

#include "../Include/Inventory.h"

Inventory::Inventory() {

}

bool Inventory::addItem(std::shared_ptr<Object> item) {

    slots.emplace_back(item);
}

std::shared_ptr<Object> Inventory::getElement(Object::ObjectType objectType) {

    std::shared_ptr<Object> element = slots[iter];
    for(int i =0; i<slots.size(); i++) {
        if(slots[iter]->objectType == objectType) {
            element = slots[iter];
            break;
        }
        iter = (iter + 1)% slots.size();
    }
    slots.erase(slots.begin() + iter);

    if(element == nullptr)
        std::cout<<"errore nel get element"<<std::endl;
    return element;
}

std::shared_ptr<Object> Inventory::findElement(Object::ObjectType objectType) {

    std::shared_ptr<Object> element = slots[iter];
    for(int i =0; i<slots.size(); i++) {
        if(slots[iter]->objectType == objectType) {
            element = slots[iter];
            break;
        }
        iter = (iter + 1)% slots.size();
    }

    if(element == nullptr)
        std::cout<<"errore nel find element"<<std::endl;
    return element;
}
