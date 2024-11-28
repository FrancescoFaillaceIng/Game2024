//
// Created by erosp on 16/06/2021.
//

#include "../Include/Game.h"

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 80.f);

Game::Game() : mWindow(new sf::RenderWindow(sf::VideoMode(1725 , 978),
                                            "Typical journey", sf::Style::Default)) {
    isGameOver = false;
    isPowerUpMenuActive = false;

    speedTextBackground.setFillColor(sf::Color::Black);
    attackDamageTextBackground.setFillColor(sf::Color::Black);
    coinsTextBackground.setFillColor(sf::Color::Black);
    gameOverTextBackground.setFillColor(sf::Color::Black);

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

    //sets the font
    if(!font.loadFromFile("BRADHITC.TTF"))
        std::cerr << "Error: font not found.";

    hero_lifebar = barsFactory.createBars(view->getCenter().x - (view->getSize().x)/2, view->getCenter().y -
                                                                                (view->getSize().y)/2, world->textures);
}

void Game::play() {
    sf::Clock clock;
    sf::Clock shootingClock;
    sf::Clock damageClock;
    sf::Clock menuClock;

    sf::Time shootingTime = shootingClock.restart();
    sf::Time damageTime = damageClock.restart();
    sf::Time menuTime = menuClock.restart();
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (mWindow->isOpen()) {
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents(shootingClock);
            Update(damageClock, menuClock);
        }
        render();
    }
}


void Game::render() {
    mWindow->clear();
    mWindow->setView(*view);

    if (isGameOver){
        mWindow->draw(gameOverTextBackground);
        mWindow->draw(gameOverText);
    } else {
        world->draw();

        mWindow->draw(hero_lifebar->getSprite());

        mWindow->draw(speedTextBackground);
        mWindow->draw(attackDamageTextBackground);
        mWindow->draw(coinsTextBackground);

        mWindow->draw(speedText);
        mWindow->draw(attackDamageText);
        mWindow->draw(coinsText);
    }

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

void Game::Update(sf::Clock &damageClock, sf::Clock &menuClock) {
    if(world->isRunning && !isGameOver)
        world->Update(damageClock);
    else if (!world->isRunning && !isPowerUpMenuActive){
        game_menu->update(mWindow, sf::Vector2i(view->getCenter().x-400, view->getCenter().y-300));
        for(auto& button : game_menu->buttons){
            button->handleMouse(mWindow);
            if(button->isClicked(mWindow) && menuClock.getElapsedTime().asSeconds() >= 1){
                if(button->text.getString() == "Resume"){
                    world->isRunning = true;
                }
                else if (button->text.getString() == "Upgrade"){
                    isPowerUpMenuActive = true;
                }
                else if(button->text.getString() == "Exit") {
                    mWindow->close();
                }
            menuClock.restart();
            }
        }
    } else if (!world->isRunning && isPowerUpMenuActive){
        powerupMenu->update(mWindow, sf::Vector2i(view->getCenter().x-400, view->getCenter().y-300));
        for(auto& button : powerupMenu->buttons){
            button->handleMouse(mWindow);
            if(button->isClicked(mWindow)  && menuClock.getElapsedTime().asSeconds() >= 1){
                if (button->text.getString() == "Upgrade Attack" && powerupMenu->counterPowerUp <= world->coins_counter){
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
            menuClock.restart();
            }
        }
    } else if (isGameOver){
        UpdateGameOverText();
    }

    view->setCenter(world->hero->rect.getPosition());

    LifeBarUpdate();
    UpdateSpeedText();
    UpdateAttackDamageText();
    UpdateCoinsText();

}

void Game::LifeBarUpdate() {
    hero_lifebar->update(view->getCenter().x - (view->getSize().x)/2, view->getCenter().y - (view->getSize().y)/2,
                                                                                            world->hero->getHp());
    if (world->hero->getHp() <= 0){
        isGameOver = true;
    }
}

void Game::UpdateSpeedText() {
    speedText.setFont(font);
    speedText.setCharacterSize(20);
    speedText.setFillColor(sf::Color::White);
    speedText.setPosition(view->getCenter().x - (view->getSize().x)/2, view->getCenter().y - ((view->getSize().y)/2) + 100);
    speedText.setString("Speed: " + std::to_string(world->hero->getSpeedBasic()));

    speedTextBackground.setSize(sf::Vector2f(speedText.getLocalBounds().width + 10,speedText.getLocalBounds().height + 15));
    speedTextBackground.setPosition(speedText.getPosition().x - 5, speedText.getPosition().y - 5);
}

void Game::UpdateAttackDamageText() {
    attackDamageText.setFont(font);
    attackDamageText.setCharacterSize(20);
    attackDamageText.setFillColor(sf::Color::White);
    attackDamageText.setPosition(view->getCenter().x - (view->getSize().x)/2, view->getCenter().y - ((view->getSize().y)/2) + 150);
    attackDamageText.setString("Attack Damage: " + std::to_string(world->hero->getAttackDamage()));

    attackDamageTextBackground.setSize(sf::Vector2f(attackDamageText.getLocalBounds().width + 10,attackDamageText.getLocalBounds().height + 15));
    attackDamageTextBackground.setPosition(attackDamageText.getPosition().x - 5, attackDamageText.getPosition().y - 5);
}

void Game::UpdateCoinsText() {
    coinsText.setFont(font);
    coinsText.setCharacterSize(20);
    coinsText.setFillColor(sf::Color::White);
    coinsText.setPosition(view->getCenter().x - (view->getSize().x)/2, view->getCenter().y - ((view->getSize().y)/2) + 200);
    coinsText.setString("Coins: " + std::to_string(world->coins_counter));

    coinsTextBackground.setSize(sf::Vector2f(coinsText.getLocalBounds().width + 10,coinsText.getLocalBounds().height + 15));
    coinsTextBackground.setPosition(coinsText.getPosition().x - 5, coinsText.getPosition().y - 5);
}

void Game::UpdateGameOverText() {
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(150);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(view->getCenter().x - 400, view->getCenter().y - 200);
    gameOverText.setString("GAME OVER");

    gameOverTextBackground.setSize(sf::Vector2f(gameOverText.getLocalBounds().width + 10,gameOverText.getLocalBounds().height + 75));
    gameOverTextBackground.setPosition(gameOverText.getPosition().x - 5, gameOverText.getPosition().y - 5);
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