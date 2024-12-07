//
// Created by Francesco on 26/11/2021.
//

#ifndef GAME_PATROLSTRATEGY_H
#define GAME_PATROLSTRATEGY_H

#include "Strategy.h"
#include "..\Random.h"

class PatrolStrategy: public Strategy{
public:
    PatrolStrategy(sf::Vector2u windowSize);

    //change direction every x frames
    void update(bool &isMovingUp, bool &isMovingDown, bool &isMovingLeft, bool &isMovingRight, int randDirection,
                sf::RectangleShape &rect) override;

    void animation(bool &isMovingUp, bool &isMovingDown, bool &isMovingLeft, bool &isMovingRight, bool &delayWalk,
                   bool &delayMoreWalk, int &counterWalk) override;

    int changeDirectionTime, counterDirection = 0;
    Direction direction;
    Type type;

private:
    void changeDirection(bool &isMovingUp, bool &isMovingDown, bool &isMovingLeft, bool &isMovingRight, int randDirection);
    int randDirection = 0;

    int speed;
    sf::Vector2u windowSize;
};


#endif //GAME_PATROLSTRATEGY_H
