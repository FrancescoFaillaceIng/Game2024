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

    //gives 3 different textures
    int t = GenerateRandom(3);
    if (t == 1) texture = textures.get(Textures::bull_fighter);
    if (t == 2) texture = textures.get(Textures::flying_fighter);
    if (t == 3) texture = textures.get(Textures::ghost_fighter);

    isMovingDown = false;
    isMovingLeft = false;
    isMovingRight = false;
    isMovingUp = false;

    speedBasic = 1;
    hp = 20;
    hpMax = hp;
    attackDamage = 20;

    //makes 3 differents spawn points
    int p = GenerateRandom(3);
    if (p == 1) {
        position.x = 64*2;
        position.y = 64*2;
    }
    if (p == 2) {
        position.x = 64*8;
        position.y = 64*8;
    }
    if (p == 3) {
        position.x = 64*11;
        position.y = 64*11;
    }

    rect.setPosition(position);
    rect.setSize(sf::Vector2f(32, 32));

    sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    sprite.setPosition(rect.getPosition());
    sprite.setTexture(texture);
}