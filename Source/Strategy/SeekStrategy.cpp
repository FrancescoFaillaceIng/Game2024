//
// Created by Francesco on 26/11/2021.
//

#include "../../Include/Strategy/SeekStrategy.h"

SeekStrategy::SeekStrategy(sf::Vector2u windowSize) {
    speed = 1;
    this->windowSize = windowSize;
    type = seek;
}

void SeekStrategy::update(bool &isMovingUp, bool &isMovingDown, bool &isMovingLeft, bool &isMovingRight,
                          sf::RectangleShape &rect) {

    sf::Vector2f target(heroPosition.x - enemyPos.x, heroPosition.y - enemyPos.y);
    sf::Vector2f movement;

    double modulo = sqrt(pow(target.x, 2)+ pow(target.y, 2));

    movement = sf::Vector2f ((target.x/modulo)*speed, (target.y/modulo)*speed);

    //hero is up right
    if (target.x > 0 && target.y < 0){
        isMovingUp = true;
        isMovingDown = false;

        isMovingRight = true;
        isMovingLeft = false;
    }

    //hero is down right
    else if (target.x > 0 && target.y > 0){
        isMovingUp = false;
        isMovingDown = true;

        isMovingRight = true;
        isMovingLeft = false;
    }

    //hero is down left
    else if (target.x < 0 && target.y > 0){
        isMovingUp = false;
        isMovingDown = true;

        isMovingRight = false;
        isMovingLeft = true;
    }

    //hero is up left
    else if (target.x < 0 && target.y < 0){
        isMovingUp = true;
        isMovingDown = false;

        isMovingRight = false;
        isMovingLeft = true;
    }
    rect.move(movement);
}

void SeekStrategy::animation(bool &isMovingUp, bool &isMovingDown, bool &isMovingLeft, bool &isMovingRight, bool &delayWalk,
                        bool &delayMoreWalk, int &counterWalk) {

    if(!((isMovingLeft && isMovingRight) || (isMovingUp && isMovingDown))) {
        if ( delayWalk ) {
            if ( delayMoreWalk )
                counterWalk = (counterWalk + 1) % 3;
            delayMoreWalk = !delayMoreWalk;
        }
        delayWalk = !delayWalk;
    }
}
