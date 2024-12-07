//
// Created by Francesco on 26/11/2021.
//

#ifndef GAME_STRATEGY_H
#define GAME_STRATEGY_H

#include "SFML/Graphics.hpp"

class Strategy {
public:
    enum Type {
        patrol,
        seek
    };

    enum Direction {
        up, down, left, right
    };


    Strategy();

    virtual void update(bool& isMovingUp,bool& isMovingDown,bool& isMovingLeft,bool& isMovingRight, int randDirection, sf::RectangleShape& rect);
    virtual void animation(bool& isMovingUp,bool& isMovingDown,bool& isMovingLeft,bool& isMovingRight, bool&
    delayWalk, bool& delayMoreWalk, int& counterWalk);
};


#endif //GAME_STRATEGY_H
