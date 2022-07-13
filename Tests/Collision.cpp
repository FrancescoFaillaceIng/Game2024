//
// Created by Francesco on 03/07/2022.
//

#include <gtest/gtest.h>
#include "../Include/World.h"

class Collision: public testing::Test{
protected:
    TextureHolder textures;

    std::shared_ptr<sf::RenderWindow> mWindow;
    std::shared_ptr<Strategy> strategy;

    sf::Vector2u windowSize;
};

TEST_F(Collision, Hero_Enemy){

    //load textures
    textures.load(Textures::StHero, "../../Resources/HeroSprite.png");
    textures.load(Textures::bull_fighter, "../../Resources/minotaur.png");
    textures.load(Textures::ghost_fighter, "../../Resources/ghost.png");
    textures.load(Textures::flying_fighter, "../../Resources/bat.png");

    //costruttori
    World World(mWindow, textures);
    std::shared_ptr<Hero> hero = World.hero;
    std::shared_ptr<Enemy> enemy = World.enemyArray.front();

    //vita eroe prima collisione
    EXPECT_EQ(hero->getHp(), 200);

    //collisione
    enemy->rect.setPosition(100, 100);
    World.CollisionsHeroEnemies();

    //vita eroe dopo collisione
    EXPECT_EQ(hero->getHp(), 180);
}

TEST_F(Collision, Hero_Map){

    //load textures
    textures.load(Textures::StHero,"../../Resources/HeroSprite.png");
    textures.load(Textures::WallText,"../../Resources/Wall.png");
    textures.load(Textures::FloorText, "../../Resources/Floor.png");

    //costruttori
    World World(mWindow, textures);
    std::shared_ptr<Hero> hero = World.hero;

    //condizioni muro a sinistra dell' eroe
    hero->rect.setPosition(64, 128);
    hero->setIsMovingUp(false);
    hero->setIsMovingDown(false);
    hero->setIsMovingRight(false);
    hero->setIsMovingLeft(true);

    //posizione eroe invariata
    World.Update();
    World.CollisionsHeroMap();
    EXPECT_EQ(hero->rect.getPosition().x, 64);
    EXPECT_EQ(hero->rect.getPosition().y, 128);
}

TEST_F(Collision, Enemy_Map){
    //load textures
    textures.load(Textures::flying_fighter,"../../Resources/HeroSprite.png");
    textures.load(Textures::bull_fighter,"../../Resources/HeroSprite.png");
    textures.load(Textures::flying_fighter,"../../Resources/H.png");
    textures.load(Textures::WallText,"../../Resources/Wall.png");
    textures.load(Textures::FloorText, "../../Resources/Floor.png");

    //costruttori
    World World(mWindow, textures);
    std::shared_ptr<Hero> hero = World.hero;

    //condizioni muro a sinistra dell' eroe
    hero->rect.setPosition(64, 128);
    hero->setIsMovingUp(false);
    hero->setIsMovingDown(false);
    hero->setIsMovingRight(false);
    hero->setIsMovingLeft(true);

    //posizione eroe invariata
    World.Update();
    World.CollisionsHeroMap();
    EXPECT_EQ(hero->rect.getPosition().x, 64);
    EXPECT_EQ(hero->rect.getPosition().y, 128);
}

TEST_F(Collision, Projectile_Enemy){

    //load textures
    textures.load(Textures::StHero, "../../Resources/HeroSprite.png");
    textures.load(Textures::bull_fighter, "../../Resources/minotaur.png");
    textures.load(Textures::ghost_fighter, "../../Resources/ghost.png");
    textures.load(Textures::flying_fighter, "../../Resources/bat.png");
    textures.load(Textures::StProjectile, "../../StProjectile.png");

    //costruttori
    World World(mWindow, textures);
    std::shared_ptr<Hero> hero = World.hero;
    std::shared_ptr<Enemy> enemy = World.enemyArray.front();

    //condizioni nemico a destra dell' eroe
    enemy->rect.setPosition(109, 100);
    EXPECT_EQ(enemy->getHp(), 20);

    std::shared_ptr<Projectile> projectile = std::make_shared<StProjectile>(textures, hero->getPosition());
    projectile->setDirection(Entity::right);
    World.projectilePlayerArray.emplace_back(projectile);
    EXPECT_EQ(World.projectilePlayerArray.empty(), false);
    EXPECT_EQ(World.projectilePlayerArray.front()->getPower(), 4);

    //test hp and array
    World.Update();
    World.CollisionsProjectilesEnemies();
    EXPECT_EQ(enemy->getHp(), 16);
    EXPECT_EQ(World.projectilePlayerArray.empty(), true);
}

TEST_F(Collision, Projectile_Map){

    //load textures
    textures.load(Textures::WallText, "../../Resources/Wall.png");
    textures.load(Textures::FloorText, "../../Resources/Floor.png");
    textures.load(Textures::StProjectile,"../../Resources/StProjectile.png");
    textures.load(Textures::StHero, "../../Resources/HeroSprite.png");

    //costruttori
    World World(mWindow, textures);
    std::shared_ptr<Hero> hero = World.hero;

    //condizioni muro a sinistra dell' eroe
    hero->rect.setPosition(64, 128);

    std::shared_ptr<Projectile> projectile = std::make_shared<StProjectile>(textures, hero->getPosition());
    projectile->setDirection(Entity::left);
    World.projectilePlayerArray.emplace_back(projectile);
    EXPECT_EQ(World.projectilePlayerArray.empty(), false);

    //collisione muro
    World.Update();
    World.CollisionsProjectilesMap();
    EXPECT_EQ(World.projectilePlayerArray.empty(), true);
}