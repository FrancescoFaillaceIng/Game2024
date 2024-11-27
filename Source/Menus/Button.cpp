//
// Created by franc on 19/11/2024.
//

#include <iostream>
#include "../../Include/Menus/Button.h"

Button::Button(int x, int y, const std::string &label, const sf::Font& font)
                            : defaultColor(sf::Color(sf::Color::White)), hoverColor(150, 150, 150) {
    int width = 400;
    int height = 50;

    this->font = font;
    shape.setPosition(x, y);
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color::White);

    text.setFont(font);
    text.setString(label);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);

    // Center text inside the button
    sf::FloatRect textBounds = text.getLocalBounds();
    text.setOrigin(textBounds.left + textBounds.width / 2.0f,textBounds.top + textBounds.height / 2.0f);
    text.setPosition(x + width / 2.0f, y + height / 2.0f);
}

// Render button on the window
void Button::render(std::shared_ptr<sf::RenderWindow> window) {
    window->draw(shape);
    window->draw(text);
}

// Check if button is clicked
bool Button::isClicked(std::shared_ptr<sf::RenderWindow> window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
    sf::Vector2f worldPos = window->mapPixelToCoords(mousePos);

    if (shape.getGlobalBounds().contains(worldPos)){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            return true;
        }
    }
    return false;
}

// Handle mouse hover and click color changes
void Button::handleMouse(std::shared_ptr<sf::RenderWindow> window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
    sf::Vector2f worldPos = window->mapPixelToCoords(mousePos);

    if (shape.getGlobalBounds().contains(worldPos)) {
        shape.setFillColor(hoverColor);

    } else {
        shape.setFillColor(defaultColor);

    }
}

void Button::setPosition(float x, float y) {
    shape.setPosition(x, y);

    // Update the text position to stay centered
    sf::FloatRect textBounds = text.getLocalBounds();
    text.setPosition(x + shape.getSize().x / 2.0f, y + shape.getSize().y / 2.0f);
}

void Button::update(std::shared_ptr<sf::RenderWindow> window, int x, int y) {
    int width = 400;
    int height = 50;
    shape.setPosition(x,y);
    text.setPosition(x + width / 2.0f, y + height / 2.0f);
}
