//
// Created by Francesco on 21/07/2022.
//

#include "../../Include/LifeBars/BarsFactory.h"

std::shared_ptr<LifeBars> BarsFactory::createBars(float x, float y, const TextureHolder &textures) {
    std::shared_ptr<LifeBars> bar;

    bar = std::make_shared<LifeBars>(x, y, textures);

    return bar;
}