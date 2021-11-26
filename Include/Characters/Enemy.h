//
// Created by Francesco on 14/10/2021.
//

#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H

#include <memory>
#include "Characters.h"
#include "..\Random.h"
#include "..\Strategy\PatrolStrategy.h"
#include "..\Strategy\SeekStrategy.h"

class Enemy: public Characters{
public:
    enum EnemyType{
        meleeEnemy,
        rangedEnemy,
    };

    Enemy();

    void Update() override;
    void setDirection();
    void changeDirection() override;
    void die() override;

    std::shared_ptr<Strategy> strategy;
protected:
    sf::Vector2f windowSize;



    int counterWalk;
    bool delayMoreWalk;
};


#endif //GAME_ENEMY_H
