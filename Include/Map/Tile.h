//
// Created by erosp on 16/06/2021.
//

#ifndef GAME_TILE_H
#define GAME_TILE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "../ResourceHolder.h"
#include "../ResourceIdentifier.h"

class Tile{
public:
    enum TileType{
        wall,
        floor,
    };

    Tile(const TextureHolder& textures);
    virtual ~Tile();

    bool isWalkable() const;

    void setWalkable(bool walkable);

private:
    TileType tileType;
    bool walkable;
    const TextureHolder& textures;
public:
    const TextureHolder &getTextures() const;
};

#endif //GAME_TILE_H
