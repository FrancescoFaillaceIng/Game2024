//
// Created by Francesco on 18/06/2021.
//

#ifndef GAME_WORLD_H
#define GAME_WORLD_H

#include "Map/Tile.h"
#include "Characters/Hero.h"
#include "Projectile.h"
#include "Objects/ObjectFactory.h"

class World {
public:
    World(std::shared_ptr<sf::RenderWindow> window, const TextureHolder &textures);

    void Update();
    void draw();
    void PlayerInput(sf::Keyboard::Key key, bool isPressed);

    void createObjects();

    void drawHero();
    void drawProjectiles();
    void drawObjects();

    void updateObjects();
    void updateProjectiles();

    void setUpInitialState();
    void setUpEnemyPositions();
    void setUpTiles();


    //things related to tiles
    int gridLength;
    std::vector<std::vector<Tile *>> tiles;
    sf::Vector2i exitPos;
    sf::Vector2i HeroPos;
    std::vector<sf::Vector2i> enemyPositions;

    std::shared_ptr<Hero> hero;
    std::shared_ptr<sf::RenderWindow> window;
    const TextureHolder& textures;
    ObjectFactory objectFactory;
    std::vector<std::shared_ptr<Projectile>> projectilePlayerArray;
    std::vector<std::shared_ptr<Object>> collectableObject;
};


#endif //GAME_WORLD_H
