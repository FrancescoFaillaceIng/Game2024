//
// Created by Francesco on 18/06/2021.
//

#ifndef GAME_WORLD_H
#define GAME_WORLD_H

#include "Map/Map.h"
#include "Characters/Hero.h"
#include "Characters/MeleeEnemy.h"
#include "Objects/StWeapon.h"
#include "Objects/ObjectFactory.h"
#include "Characters/CharacterFactory.h"
#include "Random.h"

class World {
public:
    World(std::shared_ptr<sf::RenderWindow> window, const TextureHolder &textures);

    void Update();
    void draw();
    void PlayerInput(sf::Keyboard::Key key, bool isPressed);

    void createObjects();
    void createCharacter();

    void drawHero();
    void drawObject();
    void drawEnemies();

    void UpdateEnemies();

    void collectObjects();

    void Shoot();

    std::shared_ptr<Map> map;
    std::shared_ptr<Hero> hero;
    std::shared_ptr<sf::RenderWindow> window;

    std::vector<std::shared_ptr<Object>> collectableObject;
    std::vector<std::shared_ptr<Enemy>> enemyArray;

    const TextureHolder& textures;

    ObjectFactory objectFactory;
    CharacterFactory characterFactory;
};


#endif //GAME_WORLD_H