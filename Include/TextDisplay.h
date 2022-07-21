//
// Created by Francesco on 15/07/2022.
//

#ifndef GAME_TEXTDISPLAY_H
#define GAME_TEXTDISPLAY_H

#include "SFML/Graphics.hpp"

class TextDisplayClass {
public:
    sf::RectangleShape rect;
    sf::Sprite sprite;
    sf::Text text;
    std::string myString;
    int counter = 0;
    int lifeTime = 100;
    int movementSpeed = 1;
    bool destroy = false;

    TextDisplayClass();
    void Update();
};


#endif //GAME_TEXTDISPLAY_H
