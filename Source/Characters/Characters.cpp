//
// Created by Francesco on 18/06/2021.
//

#include "../../Include/Characters/Characters.h"

Characters::Characters() {

}

void Characters::UpdateMovement() {
    switch (direction) {
        case up:
            sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32*3, 32, 32));
            break;
        case down:
            sprite.setTextureRect(sf::IntRect(counterWalking * 32, 0, 32, 32));
            break;
        case left:
            sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32, 32, 32));
            break;
        case right:
            sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32*2, 32, 32));
            break;
        default:
            break;
    }

    counterWalking++;
    if (counterWalking == 2)
        counterWalking = 0;

}

const sf::Sprite &Characters::getSprite() {
    return Entity::getSprite();
}
