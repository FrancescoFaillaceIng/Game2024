//
// Created by Francesco on 14/10/2021.
//

#include "../../Include/Characters/MeleeEnemy.h"

MeleeEnemy::MeleeEnemy(Enemy::EnemyType enemyType, sf::Vector2u windowSize, const TextureHolder &textures,
                       std::shared_ptr<Strategy> strategy): textures(textures) {

    if(std::dynamic_pointer_cast<PatrolStrategy>(strategy) != nullptr)
        this->strategy = std::make_shared<PatrolStrategy>(windowSize);
    else
        std::cout <<"errore sulla conversione della strategia"<< std::endl;

    texture = textures.get(Textures::fighter);

    isMovingDown = false;
    isMovingLeft = false;
    isMovingRight = false;
    isMovingUp = false;

    speedBasic = 1;
    hp = 20;
    hpMax = hp;
    attackDamage = 20;

    int x,y;
    x = GenerateRandom(64*5);
    y = GenerateRandom(64*5);

    rect.setPosition(x, y);
    rect.setSize(sf::Vector2f(32, 32));

    sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    sprite.setPosition(rect.getPosition());
    sprite.setTexture(texture);
}