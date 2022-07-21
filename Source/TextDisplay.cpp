//
// Created by Francesco on 15/07/2022.
//

#include "../Include/TextDisplay.h"

TextDisplayClass::TextDisplayClass() {
    text.setFillColor(sf::Color::Red);
    text.setCharacterSize(15);
    text.setString(myString);
}

void TextDisplayClass::Update() {
    text.move(0, -movementSpeed);
    counter++;
    if (counter >= lifeTime)
        destroy = true;
}