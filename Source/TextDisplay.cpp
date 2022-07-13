//
// Created by Francesco on 12/07/2022.
//

#include "../Include/TextDisplay.h"

TextDisplay::TextDisplay() {
    rect.setSize(sf::Vector2f(32, 8));

    sf::Text textHP("HP ", font, 20);

    text.setFillColor(sf::Color::Red);
    text.setCharacterSize(15);
    text.setString(myString);
}

void TextDisplay::setBarPosition(float x, float y) {
    bar_position.x = x;
    bar_position.y = y;
}
