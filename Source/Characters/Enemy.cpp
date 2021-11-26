//
// Created by Francesco on 14/10/2021.
//

#include "../../Include/Characters/Enemy.h"

Enemy::Enemy() {

}

void Enemy::Update() {
    strategy->animation(isMovingUp,isMovingDown,isMovingLeft,isMovingRight,delayMoreWalk,
                        delayMoreWalk,counterWalk);

    strategy->update(isMovingUp, isMovingDown, isMovingLeft, isMovingRight, rect);
    sprite.setPosition(rect.getPosition());
    position = sprite.getPosition();

    //serve per texture corretta
    setDirection();

    if(hp<=0) {
        this->die();
    }

    Characters::Update();
}

void Enemy::die() {
    active = false;
}

void Enemy::setDirection() {
    if(isMovingUp) {
        this->direction = up;
        sprite.setTextureRect(sf::IntRect(counterWalk*32,32*3,32,32));
    } else if(isMovingRight) {
        this->direction = right;
        sprite.setTextureRect(sf::IntRect(counterWalk*32,32*2,32,32));
    } else if(isMovingLeft) {
        this->direction = left;
        sprite.setTextureRect(sf::IntRect(counterWalk*32,32,32,32));
    } else if(isMovingDown) {
        this->direction = down;
        sprite.setTextureRect(sf::IntRect(counterWalk*32,0,32,32));
    }
}

void Enemy::changeDirection() {
    isMovingUp= false;
    isMovingDown= false;
    isMovingLeft= false;
    isMovingRight= false;
    int randDirection = GenerateRandom(4);
    if(randDirection==1) isMovingUp=true;
    if(randDirection==2) isMovingDown=true;
    if(randDirection==3) isMovingLeft=true;
    if(randDirection==4) isMovingRight=true;
}

