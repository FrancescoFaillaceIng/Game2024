//
// Created by erosp on 16/06/2021.
//

#include "../../Include/Map/Tile.h"

Textures::ID toTextureID(Tile::TileType tileType) {
    switch(tileType) {
        case Tile::TileType::wall:
            return Textures::ID::WallText;
        case Tile::TileType::floor:
            return Textures::ID::FloorText;
    }
}

Tile::Tile(int x, int y, TileType tileType, const TextureHolder& textures){

    rect.setPosition(x, y);
    rect.setSize(sf::Vector2f(64, 64));

    sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
    sprite.setPosition(rect.getPosition());

    if (tileType == floor){
        setWalkable(true);
    }

    sprite.setTexture(textures.get(toTextureID(tileType)));
}

void Tile::setWalkable(bool walkable) {
    Tile::walkable = walkable;
}

const sf::Sprite &Tile::getSprite() {
    return sprite;
}

void Tile::UpdateTile() {
    rect.setPosition(rect.getPosition());
    sprite.setPosition(rect.getPosition());
}

bool Tile::isWalkable() const {
    return walkable;
}

const sf::Vector2f &Tile::getPosition() const {
    return position;
}

