//
// Created by erosp on 25/07/2021.
//

#include <gtest/gtest.h>
#include "../Include/World.h"

class Movements: public testing::Test{
protected:
    TextureHolder textures;

    std::shared_ptr<Strategy> strategy;

    sf::Vector2u windowSize;
};

TEST_F(Movements, HeroMovement) {

//load textures
    textures.load(Textures::StHero, "../../Resources/HeroSprite.png");

//costruttori
    Hero Hero(Hero::StRanged, textures);

//test posizone iniziale
    EXPECT_EQ(Hero.rect.getPosition().x, 100);
    EXPECT_EQ(Hero.rect.getPosition().y, 100);
    Hero.setIsMovingRight(false);
    Hero.setIsMovingLeft(false);
    Hero.setIsMovingDown(false);
    Hero.setIsMovingUp(false);

//test speed
    EXPECT_EQ(Hero.getSpeedBasic(), 4);

//test movimento right
    Hero.setIsMovingRight(true);
    Hero.setDirection(Entity::right);
    Hero.Update();

    EXPECT_EQ(Hero.rect.getPosition().x, 104);
    EXPECT_EQ(Hero.rect.getPosition().y, 100);

    Hero.setIsMovingRight(false);

//test movimento down
    Hero.setIsMovingDown(true);
    Hero.setDirection(Entity::down);
    Hero.Update();

    EXPECT_EQ(Hero.rect.getPosition().x, 104);
    EXPECT_EQ(Hero.rect.getPosition().y, 104);

    Hero.setIsMovingDown(false);

//test movimento left
    Hero.setIsMovingLeft(true);
    Hero.setDirection(Entity::left);
    Hero.Update();

    EXPECT_EQ(Hero.rect.getPosition().x, 100);
    EXPECT_EQ(Hero.rect.getPosition().y, 104);

    Hero.setIsMovingLeft(false);

//test movimento up
    Hero.setIsMovingUp(true);
    Hero.setDirection(Entity::up);
    Hero.Update();

    EXPECT_EQ(Hero.rect.getPosition().x, 100);
    EXPECT_EQ(Hero.rect.getPosition().y, 100);

    Hero.setIsMovingDown(false);
}

TEST_F(Movements, EnemyMovement) {

    //load textures
    textures.load(Textures::bull_fighter, "../../Resources/minotaur.png");
    textures.load(Textures::ghost_fighter, "../../Resources/ghost.png");
    textures.load(Textures::flying_fighter, "../../Resources/bat.png");

    //costruttori
    MeleeEnemy MeleeEnemy(Enemy::meleeEnemy, windowSize,  textures, strategy);

    float x = MeleeEnemy.rect.getPosition().x;
    float y = MeleeEnemy.rect.getPosition().y;

    //test speed
    EXPECT_EQ(MeleeEnemy.getSpeedBasic(), 1);

    //test movimento right
    MeleeEnemy.setIsMovingRight(true);
    MeleeEnemy.Characters::setDirection(Entity::up);
    MeleeEnemy.Update();

    EXPECT_EQ(MeleeEnemy.rect.getPosition().x, x + 1);
    EXPECT_EQ(MeleeEnemy.rect.getPosition().y, y);

    MeleeEnemy.setIsMovingRight(false);

    //test movimento down
    MeleeEnemy.setIsMovingDown(true);
    MeleeEnemy.Characters::setDirection(Entity::down);
    MeleeEnemy.Update();

    EXPECT_EQ(MeleeEnemy.rect.getPosition().x, x + 1);
    EXPECT_EQ(MeleeEnemy.rect.getPosition().y, y + 1);

    MeleeEnemy.setIsMovingDown(false);

    //test movimento left
    MeleeEnemy.setIsMovingLeft(true);
    MeleeEnemy.Characters::setDirection(Entity::left);
    MeleeEnemy.Update();

    EXPECT_EQ(MeleeEnemy.rect.getPosition().x, x);
    EXPECT_EQ(MeleeEnemy.rect.getPosition().y, y + 1);

    MeleeEnemy.setIsMovingLeft(false);

    //test movimento up
    MeleeEnemy.setIsMovingUp(true);
    MeleeEnemy.Characters::setDirection(Entity::up);
    MeleeEnemy.Update();

    EXPECT_EQ(MeleeEnemy.rect.getPosition().x, x);
    EXPECT_EQ(MeleeEnemy.rect.getPosition().y, y);

    MeleeEnemy.setIsMovingDown(false);
}

TEST_F(Movements, ProjectileMovement) {

    //load textures
    textures.load(Textures::StHero, "../../Resources/HeroSprite.png");
    textures.load(Textures::StProjectile, "../../Resources/StProjectile.png");

    //costruttori
    Hero Hero(Hero::StRanged, textures);
    StProjectile StProjectile(textures, Hero.rect.getPosition());

    //test posizone iniziale
    float x = StProjectile.rect.getPosition().x;
    float y = StProjectile.rect.getPosition().y;

    EXPECT_EQ(x, Hero.rect.getPosition().x);
    EXPECT_EQ(y, Hero.rect.getPosition().y);

    //test speed
    EXPECT_EQ(StProjectile.getPspeed(), 10);

    //test movimento right
    StProjectile.setDirection(Entity::up);
    StProjectile.Update();

    EXPECT_EQ(StProjectile.rect.getPosition().x, x + 10);
    EXPECT_EQ(StProjectile.rect.getPosition().y, y);

    //test movimento down
    StProjectile.setDirection(Entity::down);
    StProjectile.Update();

    EXPECT_EQ(Hero.rect.getPosition().x, x);
    EXPECT_EQ(Hero.rect.getPosition().y, y + 10);

    //test movimento left
    StProjectile.setDirection(Entity::left);
    StProjectile.Update();

    EXPECT_EQ(Hero.rect.getPosition().x, x - 10);
    EXPECT_EQ(Hero.rect.getPosition().y, y);

    //test movimento up
    StProjectile.setDirection(Entity::up);
    StProjectile.Update();

    EXPECT_EQ(Hero.rect.getPosition().x, x);
    EXPECT_EQ(Hero.rect.getPosition().y, y - 10);
}
