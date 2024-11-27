//
// Created by franc on 19/11/2024.
//

#ifndef GAME_BUTTON_H
#define GAME_BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>
#include "memory"

class Button {

    private:
        sf::Color defaultColor;
        sf::Color hoverColor;

        sf::Font font;

    public:
        sf::RectangleShape shape;
        sf::Text text;

        Button(int x, int y, const std::string& label, const sf::Font& font);

        void setPosition(float x, float y);
        void update(std::shared_ptr<sf::RenderWindow> window, int x, int y);

        void render(std::shared_ptr<sf::RenderWindow> window);
        bool isClicked(std::shared_ptr<sf::RenderWindow> window);

        void handleMouse(std::shared_ptr<sf::RenderWindow> window);
};


#endif //GAME_BUTTON_H
