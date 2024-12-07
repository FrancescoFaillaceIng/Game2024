//
// Created by Francesco on 26/11/2021.
//

#include "../../Include/Strategy/PatrolStrategy.h"

PatrolStrategy::PatrolStrategy(sf::Vector2u windowSize) {
    speed = 0;
    type = patrol;
}

void PatrolStrategy::update(bool &isMovingUp, bool &isMovingDown, bool &isMovingLeft, bool &isMovingRight, int randDirection,
                            sf::RectangleShape& rect) {

    if(counterDirection==0) {
        changeDirection(isMovingUp, isMovingDown, isMovingLeft, isMovingRight, randDirection);
        changeDirectionTime = GenerateRandom(200);
    }
    counterDirection = (counterDirection+1)%changeDirectionTime;

    sf::Vector2f movements(0.f,0.f);
    if(isMovingUp) {
        movements.y-=speed;
    }
    if(isMovingDown) {
        movements.y+=speed;
    }
    if(isMovingRight) {
        movements.x+=speed;
    }
    if(isMovingLeft) {
        movements.x-=speed;
    }

    rect.move(movements);

}

void PatrolStrategy::changeDirection(bool &isMovingUp, bool &isMovingDown, bool &isMovingLeft, bool &isMovingRight, int randDirection) {
    isMovingUp= false;
    isMovingDown= false;
    isMovingLeft= false;
    isMovingRight= false;
    switch (randDirection) {
        case 1:
            isMovingUp = true;
            break;
        case 2:
            isMovingDown = true;
            break;
        case 3:
            isMovingLeft = true;
            break;
        case 4:
            isMovingRight = true;
            break;
    }
}

void PatrolStrategy::animation(bool &isMovingUp, bool &isMovingDown, bool &isMovingLeft, bool &isMovingRight,
                               bool &delayWalk, bool &delayMoreWalk, int &counterWalk) {

    if(!((isMovingLeft && isMovingRight) || (isMovingUp && isMovingDown))) {
        if ( delayWalk ) {
            if ( delayMoreWalk )
                counterWalk = (counterWalk + 1) % 3;
            delayMoreWalk = !delayMoreWalk;
        }
        delayWalk = !delayWalk;
    }
}