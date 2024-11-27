//
// Created by franc on 19/11/2024.
//

#include "../../Include/Menus/Game_menu.h"

// Constructor to initialize font
Game_menu::Game_menu(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<sf::View> view){
    if(!font.loadFromFile("BRADHITC.TTF"))
        std::cerr << "Error: font not found.";


    popupBackground.setFillColor(sf::Color(60, 20, 0));
    popupBackground.setOutlineColor(sf::Color::White);
    popupBackground.setOutlineThickness(3);
    popupBackground.setPosition(static_cast<float>(window->getSize().x) * 25 / 100,
                                static_cast<float>(window->getSize().y) * 30 / 100);
    popupBackground.setSize(sf::Vector2f(static_cast<float>(window->getSize().x) * 50 / 100,
                                         static_cast<float>(window->getSize().y) * 40 / 100));

}

// Add a new button to the Game_menu
void Game_menu::addButton(std::shared_ptr<Button> button) {
    buttons.emplace_back(button);
}

void Game_menu::initButtons() {
    button1 = std::make_shared<Button>(static_cast<float>(popupBackground.getSize().x),static_cast<float>(popupBackground.getSize().y), "Resume", font);
    button2 = std::make_shared<Button>(static_cast<float>(popupBackground.getSize().x),static_cast<float>(popupBackground.getSize().y), "Upgrade", font);
    button3 = std::make_shared<Button>(static_cast<float>(popupBackground.getSize().x),static_cast<float>(popupBackground.getSize().y), "Exit", font);

    addButton(button1);
    addButton(button2);
    addButton(button3);

    button1->setPosition(popupBackground.getPosition().x + 225, popupBackground.getPosition().y + 50);
    button2->setPosition(popupBackground.getPosition().x + 225, popupBackground.getPosition().y + 150);
    button3->setPosition(popupBackground.getPosition().x + 225, popupBackground.getPosition().y + 250);
}

// Render all buttons
void Game_menu::render(std::shared_ptr<sf::RenderWindow> window) {
    for (auto& button : buttons) {
        button->render(window);
    }

    window->draw(popupBackground);
}

// Update button hover and click effects
void Game_menu::update(std::shared_ptr<sf::RenderWindow> window, sf::Vector2i pos) {
    popupBackground.setPosition(sf::Vector2f(pos.x, pos.y));
    button1->update(window, pos.x+225, pos.y+50);
    button2->update(window, pos.x+225, pos.y+150);
    button3->update(window, pos.x+225, pos.y+250);
}