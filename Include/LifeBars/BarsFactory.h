//
// Created by Francesco on 21/07/2022.
//

#ifndef GAME_BARSFACTORY_H
#define GAME_BARSFACTORY_H

#include "LifeBars.h"
#include "../ResourceHolder.h"
#include "../ResourceIdentifier.h"

class BarsFactory {
public:
    std::shared_ptr<LifeBars> createBars(float x, float y);
};


#endif //GAME_BARSFACTORY_H
