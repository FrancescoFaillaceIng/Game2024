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

    Tile(int x, int y, TileType tileType, const TextureHolder& textures);

    void setWalkable(bool walkable);
    void setTileType(TileType tileType);

    const sf::Sprite &getSprite();
    const sf::RectangleShape &getRect();

    void UpdateTile();

    TileType tileType;

protected:
    sf::Sprite sprite;
    sf::RectangleShape rect;

    bool walkable = false;
};

#endif //GAME_TILE_H
