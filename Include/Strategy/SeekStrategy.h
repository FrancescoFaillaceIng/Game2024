//
// Created by Francesco on 26/11/2021.
//

#ifndef GAME_SEEKSTRATEGY_H
#define GAME_SEEKSTRATEGY_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include "Strategy.h"

class SeekStrategy: public Strategy{
public:
    enum Direction {
        up, down, left, right
    };

    SeekStrategy(sf::Vector2u windowSize);

    void update(bool &isMovingUp, bool &isMovingDown, bool &isMovingLeft, bool &isMovingRight,
                sf::RectangleShape &rect) override;

    void animation(bool &isMovingUp, bool &isMovingDown, bool &isMovingLeft, bool &isMovingRight, bool &delayWalk,
                   bool &delayMoreWalk, int &counterWalk) override;

    Direction direction;
    Type type;
    sf::Vector2f heroPosition;

private:
    float speed;
    sf::Vector2u windowSize;
};


#endif //GAME_SEEKSTRATEGY_H
