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
    void UpdateTile();

    const sf::Sprite &getSprite();
    const sf::RectangleShape &getRect();
    const sf::Vector2f &getPosition() const;

    bool isWalkable() const;

    TileType tileType;
    sf::RectangleShape rect;
protected:
    sf::Sprite sprite;

    sf::Vector2f position;

    bool walkable = false;
};

#endif //GAME_TILE_H
