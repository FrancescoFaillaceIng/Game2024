//
// Created by Francesco on 27/10/2021.
//

#ifndef GAME_CHARACTERFACTORY_H
#define GAME_CHARACTERFACTORY_H

#include "Hero.h"
#include "MeleeEnemy.h"
#include "../ResourceHolder.h"
#include "../ResourceIdentifier.h"

class CharacterFactory {
public:
    std::shared_ptr<Hero> createHero(Characters::CharacterType characterType, Hero::HeroType heroType,
                                     const TextureHolder &textures);

    std::shared_ptr<Enemy>createEnemy(Characters::CharacterType characterType, Enemy::EnemyType enemyType,
                                      sf::Vector2u windowSize, const TextureHolder &textures);
};


#endif //GAME_CHARACTERFACTORY_H
