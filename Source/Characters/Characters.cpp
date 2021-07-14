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
                rect.setPosition(x, y-speedBasic);
                sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32*3, 32, 32));
                break;
            case down:
                rect.setPosition(x, y+speedBasic);
                sprite.setTextureRect(sf::IntRect(counterWalking * 32, 0, 32, 32));
                break;
            case left:
                rect.setPosition(x-speedBasic, y);
                sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32, 32, 32));
                break;
            case right:
                rect.setPosition(x+speedBasic, y);
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



