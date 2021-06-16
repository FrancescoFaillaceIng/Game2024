//
// Created by erosp on 16/06/2021.
//

#ifndef GAME_TILE_H
#define GAME_TILE_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Tile{
public:
    Tile(std::string textureName, float x, float y, bool walkable, bool exit);

    sf::Vector2f pos;
    sf::Texture texture;
    sf::Sprite sprite;

    bool isWalkable;
    bool isExit;
    bool setUpSprite(std::string textureName);
};

#endif //GAME_TILE_H
