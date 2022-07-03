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
    Hero Hero(Hero::StRanged, textures);
    MeleeEnemy MeleeEnemy(Enemy::meleeEnemy, windowSize,  textures, strategy);

//vita eroe prima collisione
    EXPECT_EQ(Hero.getHp(), 200);

//collisione
    MeleeEnemy.rect.setPosition(Hero.rect.getPosition());
    EXPECT_EQ(MeleeEnemy.getAttackDamage(), 20);
    World.CollisionsHeroEnemies();

//vita eroe dopo collisione
    EXPECT_EQ(Hero.getHp(), 180);
}

TEST_F(Collision, Hero_Map){

}

TEST_F(Collision, Enemy_Map){

}

TEST_F(Collision, Projectile_Enemy){

}

TEST_F(Collision, Projectile_Map){

}