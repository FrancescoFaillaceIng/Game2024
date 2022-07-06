//
// Created by Francesco on 18/06/2021.
//

#include "../../Include/Characters/Characters.h"

Characters::Characters() {

}

void Characters::Update() {
    if (isMovingRight || isMovingLeft || isMovingDown || isMovingUp){
        position.x = rect.getPosition().x;
        position.y = rect.getPosition().y;
        sprite.setPosition(position);
        switch (direction) {
            case up:
                rect.move(0, -speedBasic);
                sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32*3, 32, 32));
                break;
            case down:
                rect.move(0, +speedBasic);
                sprite.setTextureRect(sf::IntRect(counterWalking * 32, 0, 32, 32));
                break;
            case left:
                rect.move(-speedBasic, 0);
                sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32, 32, 32));
                break;
            case right:
                rect.move(+speedBasic, 0);
                sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32*2, 32, 32));
                break;
            default:
                break;
        }

        counterWalking++;
        if (counterWalking == 2)
            counterWalking = 0;
    }
}

void Characters::changeDirection() {

}

void Characters::die() {

}

const sf::Vector2f &Characters::getPosition() const {
    return position;
}

int Characters::getHp() const {
    return hp;
}

void Characters::setHp(int hp) {
    Characters::hp = hp;
}

int Characters::getHpMax() const {
    return hpMax;
}

void Characters::setHpMax(int hpMax) {
    Characters::hpMax = hpMax;
}

int Characters::getAttackDamage() const {
    return attackDamage;
}

void Characters::setAttackDamage(int attackDamage) {
    Characters::attackDamage = attackDamage;
}

int Characters::getSpeedBasic() const {
    return speedBasic;
}

void Characters::setSpeedBasic(int speedBasic) {
    Characters::speedBasic = speedBasic;
}

void Characters::setIsMovingUp(bool isMovingUp) {
    Characters::isMovingUp = isMovingUp;
}

void Characters::setIsMovingDown(bool isMovingDown) {
    Characters::isMovingDown = isMovingDown;
}

void Characters::setIsMovingLeft(bool isMovingLeft) {
    Characters::isMovingLeft = isMovingLeft;
}

void Characters::setIsMovingRight(bool isMovingRight) {
    Characters::isMovingRight = isMovingRight;
}


