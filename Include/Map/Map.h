//
// Created by erosp on 16/06/2021.
//

#ifndef GAME_MAP_H
#define GAME_MAP_H

#include "Tile.h"

class Map{
public:
    Map();
    virtual ~Map();

private:
    sf::Vector2u maxSize;
    std::shared_ptr<Tile> tile;
    std::vector< std::vector<Tile>> map;
};
#endif //GAME_MAP_H
