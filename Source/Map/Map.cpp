//
// Created by erosp on 16/06/2021.
//

#include "../../Include/Map/Map.h"

Map::Map() {
    this->maxSize.x = 500;
    this->maxSize.y = 500;

    for (size_t x = 0; x <= this->maxSize.x; x++){
        this->map.emplace_back(std::vector<Tile>());
        for (size_t y = 0; y <= this->maxSize.y ; y++) {
            this->map[x].emplace_back(Tile(tile->getTextures()));
        }
    }
}

Map::~Map() {

}