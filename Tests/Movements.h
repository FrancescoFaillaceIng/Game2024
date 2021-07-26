//
// Created by erosp on 25/07/2021.
//

#ifndef MAIN_CPP_MOVEMENTS_H
#define MAIN_CPP_MOVEMENTS_H

#include "gtest/gtest.h"
#include "../Include/World.h"

TEST(MovementTest, Movement) {
//load textures
    TextureHolder textureHolder;
    textureHolder.load(Textures::StHero, "../../Resources/HeroSprite.png");
    textureHolder.load(Textures::StWeapon, "../../Resources/StWeapon.png");

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//costruttori
    Hero Hero(Hero::StRanged, textureHolder);
    StWeapon StWeapon(textureHolder);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//test posizone iniziale
    //eroe
    EXPECT_EQ(Hero.rect.getPosition().x, 32);
    EXPECT_EQ(Hero.rect.getPosition().y, 32);
    //arma
    EXPECT_EQ(StWeapon.rect.getPosition().x, 64);
    EXPECT_EQ(StWeapon.rect.getPosition().y, 64);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//test movimento right
    Hero.isMovingRight = true;
    Hero.Update();

    //eroe
    EXPECT_EQ(Hero.rect.getPosition().x, 36);
    EXPECT_EQ(Hero.rect.getPosition().y, 32);
    Hero.isMovingRight = false;

//test movimento down
    Hero.isMovingDown = true;
    Hero.Update();

    //eroe
    EXPECT_EQ(Hero.rect.getPosition().x, 36);
    EXPECT_EQ(Hero.rect.getPosition().y, 36);
    Hero.isMovingDown = false;

//test movimento left
    Hero.isMovingLeft = true;
    Hero.Update();

    //eroe
    EXPECT_EQ(Hero.rect.getPosition().x, 32);
    EXPECT_EQ(Hero.rect.getPosition().y, 36);
    Hero.isMovingLeft = false;

//test movimento up
    Hero.isMovingUp = true;
    Hero.Update();

    //eroe
    EXPECT_EQ(Hero.rect.getPosition().x, 32);
    EXPECT_EQ(Hero.rect.getPosition().y, 32);
    Hero.isMovingUp = false;

}
#endif //MAIN_CPP_MOVEMENTS_H
