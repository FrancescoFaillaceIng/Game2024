//
// Created by Francesco on 18/06/2021.
//

#ifndef GAME_WORLD_H
#define GAME_WORLD_H

#include "Map/Map.h"

#include "Characters/Hero.h"
#include "Characters/MeleeEnemy.h"

#include "Objects/StWeapon.h"
#include "Projectiles/StProjectile.h"

#include "Characters/CharacterFactory.h"
#include "Objects/ObjectFactory.h"
#include "Projectiles/ProjectileFactory.h"

#include "Random.h"

class World {
public:
    World(std::shared_ptr<sf::RenderWindow> window, const TextureHolder &textures);

    void Update();
    void draw();
    void PlayerInput(sf::Keyboard::Key key, bool isPressed, sf::Clock& shootingClock);
    void CheckGlobalBounds();

    void createMap();
    void createObjects();
    void createCharacters();

    void drawMap();
    void drawHero();
    void drawEnemies();
    void drawObject();
    void drawProjectiles();

    void CollisionsHeroEnemies();
    void CollisionsProjectilesEnemies();

    void UpdateMap();
    void UpdateHero();
    void UpdateEnemies();
    void UpdateProjectiles();

    void collectObjects();

    void Shoot();

    std::shared_ptr<sf::RenderWindow> window;
    std::shared_ptr<Map> map;
    std::shared_ptr<Hero> hero;

    std::vector<std::shared_ptr<Object>> collectableObject;
    std::vector<std::shared_ptr<Enemy>> enemyArray;
    std::vector<std::shared_ptr<Projectile>> projectilePlayerArray;

    const TextureHolder& textures;

    CharacterFactory characterFactory;
    ObjectFactory objectFactory;
    ProjectileFactory projectileFactory;

};


#endif //GAME_WORLD_H