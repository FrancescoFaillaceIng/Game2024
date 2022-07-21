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
};

TEST_F(Collision, Hero_Enemy){

    //load textures
    textures.load(Textures::StHero, "../../Resources/HeroSprite.png");
    textures.load(Textures::bull_fighter, "../../Resources/minotaur.png");
    textures.load(Textures::ghost_fighter, "../../Resources/ghost.png");
    textures.load(Textures::flying_fighter, "../../Resources/bat.png");

    //costruttori
    tWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(1500, 850),
                                                 "Berto's Adventure", sf::Style::Default);

    tWorld = std::make_shared<World>(tWindow, textures);

    //vita eroe prima collisione
    EXPECT_EQ(tWorld->hero->getHp(), 200);

    //collisione
    tWorld->enemyArray.front()->rect.setPosition(100, 100);
    tWorld->CollisionsHeroEnemies();

    //vita eroe dopo collisione
    EXPECT_EQ(tWorld->hero->getHp(), 180);
}

TEST_F(Collision, Hero_Map){

    //load textures
    textures.load(Textures::StHero,"../../Resources/HeroSprite.png");
    textures.load(Textures::WallText,"../../Resources/Wall.png");
    textures.load(Textures::FloorText, "../../Resources/Floor.png");

    //costruttori
    tWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(1500, 850),
                                                 "Berto's Adventure", sf::Style::Default);

    tWorld = std::make_shared<World>(tWindow, textures);

    //condizioni muro sopra all' eroe
    tWorld->hero->rect.setPosition(64, 64);
    tWorld->hero->setIsMovingLeft(false);
    tWorld->hero->setIsMovingUp(true);
    tWorld->hero->setIsMovingDown(false);
    tWorld->hero->setIsMovingRight(false);

    //posizione eroe invariata
    tWorld->UpdateHero();
    tWorld->CollisionsHeroMap();
    EXPECT_EQ(tWorld->hero->rect.getPosition().x, 64);
    EXPECT_EQ(tWorld->hero->rect.getPosition().y, 64);
}

TEST_F(Collision, Enemy_Map){
    //load textures
    textures.load(Textures::ghost_fighter,"../../Resources/ghost.png");
    textures.load(Textures::bull_fighter,"../../Resources/minotaur.png");
    textures.load(Textures::flying_fighter,"../../Resources/bat.png");
    textures.load(Textures::WallText,"../../Resources/Wall.png");
    textures.load(Textures::FloorText, "../../Resources/Floor.png");

    //costruttori
    tWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(1500, 850),
                                                 "Berto's Adventure", sf::Style::Default);

    tWorld = std::make_shared<World>(tWindow, textures);
    tEnemy = tWorld->enemyArray.front();

    //condizioni muro a sinistra del nemico
    tEnemy->rect.setPosition(64, 64);
    tEnemy->setIsMovingUp(true);
    tEnemy->setIsMovingDown(false);
    tEnemy->setIsMovingRight(false);
    tEnemy->setIsMovingLeft(false);

    //posizione nemico invariata
    tWorld->UpdateEnemies();
    tWorld->CollisionsEnemiesMap();
    EXPECT_EQ(tEnemy->rect.getPosition().x, 64);
    EXPECT_EQ(tEnemy->rect.getPosition().y, 64);
}

TEST_F(Collision, Projectile_Enemy){

    //load textures
    textures.load(Textures::StHero, "../../Resources/HeroSprite.png");
    textures.load(Textures::bull_fighter, "../../Resources/minotaur.png");
    textures.load(Textures::ghost_fighter, "../../Resources/ghost.png");
    textures.load(Textures::flying_fighter, "../../Resources/bat.png");
    textures.load(Textures::StProjectile, "C:\\Users\\franc\\CLionProjects\\Game\\Resources\\StProjectile.png");

    //costruttori
    tWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(1500, 850),
                                                 "Berto's Adventure", sf::Style::Default);

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
    textures.load(Textures::WallText, "../../Resources/Wall.png");
    textures.load(Textures::FloorText, "../../Resources/Floor.png");
    textures.load(Textures::StProjectile,"../../Resources/StProjectile.png");
    textures.load(Textures::StHero, "../../Resources/HeroSprite.png");

    //costruttori
    tWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(1500, 850),
                                                 "Berto's Adventure", sf::Style::Default);

    tWorld = std::make_shared<World>(tWindow, textures);

    std::shared_ptr<Projectile> projectile = std::make_shared<StProjectile>(textures, tWorld->hero->getPosition());
    tWorld->projectilePlayerArray.emplace_back(projectile);
    EXPECT_EQ(tWorld->projectilePlayerArray.empty(), false);

    //collisione muro
    tWorld->projectilePlayerArray.front()->rect.setPosition(32, 32);
    tWorld->CollisionsProjectilesMap();
    EXPECT_EQ(tWorld->projectilePlayerArray.empty(), true);
}