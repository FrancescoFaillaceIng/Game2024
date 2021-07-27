//
// Created by Francesco on 18/06/2021.
//

#ifndef GAME_WORLD_H
#define GAME_WORLD_H

#include "Map/Tile.h"
#include "Characters/Hero.h"
#include "Objects/StWeapon.h"
#include "Objects/ObjectFactory.h"

class World {
public:
    World(std::shared_ptr<sf::RenderWindow> window, const TextureHolder &textures);

    void Update();
    void draw();
    void PlayerInput(sf::Keyboard::Key key, bool isPressed);

    void drawHero();
    void drawWeapon();

    void createObjects();

    void collectObjects();

    void setUpInitialState();
    void setUpEnemyPositions();
    void setUpTiles();

    //things related to tiles(video)
    int gridLength;
    std::vector<std::vector<Tile *>> tiles;
    sf::Vector2i exitPos;
    sf::Vector2i HeroPos;
    std::vector<sf::Vector2i> enemyPositions;

    std::shared_ptr<Hero> hero;
    std::shared_ptr<StWeapon> stweapon;
    std::vector<std::shared_ptr<Object>> collectableObject;
    std::shared_ptr<sf::RenderWindow> window;
    const TextureHolder& textures;
    ObjectFactory objectFactory;
};


#endif //GAME_WORLD_H