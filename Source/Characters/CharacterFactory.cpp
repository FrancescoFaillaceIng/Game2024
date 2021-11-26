//
// Created by Francesco on 27/10/2021.
//

#include "../../Include/Characters/CharacterFactory.h"

std::shared_ptr<Hero> CharacterFactory::createHero(Characters::CharacterType characterType, Hero::HeroType heroType,
                                                   const TextureHolder&textures) {
    std::shared_ptr<Hero> herof;
    if (characterType == Characters::goodboy){
        herof = std::make_shared<Hero>(Hero::HeroType::StRanged, textures);
    }

    return herof;
}

std::shared_ptr<Enemy> CharacterFactory::createEnemy(Characters::CharacterType characterType, Enemy::EnemyType enemyType,
                                                     sf::Vector2u windowSize, const TextureHolder &textures) {
    std::shared_ptr<Enemy> enemyf;
    std::shared_ptr<Strategy> strategy = std::make_shared<PatrolStrategy>(windowSize);
    if (characterType == Characters::badguy){
        enemyf = std::make_shared<MeleeEnemy>(Enemy::EnemyType::meleeEnemy, windowSize, textures, strategy);
    }

    return enemyf;
}
