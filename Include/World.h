//
// Created by Francesco on 18/06/2021.
//

#ifndef GAME_WORLD_H
#define GAME_WORLD_H

#include "Map/Map.h"

#include "Objects/StWeapon.h"
#include "Projectiles/StProjectile.h"

#include "Characters/CharacterFactory.h"
#include "Objects/ObjectFactory.h"
#include "Projectiles/ProjectileFactory.h"

#include "Random.h"
#include "Observer/Subject.h"
#include "Observer/mObserver.h"

#include <memory>
#include <list>

class World: public Subject{
public:
    World(std::shared_ptr<sf::RenderWindow> window, const TextureHolder &textures);

    void Update(sf::Clock &damageClock);
    void draw();
    void PlayerInput(sf::Keyboard::Key key, bool isPressed, sf::Clock &shootingClock);
    void CheckGlobalBounds(sf::Clock &damageClock);

    void createMap();
    void createObjects();
    void createHero();
    void createEnemies();

    void drawMap();
    void drawHero();
    void drawEnemies();
    void drawObject();
    void drawProjectiles();

    void CollisionsHeroEnemies(sf::Clock &damgeClock);
    void CollisionsProjectilesEnemies();
    void CollisionsHeroMap();
    void CollisionsProjectilesMap();
    void CollisionsEnemiesMap();

    void UpdateMap();
    void UpdateHero();
    void UpdateEnemies();
    void UpdateProjectiles();

    void addObserver(std::shared_ptr<mObserver> observer);
    void removeObserver(std::shared_ptr<mObserver> observer);
    void notify() override;

    void collectObjects();
    void Drop(float x, float y);
    void Shoot();

    std::shared_ptr<sf::RenderWindow> window;
    std::shared_ptr<Map> map;
    std::shared_ptr<Hero> hero;

    std::vector<std::shared_ptr<Object>> collectableObject;
    std::vector<std::shared_ptr<Enemy>> enemyArray;
    std::vector<std::shared_ptr<Projectile>> projectilePlayerArray;

    std::vector<std::shared_ptr<mObserver>> coin_observer;
    std::shared_ptr<mObserver> _mObserver;

    const TextureHolder& textures;

    CharacterFactory characterFactory;
    ObjectFactory objectFactory;
    ProjectileFactory projectileFactory;

    int coins_counter = 0;
};


#endif //GAME_WORLD_H