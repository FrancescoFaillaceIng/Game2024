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
    StProjectile StProjectile_right(textures, Hero.rect.getPosition());
    StProjectile StProjectile_down(textures, Hero.rect.getPosition());
    StProjectile StProjectile_left(textures, Hero.rect.getPosition());
    StProjectile StProjectile_up(textures, Hero.rect.getPosition());

    //test posizioni iniziali
    EXPECT_EQ(StProjectile_right.rect.getPosition().x, 100);
    EXPECT_EQ(StProjectile_right.rect.getPosition().y, 100);

    EXPECT_EQ(StProjectile_down.rect.getPosition().x, 100);
    EXPECT_EQ(StProjectile_down.rect.getPosition().y, 100);

    EXPECT_EQ(StProjectile_left.rect.getPosition().x, 100);
    EXPECT_EQ(StProjectile_left.rect.getPosition().y, 100);

    EXPECT_EQ(StProjectile_up.rect.getPosition().x, 100);
    EXPECT_EQ(StProjectile_up.rect.getPosition().y, 100);

    //test speed
    EXPECT_EQ(StProjectile_right.getPspeed(), 10);
    EXPECT_EQ(StProjectile_down.getPspeed(), 10);
    EXPECT_EQ(StProjectile_left.getPspeed(), 10);
    EXPECT_EQ(StProjectile_up.getPspeed(), 10);

    //test movimento
    StProjectile_right.setDirection(Entity::right);
    StProjectile_down.setDirection(Entity::down);
    StProjectile_left.setDirection(Entity::left);
    StProjectile_up.setDirection(Entity::up);

    StProjectile_right.Update();
    StProjectile_down.Update();
    StProjectile_left.Update();
    StProjectile_up.Update();

    //right
    EXPECT_EQ(StProjectile_right.rect.getPosition().x, 110);
    EXPECT_EQ(StProjectile_right.rect.getPosition().y, 100);

    //down
    EXPECT_EQ(StProjectile_down.rect.getPosition().x, 100);
    EXPECT_EQ(StProjectile_down.rect.getPosition().y, 110);

    //left
    EXPECT_EQ(StProjectile_left.rect.getPosition().x, 90);
    EXPECT_EQ(StProjectile_left.rect.getPosition().y, 100);

    //up
    EXPECT_EQ(StProjectile_up.rect.getPosition().x, 100);
    EXPECT_EQ(StProjectile_up.rect.getPosition().y, 90);
}
