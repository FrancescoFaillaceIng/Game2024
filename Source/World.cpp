//
// Created by Francesco on 18/06/2021.
//

#include "../Include/World.h"

World::World(std::shared_ptr<sf::RenderWindow> window, const TextureHolder &textures): window(window),
                                                                                       textures(textures){

    createMap();
    createHero();
    createEnemies();
    createObjects();

    _mObserver = std::make_shared<mObserver>();
    addObserver(_mObserver);
}

void World::PlayerInput(sf::Keyboard::Key key, bool isPressed, sf::Clock& shootingClock) {
    if (key == sf::Keyboard::W){
        hero->setDirection(Entity::up);
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
    CollisionsHeroMap();
    CollisionsEnemiesMap();
    CollisionsProjectilesMap();
}

void World::CollisionsHeroEnemies() {
    for (auto iter = enemyArray.begin(); iter != enemyArray.end(); iter++){

        // if an enemy touches the hero, hero's life decrease
        if (hero->rect.getGlobalBounds().intersects((*iter)->rect.getGlobalBounds())){
            hero->setHp(hero->getHp()-(*iter)->getAttackDamage());
            std::cout << "hero's life is:" << hero->getHp() << std::endl;
        }
    }
}

void World::CollisionsProjectilesEnemies() {
    std::shared_ptr<Strategy> newStrategy = std::make_shared<SeekStrategy>(window->getSize());
    for (auto iter = enemyArray.begin(); iter != enemyArray.end(); iter++){
        for (auto iter1 = projectilePlayerArray.begin(); iter1 != projectilePlayerArray.end(); iter1++){

            // if a projectile touches an enemy, enemy's life decrease and the projectiles disappear
            if((*iter)->rect.getGlobalBounds().intersects((*iter1)->rect.getGlobalBounds())){
                iter1 = projectilePlayerArray.erase(iter1);
                (*iter)->setHp((*iter)->getHp()-(*iter1)->getPower()-hero->getAttackDamage());
                (*iter)->strategy = newStrategy;
                if (iter1 == projectilePlayerArray.end())
                    break;
            }
        }
    }
}

void World::CollisionsHeroMap() {
    for (auto i = map->tileArray.begin(); i != map->tileArray.end(); i++){
        if (hero->rect.getGlobalBounds().intersects((*i)->rect.getGlobalBounds())){
            if (!((*i)->isWalkable())){
                switch (hero->getDirection()) {
                    case Entity::up:
                        hero->rect.move(0, hero->getSpeedBasic());
                        break;
                    case Entity::down:
                        hero->rect.move(0, -(hero->getSpeedBasic()));
                        break;
                    case Entity::right:
                        hero->rect.move(-hero->getSpeedBasic(), 0);
                        break;
                    case Entity::left:
                        hero->rect.move(hero->getSpeedBasic(), 0);
                        break;
                }

            }
        }
    }
}

void World::CollisionsEnemiesMap() {
    for (auto i = map->tileArray.begin(); i != map->tileArray.end(); i++){
        for (auto j = enemyArray.begin(); j != enemyArray.end(); j++){
            if ((*j)->rect.getGlobalBounds().intersects((*i)->rect.getGlobalBounds())){
                if (!(*i)->isWalkable()){
                    switch ((*j)->getDirection()) {
                        case Entity::up:
                            (*j)->rect.move(0, (*j)->getSpeedBasic());
                            break;
                        case Entity::down:
                            (*j)->rect.move(0, -((*j)->getSpeedBasic()));
                            break;
                        case Entity::right:
                            (*j)->rect.move(-((*j)->getSpeedBasic()), 0);
                            break;
                        case Entity::left:
                            (*j)->rect.move((*j)->getSpeedBasic(), 0);
                            break;
                    }
                    (*j)->changeDirection();
                }
            }
        }
    }
}

void World::CollisionsProjectilesMap() {
    for (auto i = map->tileArray.begin(); i != map->tileArray.end(); i++){
        for (auto j = projectilePlayerArray.begin(); j != projectilePlayerArray.end(); j++){

            // if a projectile touches a wall, the projectile disappear
            if (!(*i)->isWalkable()){
                if ((*i)->rect.getGlobalBounds().intersects((*j)->rect.getGlobalBounds())){
                    j = projectilePlayerArray.erase(j);
                    if (j == projectilePlayerArray.end())
                        break;
                }
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
    CheckGlobalBounds();
}

void World::UpdateMap() {
    for(auto i = map->tileArray.begin(); i != map->tileArray.end(); i++){
        (*i)->UpdateTile();
    }
}

void World::UpdateHero() {
    hero->Update();
    if (hero->getHp() <= 0){
        hero->active = false;
    }
    if (!hero->active){
       //free(&hero);
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
                Drop((*iter)->rect.getPosition().x, (*iter)->rect.getPosition().y);
                (*iter)->active = false;
            }
            if ( !(*iter)->active ) {
                iter = enemyArray.erase(iter);
                if( iter == enemyArray.end())
                    createEnemies();
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
    std::shared_ptr<Object> weapon = objectFactory.createObject(Object::ObjectType::stWeapon, 192, 192, textures);

    collectableObject.emplace_back(weapon);
}

void World::createHero() {
    //create the hero
    hero = characterFactory.createHero(Characters::goodboy, Hero::StRanged, textures);
}

void World::createEnemies() {
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

            // if hero pick up an object, the object is added to hero's inventory and the object disappear from the map
            if ( (*iter)->getRect().getGlobalBounds().intersects(hero->getRect().getGlobalBounds())) {
                switch ((*iter)->objectType) {
                    case Object::stWeapon:
                        hero->PickUpObject(*iter);
                        (*iter)->equipped = true;
                        break;
                    case Object::coins:
                        coins_counter++;
                        if (coins_counter >= 2){
                            notify();
                            coins_counter = 0;
                            std::cout << hero->getAttackDamage();
                        }
                        break;
                    case Object::potion:
                        if(hero->getHp() < hero->getHpMax()){
                            hero->setHp(hero->getHp() + 20);
                        }
                        std::cout << "hero's life is:" << hero->getHp() << std::endl;
                        break;
                }
                iter = collectableObject.erase(iter);
                if (iter == collectableObject.end())
                    break;
            }
        }
    }
}

void World::Drop(float x, float y) {
    int t = GenerateRandom(3);
    std::shared_ptr<Object> ObjectDropped;
    if (t == 1 || t == 2){
        ObjectDropped = objectFactory.createObject(Object::ObjectType::coins, x, y, textures);
    }
    if (t ==3){
        ObjectDropped = objectFactory.createObject(Object::ObjectType::potion, x, y, textures);
    }

    collectableObject.emplace_back(ObjectDropped);
}

void World::Shoot() {

    //when hero shoot, create a projectile and put in projectilePLayerArray
    if(hero->Shoot()){
        std::shared_ptr<Projectile> worldProjectile = projectileFactory.createProjectile(Projectile::stProjectile,
                                                                                         textures, hero->rect.getPosition());
        worldProjectile->active = true;
        worldProjectile->setDirection(hero->getDirection());
        projectilePlayerArray.emplace_back(worldProjectile);

    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void World::addObserver(std::shared_ptr<mObserver> observer) {
    coin_observer.emplace_back(observer);
}

void World::removeObserver(std::shared_ptr<mObserver> observer) {
}

void World::notify() {
    for(auto iter = coin_observer.begin(); iter != coin_observer.end(); iter++){
        (*iter)->update(this->hero);
    }
}
