//
// Created by erosp on 16/06/2021.
//

#include "../Include/Game.h"

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 80.f);

Game::Game() : mWindow(new sf::RenderWindow(sf::VideoMode(1500, 850),
                                            "Berto's Adventure", sf::Style::Default)) {

    loadTextures();
    world = std::make_shared<World>(mWindow, textureHolder);

    //sets the view
    view = std::make_shared<sf::View>(sf::Vector2f(world->hero->rect.getPosition()), sf::Vector2f(1500, 850));
    mWindow->setView(*view);

    //sets the icon
    sf::Image icon;
    if ( !icon.loadFromFile("../Resources/role-playing-game.png"))
        throw std::runtime_error("icon not loaded");
    mWindow->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    //hero_lifebar = barsFactory.createBars(view->getCenter().x - view->getSize().x/2, view->getCenter().y - view->getSize().y);
}

void Game::play() {
    sf::Clock clock;
    sf::Clock shootingClock;
    sf::Time shootingTime = shootingClock.restart();
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (mWindow->isOpen()) {
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents(shootingClock);
            Update();
        }
        render();
    }
}


void Game::render() {
    mWindow->clear();
    mWindow->setView(*view);
    world->draw();
    //mWindow->draw(hero_lifebar->getSprite());
    mWindow->display();
}

void  Game::processEvents(sf::Clock &shootingClock) {
    sf::Event event;

    while (mWindow->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                mWindow->close();
                break;
            case sf::Event::KeyPressed:
                world->PlayerInput(event.key.code, true, shootingClock);
                break;
            case sf::Event::KeyReleased:
                world->PlayerInput(event.key.code, false, shootingClock);
                break;
            default:
                break;
        }
    }
}

void Game::Update() {
    world->Update();
    view->setCenter(world->hero->rect.getPosition());
    //hero_lifebar->update(view->getCenter().x - view->getSize().x/2, view->getCenter().y - view->getSize().y, world->hero->getHp());
}

void Game::loadTextures() {
    //characters
    textureHolder.load(Textures::StHero, "../Resources/HeroSprite.png");
    textureHolder.load(Textures::bull_fighter,"../Resources/minotaur.png");
    textureHolder.load(Textures::flying_fighter,"C:\\Users\\franc\\CLionProjects\\Game\\Resources\\bat.png");
    textureHolder.load(Textures::ghost_fighter,"C:\\Users\\franc\\CLionProjects\\Game\\Resources\\ghost.png");

    //objects
    textureHolder.load(Textures::StWeapon, "../Resources/StWeapon.png");
    textureHolder.load(Textures::StProjectile,"../Resources/StProjectile.png");
    textureHolder.load(Textures::CoinText, "../Resources/Coins.png");
    textureHolder.load(Textures::PotionText, "../Resources/Potion.png");

    //map
    textureHolder.load(Textures::FloorText, "../Resources/Floor.png");
    textureHolder.load(Textures::WallText, "../Resources/Wall.png");

    //lifebar
    //textureHolder.load(Textures::LifeBarText, "../Resources/LifeBar.png");
}