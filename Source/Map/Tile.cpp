//
// Created by erosp on 16/06/2021.
//

#include "../../Include/Map/Tile.h"

Tile::Tile(std::string textureName, float x, float y, bool walkable, bool exit) {
    pos = sf::Vector2f (x, y);
    sprite.setPosition(pos);
    isWalkable = walkable;
    isExit = exit;
    if (!setUpSprite(textureName))
        return;
}

bool Tile::setUpSprite(std::string textureName) {
    if (!texture.loadFromFile(textureName)) {
        return false;
    }
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
    return true;
}
