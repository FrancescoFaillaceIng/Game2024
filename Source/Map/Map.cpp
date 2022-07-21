//
// Created by erosp on 16/06/2021.
//

#include "../../Include/Map/Map.h"

Map::Map(const TextureHolder& textures) {
    //TODO togliere create map?
    createMap(textures);
}

void Map::createMap(const TextureHolder& textures) {
    createMatrix();
    y = 0;
    for (auto i = stringmap.begin(); i != stringmap.end(); i++){
        if ((*i).size() != line.size()){
            std::cout << "errore, le colonne non hanno la stessa lunghezza \n";
            break;
        }
        x = 0;
        for (auto j = (*i).begin(); j != (*i).end(); j++){

            //create a tile up to stringmap elements
            if ((*j) == '1'){
                tile = std::make_shared<Tile>(x, y, Tile::TileType::wall, textures);
            } else if ((*j) == '0'){
                tile = std::make_shared<Tile>(x, y, Tile::TileType::floor, textures);
            } else {
                std::cout << "carattere non riconosciuto";
            }

            //put the tile in tileArray
            tileArray.emplace_back(tile);
            x = x + 64;
        }
        y = y + 64;
    }
}

void Map::createMatrix() {
    std::ifstream ReadFile("../Resources/Map.txt");

    //read the file and make a vector of string
    while (getline(ReadFile, line)){
        stringmap.emplace_back(line);
    }
    ReadFile.close();
}
