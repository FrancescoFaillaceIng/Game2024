//
// Created by Francesco on 14/10/2021.
//

#ifndef GAME_MELEEENEMY_H
#define GAME_MELEEENEMY_H

#include "Enemy.h"

class MeleeEnemy: public Enemy{
public:
    explicit MeleeEnemy(Enemy::EnemyType enemyType, sf::Vector2u windowSize, const TextureHolder& textures,
                        std::shared_ptr<Strategy> strategy);

private:
    const TextureHolder& textures;
};


#endif //GAME_MELEEENEMY_H
