//
// Created by erosp on 25/07/2021.
//

#include <gtest/gtest.h>
#include "../Include/World.h"

class Movements: public testing::Test{
protected:
    TextureHolder textures;

    std::shared_ptr<Strategy> strategy;
    std::shared_ptr<Hero> tHero;
    std::shared_ptr<Enemy> tEnemy;
    std::shared_ptr<Projectile> tProjectile_up;
    std::shared_ptr<Projectile> tProjectile_left;
    std::shared_ptr<Projectile> tProjectile_down;
    std::shared_ptr<Projectile> tProjectile_right;

    sf::Vector2u windowSize;
};

TEST_F(Movements, HeroMovement) {

//load textures
    textures.load(Textures::StHero, "../../Resources/HeroSprite.png");

//costruttori
    tHero = std::make_shared<Hero>(Hero::StRanged, textures);

//test posizone iniziale
    EXPECT_EQ(tHero->rect.getPosition().x, 100);
    EXPECT_EQ(tHero->rect.getPosition().y, 100);
    tHero->setIsMovingRight(false);
    tHero->setIsMovingLeft(false);
    tHero->setIsMovingDown(false);
    tHero->setIsMovingUp(false);

//test speed
    EXPECT_EQ(tHero->getSpeedBasic(), 4);

//test movimento right
    tHero->setIsMovingRight(true);
    tHero->setDirection(Entity::right);
    tHero->Update();

    EXPECT_EQ(tHero->rect.getPosition().x, 104);
    EXPECT_EQ(tHero->rect.getPosition().y, 100);

    tHero->setIsMovingRight(false);

//test movimento down
    tHero->setIsMovingDown(true);
    tHero->setDirection(Entity::down);
    tHero->Update();

    EXPECT_EQ(tHero->rect.getPosition().x, 104);
    EXPECT_EQ(tHero->rect.getPosition().y, 104);

    tHero->setIsMovingDown(false);

//test movimento left
    tHero->setIsMovingLeft(true);
    tHero->setDirection(Entity::left);
    tHero->Update();

    EXPECT_EQ(tHero->rect.getPosition().x, 100);
    EXPECT_EQ(tHero->rect.getPosition().y, 104);

    tHero->setIsMovingLeft(false);

//test movimento up
    tHero->setIsMovingUp(true);
    tHero->setDirection(Entity::up);
    tHero->Update();

    EXPECT_EQ(tHero->rect.getPosition().x, 100);
    EXPECT_EQ(tHero->rect.getPosition().y, 100);

    tHero->setIsMovingDown(false);
}

TEST_F(Movements, EnemyMovement) {

    //load textures
    textures.load(Textures::bull_fighter, "../../Resources/minotaur.png");
    textures.load(Textures::ghost_fighter, "../../Resources/ghost.png");
    textures.load(Textures::flying_fighter, "../../Resources/bat.png");

    //costruttori
    strategy = std::make_shared<PatrolStrategy>(windowSize);
    tEnemy = std::make_shared<MeleeEnemy>(Enemy::meleeEnemy, windowSize,  textures, strategy);

    tEnemy->setIsMovingRight(false);
    tEnemy->setIsMovingLeft(false);
    tEnemy->setIsMovingDown(false);
    tEnemy->setIsMovingUp(false);

    //test speed
    EXPECT_EQ(tEnemy->getSpeedBasic(), 1);

    //test movimento left
    tEnemy->rect.setPosition(100, 100);

    tEnemy->setIsMovingLeft(true);
    tEnemy->Update();

    EXPECT_EQ(tEnemy->rect.getPosition().x, 99);
    EXPECT_EQ(tEnemy->rect.getPosition().y, 100);

    tEnemy->setIsMovingLeft(false);

    //test movimento down
    tEnemy->setIsMovingDown(true);
    tEnemy->Update();

    EXPECT_EQ(tEnemy->rect.getPosition().x, 99);
    EXPECT_EQ(tEnemy->rect.getPosition().y, 101);

    tEnemy->setIsMovingDown(false);

    //test movimento right
    tEnemy->setIsMovingRight(true);
    tEnemy->Update();

    EXPECT_EQ(tEnemy->rect.getPosition().x, 100);
    EXPECT_EQ(tEnemy->rect.getPosition().y, 101);

    tEnemy->setIsMovingRight(false);

    //test movimento up
    tEnemy->setIsMovingUp(true);
    tEnemy->Update();

    EXPECT_EQ(tEnemy->rect.getPosition().x, 100);
    EXPECT_EQ(tEnemy->rect.getPosition().y, 100);

    tEnemy->setIsMovingDown(false);
}

TEST_F(Movements, ProjectileMovement) {

    //load textures
    textures.load(Textures::StHero, "../../Resources/HeroSprite.png");
    textures.load(Textures::StProjectile, "../../Resources/tProjectile.png");

    //costruttori
    tHero = std::make_shared<Hero>(Hero::StRanged, textures);
    tProjectile_up = std::make_shared<StProjectile>(textures, tHero->rect.getPosition());
    tProjectile_right = std::make_shared<StProjectile>(textures, tHero->rect.getPosition());
    tProjectile_down = std::make_shared<StProjectile>(textures, tHero->rect.getPosition());
    tProjectile_left = std::make_shared<StProjectile>(textures, tHero->rect.getPosition());

    //test posizioni iniziali
    EXPECT_EQ(tProjectile_right->rect.getPosition().x, 100);
    EXPECT_EQ(tProjectile_right->rect.getPosition().y, 100);

    EXPECT_EQ(tProjectile_down->rect.getPosition().x, 100);
    EXPECT_EQ(tProjectile_down->rect.getPosition().y, 100);

    EXPECT_EQ(tProjectile_left->rect.getPosition().x, 100);
    EXPECT_EQ(tProjectile_left->rect.getPosition().y, 100);

    EXPECT_EQ(tProjectile_up->rect.getPosition().x, 100);
    EXPECT_EQ(tProjectile_up->rect.getPosition().y, 100);

    //test speed
    EXPECT_EQ(tProjectile_right->getPspeed(), 10);
    EXPECT_EQ(tProjectile_down->getPspeed(), 10);
    EXPECT_EQ(tProjectile_left->getPspeed(), 10);
    EXPECT_EQ(tProjectile_up->getPspeed(), 10);

    //test movimento
    tProjectile_right->setDirection(Entity::right);
    tProjectile_down->setDirection(Entity::down);
    tProjectile_left->setDirection(Entity::left);
    tProjectile_up->setDirection(Entity::up);

    tProjectile_right->Update();
    tProjectile_down->Update();
    tProjectile_left->Update();
    tProjectile_up->Update();

    //right
    EXPECT_EQ(tProjectile_right->rect.getPosition().x, 110);
    EXPECT_EQ(tProjectile_right->rect.getPosition().y, 100);

    //down
    EXPECT_EQ(tProjectile_down->rect.getPosition().x, 100);
    EXPECT_EQ(tProjectile_down->rect.getPosition().y, 110);

    //left
    EXPECT_EQ(tProjectile_left->rect.getPosition().x, 90);
    EXPECT_EQ(tProjectile_left->rect.getPosition().y, 100);

    //up
    EXPECT_EQ(tProjectile_up->rect.getPosition().x, 100);
    EXPECT_EQ(tProjectile_up->rect.getPosition().y, 90);
}
