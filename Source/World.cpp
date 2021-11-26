//
// Created by Francesco on 18/06/2021.
//

#include <memory>
#include "../Include/World.h"

World::World(std::shared_ptr<sf::RenderWindow> window, const TextureHolder &textures): window(window), map(),
            textures(textures){

    createCharacter();
    createObjects();
}

void World::Update() {
    hero->Update();
    UpdateEnemies();
}

void World::draw() {
    drawObject();
    drawHero();
    drawEnemies();
}

void World::drawHero() {
    window->draw(hero->getSprite());
}

void World::drawObject() {
    if (!collectableObject.empty()){
        for (auto iter = collectableObject.begin(); iter != collectableObject.end(); iter++){
            if ((*iter) -> active && !(*iter)->equipped)
                window->draw((*iter)->getSprite());
        }
    }
}

void World::drawEnemies(){
    if(!enemyArray.empty()) {
        int counter = 0;
        for (auto iter = enemyArray.begin(); iter != enemyArray.end(); iter++ ) {
            window->draw((*iter)->getSprite());
        }
    }
}

void World::UpdateEnemies() {
    if(!enemyArray.empty()) {
        int counter = 0;
        int deleted = -1;
        for ( auto iter = enemyArray.begin(); iter != enemyArray.end(); iter++ ) {

            //set hero position to the strategy
            auto seekStrategy = std::dynamic_pointer_cast<SeekStrategy>((*iter)->strategy);
            if(seekStrategy != nullptr) {
                seekStrategy->heroPosition = hero->getPosition();
            }
            (*iter)->Update();

            if ( !(*iter)->active ) {
                //enemyArray.erase(iter);
            }
        }
    }
}

void World::PlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::W){
        hero->setDirection(Entity::up) ;
        hero->setIsMovingUp(isPressed);
    }
    else if (key == sf::Keyboard::S){
        hero->setDirection(Entity::down);
        hero->setIsMovingDown(isPressed);
    }
    else if (key == sf::Keyboard::A){
        hero->setDirection(Entity::left);
        hero->setIsMovingLeft(isPressed);
    }
    else if (key == sf::Keyboard::D){
        hero->setDirection(Entity::right);
        hero->setIsMovingRight(isPressed);
    }
    else if (key == sf::Keyboard::E)
        collectObjects();

    else if (key == sf::Keyboard::Space){
        Shoot();
    }
    else if (key == sf::Keyboard::Escape && isPressed)
        window->close();
}

void World::createObjects() {
    //create a weapon with objectfactory
    std::shared_ptr<Object> weapon = objectFactory.createObject(Object::ObjectType::stWeapon, textures);

    collectableObject.emplace_back(weapon);
}

void World::createCharacter() {

    //create the hero
    this->hero = characterFactory.createHero(Characters::goodboy, Hero::StRanged, textures);

    //create enemies
    for(int i = 0; i <= 10; i++){
        std::shared_ptr<Enemy> fighter = characterFactory.createEnemy(Characters::badguy,Enemy::meleeEnemy,
                                                                      window->getSize(), textures);

        enemyArray.emplace_back(fighter);
    }

}

void World::collectObjects() {
    if(!collectableObject.empty()) {
        for (auto iter = collectableObject.begin(); iter != collectableObject.end(); iter++ ) {
            if ( (*iter)->getRect().getGlobalBounds().intersects(hero->getRect().getGlobalBounds())) {
                hero->PickUpObject(*iter);
                (*iter)->equipped = true;
                iter = collectableObject.erase(iter);
                if (iter == collectableObject.end())
                    break;
            } else std::cout<<"nothing to pick up"<<std::endl;
        }
    }
}

void World::Shoot() {
    if(hero->Shoot()){
        std::cout<<"shoot"<<std::endl;
        std::shared_ptr<Weapon> mWeapon = std::dynamic_pointer_cast<Weapon>(hero->getWeapon());
    }
}