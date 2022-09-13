//
// Created by Francesco on 18/07/2022.
//

#ifndef GAME_OBSERVER_H
#define GAME_OBSERVER_H

#include "../Characters/Hero.h"

class Observer {
public:
    virtual ~Observer() {};
    virtual void update(std::shared_ptr<Hero> hero) = 0;
};


#endif //GAME_OBSERVER_H
