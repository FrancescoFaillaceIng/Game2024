//
// Created by erosp on 16/06/2021.
//

#include "../../Include/Map/Tile.h"

Textures::ID toTextureID(Tile::TileType tileType) {
    switch (tileType) {
        case Tile::wall:
            return Textures::WallText;
        case Tile::floor:
            return Textures::FloorText;
    }
}

Tile::Tile(const TextureHolder& textures): textures(textures) {

}

Tile::~Tile() {

}

bool Tile::isWalkable() const {
    return walkable;
}

void Tile::setWalkable(bool walkable) {
    Tile::walkable = walkable;
}

const TextureHolder &Tile::getTextures() const {
    return textures;
}
