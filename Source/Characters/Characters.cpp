//
// Created by Francesco on 18/06/2021.
//

#include "../../Include/Characters/Characters.h"

Characters::Characters() {

}

void Characters::Update() {
    if (isMovingRight || isMovingLeft || isMovingDown || isMovingUp){
        float x = rect.getPosition().x;
        float y = rect.getPosition().y;
        sprite.setPosition(x,y);
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

void Characters::setPosition(const sf::Vector2f &position) {
    Characters::position = position;
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

int Characters::getCounterWalking() const {
    return counterWalking;
}

void Characters::setCounterWalking(int counterWalking) {
    Characters::counterWalking = counterWalking;
}

bool Characters::isMovingUp1() const {
    return isMovingUp;
}

void Characters::setIsMovingUp(bool isMovingUp) {
    Characters::isMovingUp = isMovingUp;
}

bool Characters::isMovingDown1() const {
    return isMovingDown;
}

void Characters::setIsMovingDown(bool isMovingDown) {
    Characters::isMovingDown = isMovingDown;
}

bool Characters::isMovingLeft1() const {
    return isMovingLeft;
}

void Characters::setIsMovingLeft(bool isMovingLeft) {
    Characters::isMovingLeft = isMovingLeft;
}

bool Characters::isMovingRight1() const {
    return isMovingRight;
}

void Characters::setIsMovingRight(bool isMovingRight) {
    Characters::isMovingRight = isMovingRight;
}

Characters::CharacterType Characters::getCharacterType() const {
    return characterType;
}

void Characters::setCharacterType(Characters::CharacterType characterType) {
    Characters::characterType = characterType;
}



