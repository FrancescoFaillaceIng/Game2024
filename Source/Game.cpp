//
// Created by erosp on 16/06/2021.
//

#include "../Include/Game.h"

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 80.f);

Game::Game() : mWindow(new sf::RenderWindow(sf::VideoMode(1500, 850),
                                            "Berto's Adventure", sf::Style::Default)) {

    loadTextures();
    world = std::make_shared<World>(mWindow, textureHolder);

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
            Update();
        }
        render();
    }
}

void Game::render() {
    mWindow->clear();
    world->draw();
    mWindow->display();
}

void  Game::processEvents() {
    sf::Event event;

    while (mWindow->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                mWindow->close();
                break;
            case sf::Event::KeyPressed:
                world->PlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                world->PlayerInput(event.key.code, false);
                break;
            default:
                break;
        }
    }
}

void Game::Update() {
    world->Update();
}

void Game::loadTextures() {
    textureHolder.load(Textures::StHero, "../Resources/HeroSprite.png");
}