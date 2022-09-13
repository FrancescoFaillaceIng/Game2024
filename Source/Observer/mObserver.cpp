//
// Created by Francesco on 18/07/2022.
//

#include "../../Include/Observer/mObserver.h"

mObserver::mObserver() {

}

void mObserver::update(std::shared_ptr<Hero> hero) {
    hero->setAttackDamage((hero->getAttackDamage()) + 5);
}