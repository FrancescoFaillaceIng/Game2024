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

    int a = GenerateRandom(3);
    int b;
    if (a == 1) b = 64*2;
    if (a == 2) b = 64*8;
    if (a == 3) b = 64*11;
    position.x = b;
    position.y = b;


    rect.setPosition(position);
    rect.setSize(sf::Vector2f(32, 32));

    sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    sprite.setPosition(rect.getPosition());
    sprite.setTexture(texture);
}