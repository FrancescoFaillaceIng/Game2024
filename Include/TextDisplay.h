//
// Created by Francesco on 12/07/2022.
//

#ifndef GAME_TEXTDISPLAY_H
#define GAME_TEXTDISPLAY_H

#include "SFML/Graphics.hpp"

class TextDisplay {
public:
    TextDisplay();

    void setBarPosition(float x, float y);

    sf::RectangleShape rect;
    sf::Sprite sprite;
    sf::Text text;

    sf::Font font;

    std::string myString;
    sf::Vector2f bar_position;
};


#endif //GAME_TEXTDISPLAY_H
