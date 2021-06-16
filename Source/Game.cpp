//
// Created by erosp on 16/06/2021.
//

#include "../Include/Game.h"

Game::Game() : Window(new sf::RenderWindow(sf::VideoMode(1500, 850), "Berto's Adventure", sf::Style::Default)) {}

void Game::play() {
    while (Window->isOpen()) {
    }
}

void Game::render() {
    Window->clear();

}