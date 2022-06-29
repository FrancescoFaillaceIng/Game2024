//
// Created by Francesco on 18/06/2021.
//

#include <memory>
#include "../Include/World.h"

World::World(std::shared_ptr<sf::RenderWindow> window, const TextureHolder &textures): window(window),
                                                                                       textures(textures){

    createMap();
    createCharacters();
    createObjects();
}


void World::PlayerInput(sf::Keyboard::Key key, bool isPressed, sf::Clock& shootingClock) {
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

    else if (key == sf::Keyboard::Space && isPressed){
        if(shootingClock.getElapsedTime().asSeconds() >= 0.2) {
            Shoot();
            shootingClock.restart();
        }
    }
    else if (key == sf::Keyboard::Escape && isPressed)
        window->close();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//collisions
void World::CheckGlobalBounds() {
    CollisionsHeroEnemies();
    CollisionsProjectilesEnemies();
    //TODO check hero touches walls
    //TODO check enemies touch walls
    //TODO check projectiles touch walls
}

void World::CollisionsHeroEnemies() {
    for (auto iter = enemyArray.begin(); iter != enemyArray.end(); iter++){
        if (hero->rect.getGlobalBounds().intersects((*iter)->rect.getGlobalBounds())){
            std::cout<<"touched"<<std::endl;
            hero->setHp(hero->getHp()-(*iter)->getAttackDamage());
        }
    }
}

void World::CollisionsProjectilesEnemies() {
    std::shared_ptr<Strategy> newStrategy = std::make_shared<SeekStrategy>(window->getSize());
    for (auto iter = enemyArray.begin(); iter != enemyArray.end(); iter++){
        for (auto iter1 = projectilePlayerArray.begin(); iter1 != projectilePlayerArray.end(); iter1++){
            if((*iter)->rect.getGlobalBounds().intersects((*iter1)->rect.getGlobalBounds())){
                std::cout<<"hit"<<std::endl;
                iter1 = projectilePlayerArray.erase(iter1);
                (*iter)->setHp((*iter)->getHp()-(*iter1)->getPower());
                (*iter)->strategy = newStrategy;
                if (iter1 == projectilePlayerArray.end())
                    break;
            }
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//updates
void World::Update() {
    UpdateMap();
    UpdateHero();
    UpdateEnemies();
    UpdateProjectiles();
}

void World::UpdateMap() {
    for(auto i = map->tileArray.begin(); i != map->tileArray.end(); i++){
        (*i)->UpdateTile();
    }
}

void World::UpdateHero() {
    hero->Update();
    if (hero->getHp() <= 0){
        //TODO hero dies
    }
}

void World::UpdateEnemies() {
    if(!enemyArray.empty()) {
        for ( auto iter = enemyArray.begin(); iter != enemyArray.end(); iter++ ) {

            //set hero position to the strategy
            auto seekStrategy = std::dynamic_pointer_cast<SeekStrategy>((*iter)->strategy);
            if(seekStrategy != nullptr) {
                seekStrategy->heroPosition = hero->rect.getPosition();
                seekStrategy->enemyPos = (*iter)->rect.getPosition();
            }
            (*iter)->Update();
            if ((*iter)->getHp()<=0){
                (*iter)->active = false;
            }
            if ( !(*iter)->active ) {
                iter = enemyArray.erase(iter);
                if( iter == enemyArray.end())
                    break;
            }
        }
    }
}

void World::UpdateProjectiles() {
    if (!projectilePlayerArray.empty()){
        for ( auto iter = projectilePlayerArray.begin(); iter != projectilePlayerArray.end(); iter ++)
            (*iter)->Update();
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//draws
void World::draw() {
    drawMap();

    drawHero();
    drawEnemies();

    drawObject();
    drawProjectiles();
}

void World::drawMap() {
    if(!map->tileArray.empty()){
        for(auto i = map->tileArray.begin(); i != map->tileArray.end(); i++){
            window->draw((*i)->getSprite());
        }
    }
}

void World::drawHero() {
    window->draw(hero->getSprite());
}

void World::drawEnemies(){
    if(!enemyArray.empty()) {
        for (auto iter = enemyArray.begin(); iter != enemyArray.end(); iter++ ) {
            window->draw((*iter)->getSprite());
        }
    }
}

void World::drawObject() {
    if (!collectableObject.empty()){
        for (auto iter = collectableObject.begin(); iter != collectableObject.end(); iter++){
            if ((*iter) -> active && !(*iter)->equipped)
                window->draw((*iter)->getSprite());
        }
    }
}

void World::drawProjectiles() {
    if (!projectilePlayerArray.empty()){
        for (auto iter = projectilePlayerArray.begin(); iter != projectilePlayerArray.end(); iter++){
            if ((*iter) -> active)
                window->draw((*iter)->getSprite());
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//creations
void World::createMap() {
    //create the map
    map = std::make_shared<Map>(textures);
}

void World::createObjects() {
    //create a weapon
    std::shared_ptr<Object> weapon = objectFactory.createObject(Object::ObjectType::stWeapon, textures);

    collectableObject.emplace_back(weapon);
}

void World::createCharacters() {

    //create the hero
    hero = characterFactory.createHero(Characters::goodboy, Hero::StRanged, textures);

    //create enemies
    for(int i = 0; i <= 10; i++){
        std::shared_ptr<Enemy> fighter = characterFactory.createEnemy(Characters::badguy,Enemy::meleeEnemy,
                                                                      window->getSize(), textures);
        fighter->active = true;
        enemyArray.emplace_back(fighter);
    }

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//actions
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
        if(mWeapon != nullptr) {
            std::shared_ptr<Projectile> worldProjectile = projectileFactory.createProjectile(Projectile::stProjectile,
                                                                                             textures, hero->rect.getPosition());
            worldProjectile->active = true;
            worldProjectile->setDirection(hero->getDirection());
            projectilePlayerArray.emplace_back(worldProjectile);
            std::cout<<"proj +1"<<std::endl;
        }
    } else
        std::cout<<"can't shoot"<<std::endl;
}