//
// Created by erosp on 16/06/2021.
//

#include "../Include/Game.h"

Game::Game() : Window(new sf::RenderWindow(sf::VideoMode(400, 250), "Berto's Adventure", sf::Style::Default)) {

    //sets the icon
    sf::Image icon;
    if ( !icon.loadFromFile("../Resources/role-playing-game.png"))
        throw std::runtime_error("icon not loaded");
    Window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void Game::play() {
    while (Window->isOpen()) {
        processEvents();
    }
}

void Game::render() {
    Window->clear();

}

void  Game::processEvents() {
    sf::Event event;
    World world = World();
    while (Window->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                Window->close();
            default:
                break;
        }
        Window->clear();
        Window->display();
        /*for (int i = 0; i < world.gridLength; i++){
            for(int j = 0; j < world.gridLength; j++){
                Window->draw(world.tiles[i][j]->sprite);
            }
        }*/ //TODO capire perchè crasha


    }
}