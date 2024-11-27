//
// Created by franc on 19/11/2024.
//

#include "../../Include/Menus/PowerupMenu.h"

// Constructor to initialize font
PowerupMenu::PowerupMenu(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<sf::View> view) {
    if(!font.loadFromFile("BRADHITC.TTF"))
        std::cerr << "Error: font not found.";


    popupBackground.setFillColor(sf::Color(60, 20, 0));
    popupBackground.setOutlineColor(sf::Color::White);
    popupBackground.setOutlineThickness(3);
    popupBackground.setPosition(static_cast<float>(window->getSize().x) * 25 / 100,
                                static_cast<float>(window->getSize().y) * 30 / 100);
    popupBackground.setSize(sf::Vector2f(static_cast<float>(window->getSize().x) * 50 / 100,
                                         static_cast<float>(window->getSize().y) * 40 / 100));

    counterPowerUp = 1;

}

// Add a new button to the Game_menu
void PowerupMenu::addButton(std::shared_ptr<Button> button) {
    buttons.emplace_back(button);
}

void PowerupMenu::initButtons() {
    button1 = std::make_shared<Button>(static_cast<float>(popupBackground.getSize().x),static_cast<float>(popupBackground.getSize().y), "Upgrade MaxHp", font);
    button2 = std::make_shared<Button>(static_cast<float>(popupBackground.getSize().x),static_cast<float>(popupBackground.getSize().y), "Upgrade Attack", font);
    button3 = std::make_shared<Button>(static_cast<float>(popupBackground.getSize().x),static_cast<float>(popupBackground.getSize().y), "Upgrade Speed", font);
    button4 = std::make_shared<Button>(static_cast<float>(popupBackground.getSize().x),static_cast<float>(popupBackground.getSize().y), "Back", font);

    addButton(button1);
    addButton(button2);
    addButton(button3);
    addButton(button4);

    button1->setPosition(popupBackground.getPosition().x + 225, popupBackground.getPosition().y + 20);
    button2->setPosition(popupBackground.getPosition().x + 225, popupBackground.getPosition().y + 100);
    button3->setPosition(popupBackground.getPosition().x + 225, popupBackground.getPosition().y + 180);
    button4->setPosition(popupBackground.getPosition().x + 225, popupBackground.getPosition().y + 260);
}

// Render all buttons
void PowerupMenu::render(std::shared_ptr<sf::RenderWindow> window) {
    for (auto& button : buttons) {
        button->render(window);
    }

    window->draw(popupBackground);
}

// Update button hover and click effects
void PowerupMenu::update(std::shared_ptr<sf::RenderWindow> window, sf::Vector2i pos) {
    popupBackground.setPosition(sf::Vector2f(pos.x, pos.y));
    button1->update(window, pos.x+225, pos.y+20);
    button2->update(window, pos.x+225, pos.y+120);
    button3->update(window, pos.x+225, pos.y+220);
    button4->update(window, pos.x+225, pos.y+320);
}
