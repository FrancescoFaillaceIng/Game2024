//
// Created by Francesco on 18/07/2022.
//

#ifndef GAME_MOBSERVER_H
#define GAME_MOBSERVER_H

#include "Observer.h"

#include <memory>

class mObserver: public Observer{
public:
    mObserver();

    void update(std::shared_ptr<Hero> hero);
};


#endif //GAME_MOBSERVER_H
