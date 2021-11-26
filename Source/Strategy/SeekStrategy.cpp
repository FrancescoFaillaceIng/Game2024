//
// Created by Francesco on 26/11/2021.
//

#include "../../Include/Strategy/SeekStrategy.h"

SeekStrategy::SeekStrategy(sf::Vector2u windowSize) {
    speed = 10;
    this->windowSize = windowSize;
    type = seek;
}

void SeekStrategy::update(bool &isMovingUp, bool &isMovingDown, bool &isMovingLeft, bool &isMovingRight,
                          sf::RectangleShape &rect) {

    sf::Vector2f movements(0.f,0.f);
    sf::Vector2f enemyPos(rect.getPosition());
    //hero is down right
    double modulo = sqrt(pow(heroPosition.x, 2) + pow(enemyPos.y,2));
    if(heroPosition.x >= enemyPos.x && heroPosition.y >= enemyPos.y) {
        movements = sf::Vector2f(abs(((heroPosition.x-enemyPos.x)/modulo)*speed), abs(((heroPosition.y-enemyPos.y)
        /modulo)*speed));
        if(movements.x > movements.y) {
            isMovingRight = true;
            isMovingDown = false;
        } else {
            isMovingRight = false;
            isMovingDown = true;
        }
        isMovingUp = false;
        isMovingLeft = false;
        //hero is down left
    } else if(heroPosition.x <= enemyPos.x && heroPosition.y >= enemyPos.y) {
        movements = sf::Vector2f(-abs(((heroPosition.x-enemyPos.x)/modulo)*speed), abs(((heroPosition.y-enemyPos.y)
        /modulo)*speed));
        if(-movements.x > movements.y) {
            isMovingLeft = true;
            isMovingDown = false;
        } else {
            isMovingLeft = false;
            isMovingDown = true;
        }
        isMovingUp = false;
        isMovingRight = false;
        //hero is up right
    } else if(heroPosition.x >= enemyPos.x && heroPosition.y <= enemyPos.y) {
        movements = sf::Vector2f(abs(((heroPosition.x-enemyPos.x)/modulo)*speed), -abs(((heroPosition.y-enemyPos.y)
        /modulo)*speed));
        if(movements.x > -movements.y) {
            isMovingRight = true;
            isMovingUp = false;
        } else {
            isMovingRight = false;
            isMovingUp = true;
        }
        isMovingLeft = false;
        isMovingDown = false;
        //hero is up left
    } else if(heroPosition.x <= enemyPos.x && heroPosition.y <= enemyPos.y) {
        movements = sf::Vector2f(-abs(((heroPosition.x-enemyPos.x)/modulo)*speed), -abs(((heroPosition.y-enemyPos.y)
        /modulo)*speed));
        if(-movements.x > -movements.y) {
            isMovingLeft = true;
            isMovingUp = false;
        } else {
            isMovingLeft = false;
            isMovingUp = true;
        }

        isMovingRight = false;
        isMovingDown = false;
    }

    rect.move(movements);
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
