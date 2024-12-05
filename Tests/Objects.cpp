//
// Created by franc on 05/12/2024.
//

#include <gtest/gtest.h>
#include "../Include/World.h"

class Objects: public testing::Test{
protected:
    TextureHolder textures;

    std::shared_ptr<sf::RenderWindow> tWindow;
    std::shared_ptr<World> tWorld;
    ObjectFactory objectFactory;

    sf::Vector2u windowSize;
};

TEST_F(Objects, CollectableObjects) {
    //load textures
    textures.load(Textures::StHero,"./Resources/HeroSprite.png");
    textures.load(Textures::StWeapon,"./Resources/StWeapon.png");
    textures.load(Textures::CoinText,"./Resources/Coins.png");
    textures.load(Textures::PotionText,"./Resources/Potion.png");

    //costruttori
    tWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(1500, 850),
                                                 "world test", sf::Style::Default);

    tWorld = std::make_shared<World>(tWindow, textures);

    //controllo arma
    std::shared_ptr<Object> weaponTest = tWorld->collectableObject[0];
    weaponTest->rect.setPosition(64, 64);

    EXPECT_EQ(tWorld->collectableObject.size(), 1);
    EXPECT_EQ(weaponTest->equipped, false);

    tWorld->collectObjects();

    EXPECT_EQ(tWorld->collectableObject.size(), 0);
    EXPECT_EQ(weaponTest->equipped, true);


    //controllo monete
    std::shared_ptr<Object> coinTest = objectFactory.createObject(Object::ObjectType::coins, 64, 64, textures);
    tWorld->collectableObject.emplace_back(coinTest);

    EXPECT_EQ(tWorld->collectableObject.size(), 1);
    EXPECT_EQ(tWorld->coins_counter, 0);

    tWorld->collectObjects();

    EXPECT_EQ(tWorld->collectableObject.size(), 0);
    EXPECT_EQ(tWorld->coins_counter, 1);


    //controllo pozione
    std::shared_ptr<Object> potionTest = objectFactory.createObject(Object::ObjectType::potion, 64, 64, textures);
    tWorld->collectableObject.emplace_back(potionTest);
    tWorld->hero->setHp(80);

    EXPECT_EQ(tWorld->collectableObject.size(), 1);
    EXPECT_EQ(tWorld->hero->getHp(), 80);

    tWorld->collectObjects();

    EXPECT_EQ(tWorld->collectableObject.size(), 0);
    EXPECT_EQ(tWorld->hero->getHp(), 100);
}