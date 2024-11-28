//
// Created by franc on 19/11/2024.
//

#ifndef GAME_GAME_MENU_H
#define GAME_GAME_MENU_H

#include "SFML/Graphics.hpp"
#include <vector>
#include "iostream"
#include "Button.h"

class Game_menu {
private:
    std::shared_ptr<sf::RenderWindow> menu_window;
    sf::Font font;
    sf::RectangleShape popupBackground;


public:
    std::vector<std::shared_ptr<Button>> buttons;
    std::shared_ptr<Button> button1;
    std::shared_ptr<Button> button2;
    std::shared_ptr<Button> button3;

    explicit Game_menu(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<sf::View> view);

    void addButton(std::shared_ptr<Button> button);
    void initButtons();

    void render(std::shared_ptr<sf::RenderWindow> window);
    void update(std::shared_ptr<sf::RenderWindow> window, sf::Vector2i pos);

};



#endif //GAME_GAME_MENU_H
