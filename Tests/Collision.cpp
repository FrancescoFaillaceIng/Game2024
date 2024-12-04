//
// Created by Francesco on 03/07/2022.
//

#include <gtest/gtest.h>
#include "../Include/World.h"

class Collision: public testing::Test{
protected:
    TextureHolder textures;

    std::shared_ptr<sf::RenderWindow> tWindow;
    std::shared_ptr<World> tWorld;
    std::shared_ptr<Strategy> strategy;
    std::shared_ptr<Enemy> tEnemy;

    sf::Vector2u windowSize;
    sf::Clock damageClock;
};

TEST_F(Collision, Hero_Enemy){
    //costruttori
    textures.load(Textures::StHero, "./Resources/HeroSprite.png");
    textures.load(Textures::bull_fighter,"./Resources/minotaur.png");
    textures.load(Textures::flying_fighter,"./Resources/bat.png");
    textures.load(Textures::ghost_fighter,"./Resources/ghost.png");

    tWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(1500, 850),
                                                 "world test", sf::Style::Default);

    tWorld = std::make_shared<World>(tWindow, textures);
    tEnemy = tWorld->enemyArray.front();

    //vita eroe prima collisione
    EXPECT_EQ(tWorld->hero->getHp(), 100);
    EXPECT_EQ(tEnemy->getAttackDamage(),20 );

    //collisione
    tWorld->hero->rect.setPosition(100, 100);
    tEnemy->rect.setPosition(100, 100);

    while(damageClock.getElapsedTime() < sf::seconds(3));
    tWorld->CollisionsHeroEnemies(damageClock);

    //vita eroe dopo collisione
    EXPECT_EQ(tWorld->hero->getHp(), 80);
}

TEST_F(Collision, Hero_Map){

    //load textures
    textures.load(Textures::StHero,"./Resources/HeroSprite.png");
    textures.load(Textures::WallText,"./Resources/Wall.png");
    textures.load(Textures::FloorText, "./Resources/Floor.png");

    //costruttori
    tWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(1500, 850),
                                                 "world test", sf::Style::Default);

    tWorld = std::make_shared<World>(tWindow, textures);

    //posizione iniziale eroe
    EXPECT_EQ(tWorld->hero->rect.getPosition().x, 64);
    EXPECT_EQ(tWorld->hero->rect.getPosition().y, 64);

    //condizioni muro sopra all' eroe
    tWorld->hero->setDirection(Characters::up);
    tWorld->hero->setIsMovingLeft(false);
    tWorld->hero->setIsMovingUp(true);
    tWorld->hero->setIsMovingDown(false);
    tWorld->hero->setIsMovingRight(false);

    //posizione eroe invariata
    tWorld->Update(damageClock);
    EXPECT_EQ(tWorld->hero->rect.getPosition().x, 64);
    EXPECT_EQ(tWorld->hero->rect.getPosition().y, 64);

    //condizioni muro a sinistra dell' eroe
    tWorld->hero->setDirection(Characters::left);
    tWorld->hero->setIsMovingLeft(true);
    tWorld->hero->setIsMovingUp(false);
    tWorld->hero->setIsMovingDown(false);
    tWorld->hero->setIsMovingRight(false);

    //posizione eroe invariata
    tWorld->Update(damageClock);
    EXPECT_EQ(tWorld->hero->rect.getPosition().x, 64);
    EXPECT_EQ(tWorld->hero->rect.getPosition().y, 64);

    tWorld->hero->rect.setPosition(352,352);

    //condizioni muro a destra dell' eroe
    tWorld->hero->setDirection(Characters::right);
    tWorld->hero->setIsMovingLeft(false);
    tWorld->hero->setIsMovingUp(false);
    tWorld->hero->setIsMovingDown(false);
    tWorld->hero->setIsMovingRight(true);

    //posizione eroe invariata
    tWorld->Update(damageClock);
    EXPECT_EQ(tWorld->hero->rect.getPosition().x, 352);
    EXPECT_EQ(tWorld->hero->rect.getPosition().y, 352);

    //condizioni muro a sotto all' eroe
    tWorld->hero->setDirection(Characters::down);
    tWorld->hero->setIsMovingLeft(false);
    tWorld->hero->setIsMovingUp(false);
    tWorld->hero->setIsMovingDown(true);
    tWorld->hero->setIsMovingRight(false);

    //posizione eroe invariata
    tWorld->Update(damageClock);
    EXPECT_EQ(tWorld->hero->rect.getPosition().x, 352);
    EXPECT_EQ(tWorld->hero->rect.getPosition().y, 352);
}

