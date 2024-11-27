//
// Created by erosp on 16/06/2021.
//

#include "../Include/Game.h"

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 80.f);

Game::Game() : mWindow(new sf::RenderWindow(sf::VideoMode(1725 , 978),
                                            "Typical journey", sf::Style::Default)) {
    isPowerUpMenuActive = false;

    loadTextures();
    world = std::make_shared<World>(mWindow, textureHolder);

    //sets the view
    view = std::make_shared<sf::View>(sf::Vector2f(world->hero->rect.getPosition()), sf::Vector2f(1500, 850));
    mWindow->setView(*view);

    game_menu = std::make_shared<Game_menu>(mWindow, view);
    game_menu->initButtons();

    powerupMenu = std::make_shared<PowerupMenu>(mWindow, view);
    powerupMenu->initButtons();

    //sets the icon
    sf::Image icon;
    if ( !icon.loadFromFile("./Resources/role-playing-game.png"))
        throw std::runtime_error("icon not loaded");
    mWindow->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    hero_lifebar = barsFactory.createBars(view->getCenter().x - (view->getSize().x)/2, view->getCenter().y -
                                                                                (view->getSize().y)/2, world->textures);
}

void Game::play() {
    sf::Clock clock;
    sf::Clock shootingClock;
    sf::Clock damageClock;
    sf::Time shootingTime = shootingClock.restart();
    sf::Time damageTime = damageClock.restart();
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (mWindow->isOpen()) {
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents(shootingClock);
            Update(damageClock);
        }
        render();
    }
}


void Game::render() {
    mWindow->clear();
    mWindow->setView(*view);
    world->draw();
    mWindow->draw(hero_lifebar->getSprite());
    if (!world->isRunning && !isPowerUpMenuActive){
        game_menu->render(mWindow);
        for(auto& button : game_menu->buttons)
            button->render(mWindow);
    } else if(isPowerUpMenuActive && !world->isRunning){
        powerupMenu->render(mWindow);
        for(auto& button : powerupMenu->buttons)
            button->render(mWindow);
    }

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

void Game::Update(sf::Clock &damageClock) {
    if(world->isRunning)
        world->Update(damageClock);
    else if (!world->isRunning && !isPowerUpMenuActive){
        game_menu->update(mWindow, sf::Vector2i(view->getCenter().x-400, view->getCenter().y-300));
        for(auto& button : game_menu->buttons){
            button->handleMouse(mWindow);
            if(button->isClicked(mWindow)){
                if(button->text.getString() == "Resume"){
                    world->isRunning = true;
                }
                else if (button->text.getString() == "Upgrade"){
                    isPowerUpMenuActive = true;
                }
                else if(button->text.getString() == "Exit") {
                    mWindow->close();
                }
            }
        }
    } else if (!world->isRunning && isPowerUpMenuActive){
        powerupMenu->update(mWindow, sf::Vector2i(view->getCenter().x-400, view->getCenter().y-300));
        for(auto& button : powerupMenu->buttons){
            button->handleMouse(mWindow);
            if(button->isClicked(mWindow)){
                if(button->text.getString() == "Upgrade MaxHp" && powerupMenu->counterPowerUp <= world->coins_counter){
                    world->hero->setHpMax(world->hero->getHpMax() + 10);
                    world->coins_counter -= powerupMenu->counterPowerUp;
                    powerupMenu->counterPowerUp++;
                }
                else if (button->text.getString() == "Upgrade Attack" && powerupMenu->counterPowerUp <= world->coins_counter){
                    world->hero->setAttackDamage(world->hero->getAttackDamage() + 2);
                    world->coins_counter -= powerupMenu->counterPowerUp;
                    powerupMenu->counterPowerUp++;
                }
                else if (button->text.getString() == "Upgrade Speed" && powerupMenu->counterPowerUp <= world->coins_counter){
                    world->hero->setSpeedBasic(world->hero->getSpeedBasic() + 1);
                    world->coins_counter -= powerupMenu->counterPowerUp;
                    powerupMenu->counterPowerUp++;
                }
                else if (button->text.getString() == "Back"){
                    isPowerUpMenuActive = false;
                }
            }
        }
    }
    view->setCenter(world->hero->rect.getPosition());
    LifeBarUpdate();

}

void Game::LifeBarUpdate() {
    hero_lifebar->update(view->getCenter().x - (view->getSize().x)/2, view->getCenter().y - (view->getSize().y)/2,
                                                                                            world->hero->getHp());
    if (world->hero->getHp() <= 0){
        free(&hero_lifebar);
    }
}

void Game::loadTextures() {
    //characters
    textureHolder.load(Textures::StHero, "./Resources/HeroSprite.png");
    textureHolder.load(Textures::bull_fighter,"./Resources/minotaur.png");
    textureHolder.load(Textures::flying_fighter,"./Resources/bat.png");
    textureHolder.load(Textures::ghost_fighter,"./Resources/ghost.png");

    //objects
    textureHolder.load(Textures::StWeapon, "./Resources/StWeapon.png");
    textureHolder.load(Textures::StProjectile,"./Resources/StProjectile.png");
    textureHolder.load(Textures::CoinText, "./Resources/Coins.png");
    textureHolder.load(Textures::PotionText, "./Resources/Potion.png");

    //map
    textureHolder.load(Textures::FloorText, "./Resources/Floor.png");
    textureHolder.load(Textures::WallText, "./Resources/Wall.png");

    //lifebar
    textureHolder.load(Textures::LifeBarText, "./Resources/LifeBar.png");
}