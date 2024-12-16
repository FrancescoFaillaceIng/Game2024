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
    upgradeAttackButton = std::make_shared<Button>(static_cast<float>(popupBackground.getSize().x),static_cast<float>(popupBackground.getSize().y), "Upgrade Attack", font);
    upgradeSpeedButton = std::make_shared<Button>(static_cast<float>(popupBackground.getSize().x),static_cast<float>(popupBackground.getSize().y), "Upgrade Speed", font);
    backButton = std::make_shared<Button>(static_cast<float>(popupBackground.getSize().x),static_cast<float>(popupBackground.getSize().y), "Back", font);

    addButton(upgradeAttackButton);
    addButton(upgradeSpeedButton);
    addButton(backButton);

    upgradeAttackButton->setPosition(popupBackground.getPosition().x + 225, popupBackground.getPosition().y + 20);
    upgradeSpeedButton->setPosition(popupBackground.getPosition().x + 225, popupBackground.getPosition().y + 100);
    backButton->setPosition(popupBackground.getPosition().x + 225, popupBackground.getPosition().y + 180);
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
    upgradeAttackButton->update(window, pos.x+225, pos.y+50);
    upgradeSpeedButton->update(window, pos.x+225, pos.y+150);
    backButton->update(window, pos.x+225, pos.y+250);
}