TEST_F(Collision, Enemy_Map){
    //load textures
    textures.load(Textures::ghost_fighter,"./Resources/ghost.png");
    textures.load(Textures::bull_fighter,"./Resources/minotaur.png");
    textures.load(Textures::flying_fighter,"./Resources/bat.png");
    textures.load(Textures::WallText,"./Resources/Wall.png");
    textures.load(Textures::FloorText, "./Resources/Floor.png");

    //costruttori
    tWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(1500, 850),
                                                 "world test", sf::Style::Default);

    tWorld = std::make_shared<World>(tWindow, textures);
    tEnemy = tWorld->enemyArray[0];

    tEnemy->rect.setPosition(64, 64);

    //condizioni muro a sinistra del nemico
    tEnemy->setIsMovingUp(false);
    tEnemy->setIsMovingDown(false);
    tEnemy->setIsMovingRight(false);
    tEnemy->setIsMovingLeft(true);

    //posizione nemico invariata
    tWorld->UpdateEnemies();
    tWorld->CollisionsEnemiesMap();
    EXPECT_EQ(tEnemy->rect.getPosition().x, 64);
    EXPECT_EQ(tEnemy->rect.getPosition().y, 64);
}

TEST_F(Collision, Projectile_Enemy){

    //load textures
    textures.load(Textures::StHero, "./Resources/HeroSprite.png");
    textures.load(Textures::bull_fighter, "./Resources/minotaur.png");
    textures.load(Textures::ghost_fighter, "./Resources/ghost.png");
    textures.load(Textures::flying_fighter, "./Resources/bat.png");
    textures.load(Textures::StProjectile, "./Resources/StProjectile.png");

    //costruttori
    tWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(1500, 850),
                                                 "world test", sf::Style::Default);

    tWorld = std::make_shared<World>(tWindow, textures);
    tEnemy = tWorld->enemyArray.front();
    tEnemy->rect.setPosition(110, 100);
    EXPECT_EQ(tEnemy->getHp(), 20);

    std::shared_ptr<Projectile> projectile = std::make_shared<StProjectile>(textures, tWorld->hero->getPosition());
    tWorld->projectilePlayerArray.emplace_back(projectile);
    EXPECT_EQ(tWorld->projectilePlayerArray.empty(), false);
    EXPECT_EQ(tWorld->projectilePlayerArray.front()->getPower(), 4);

    //test hp and array
    tWorld->projectilePlayerArray.front()->rect.setPosition(110, 100);
    tWorld->CollisionsProjectilesEnemies();

    EXPECT_EQ(tEnemy->getHp(), 16);
    EXPECT_EQ(tWorld->projectilePlayerArray.empty(), true);
}

TEST_F(Collision, Projectile_Map){

    //load textures
    textures.load(Textures::WallText, "./Resources/Wall.png");
    textures.load(Textures::FloorText, "./Resources/Floor.png");
    textures.load(Textures::StProjectile,"./Resources/StProjectile.png");
    textures.load(Textures::StHero, "./Resources/HeroSprite.png");

    //costruttori
    tWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(1500, 850),
                                                 "world test", sf::Style::Default);

    tWorld = std::make_shared<World>(tWindow, textures);

    std::shared_ptr<Projectile> projectile = std::make_shared<StProjectile>(textures, tWorld->hero->getPosition());
    tWorld->projectilePlayerArray.emplace_back(projectile);
    EXPECT_EQ(tWorld->projectilePlayerArray.empty(), false);

    //collisione muro
    tWorld->projectilePlayerArray.front()->rect.setPosition(32, 32);
    tWorld->CollisionsProjectilesMap();
    EXPECT_EQ(tWorld->projectilePlayerArray.empty(), true);
}