//
// Created by erosp on 16/06/2021.
//

#include "../Include/Game.h"

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 80.f);

Game::Game() : mWindow(new sf::RenderWindow(sf::VideoMode(400, 250), "Berto's Adventure", sf::Style::Default)) {

    //sets the icon
    sf::Image icon;
    if ( !icon.loadFromFile("../Resources/role-playing-game.png"))
        throw std::runtime_error("icon not loaded");
    mWindow->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void Game::play() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (mWindow->isOpen()) {

        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
        }
        render();
    }
}

void Game::render() {
    mWindow->clear();
    //world->draw(); //TODO risolvere crash con world->draw()
    mWindow->display();
}

void  Game::processEvents() {
    sf::Event event;

    while (mWindow->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                mWindow->close();
            default:
                break;
        }
    }
}

void Game::loadTextures() {
    textureHolder.load(Textures::StHero, "Resources/HeroSprite.png");
}