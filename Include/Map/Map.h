//
// Created by erosp on 16/06/2021.
//

#ifndef GAME_MAP_H
#define GAME_MAP_H

#include "Tile.h"

#include <fstream>
#include <string>
#include <sstream>

class Map{
public:
    Map(const TextureHolder& textures);

    std::vector<std::shared_ptr<Tile>> tileArray;
    std::shared_ptr<Tile> tile;
protected:
    int x, y;
    std::vector<std::string> stringmap;
    std::string line;

    void createMap(const TextureHolder& textures);
    void createMatrix();
};
#endif //GAME_MAP_H
