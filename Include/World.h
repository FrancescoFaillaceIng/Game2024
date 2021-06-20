//
// Created by Francesco on 18/06/2021.
//

#ifndef GAME_WORLD_H
#define GAME_WORLD_H

#include "Map/Tile.h"
#include "Characters/Hero.h"
#include <vector>

//TODO mettere World.h e World.cpp in Include e Source
class World {
public:
    World();

    std::vector<std::vector<Tile *>> tiles;

    int gridLength;

    sf::Vector2i exitPos;
    sf::Vector2i HeroPos;
    std::vector<sf::Vector2i> enemyPositions;
    std::shared_ptr<Hero> hero;
    std::shared_ptr<sf::RenderWindow> window;

    void drawPlayer();
    void setUpInitialState();
    void setUpEnemyPositions();
    void setUpTiles();


};


#endif //GAME_WORLD_H
