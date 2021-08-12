//
// Created by Francesco on 18/06/2021.
//

#include <memory>
#include "../Include/World.h"

World::World(std::shared_ptr<sf::RenderWindow> window, const TextureHolder &textures): window(window),
        textures(textures), hero(new Hero(Hero::HeroType::StRanged, textures)), stweapon(new StWeapon(textures)){

   /* gridLength = 8;
    setUpInitialState();*/

   createObjects();
}

void World::setUpInitialState() {
    exitPos = sf::Vector2i(1, 0);
    HeroPos = sf::Vector2i(gridLength-1, gridLength-1);
    setUpEnemyPositions();
}

void World::setUpEnemyPositions() {
    /*enemyPositions.clear();
    //TODO meglio emplace_back o push_back (es: enemyPositions.push_back(sf::Vector2i(x, y)) )?
    enemyPositions.emplace_back(0, 2);
    enemyPositions.emplace_back(6, 0);
    enemyPositions.emplace_back(2, 7);*/
}

void World::draw() {
    drawWeapon();
    drawHero();
}

void World::drawHero() {
    window->draw(hero->getSprite());
}

void World::drawWeapon() {
    window->draw(stweapon->getSprite());
}

void World::PlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::W){
        hero->direction = Entity::up;
        hero->isMovingUp = isPressed;
    }
    else if (key == sf::Keyboard::S){
        hero->direction = Entity::down;
        hero->isMovingDown = isPressed;
    }
    else if (key == sf::Keyboard::A){
        hero->direction = Entity::left;
        hero->isMovingLeft = isPressed;
    }
    else if (key == sf::Keyboard::D){
        hero->direction = Entity::right;
        hero->isMovingRight = isPressed;
    }
    else if (key == sf::Keyboard::E)
        collectObjects();
    else if (key == sf::Keyboard::Escape && isPressed)
        window->close();
}

void World::createObjects() {
    //create a weapon
    std::shared_ptr<Object> weapon = objectFactory.createObject(Object::ObjectType::stWeapon, textures);

    collectableObject.emplace_back(weapon);
}

void World::collectObjects() {
    if(!collectableObject.empty()) {
        for (  auto iter = collectableObject.begin(); iter != collectableObject.end(); iter++ ) {
            if ( (*iter)->rect.getGlobalBounds().intersects(hero->rect.getGlobalBounds())) {
                hero->PickUpObject(*iter);
                std::cout << "collecting object" << std::endl;
                iter = collectableObject.erase(iter);
                if (iter == collectableObject.end()) {
                    std::cout << "did it" << std::endl;
                    break;
                }
            }
        }
    }
}

void World::Update() {
    hero->Update();
}

void World::setUpTiles() {
    tiles.clear();
    std::vector<Tile *> firstRow;
    firstRow.push_back(new Tile("???", 0, 0, false, false)); //wall tile
    firstRow.push_back(new Tile("???", 32, 0, true, true)); //exit tile
    firstRow.push_back(new Tile("???", 64, 0, false, false)); //wall tile
    firstRow.push_back(new Tile("???", 96, 0, false, false)); //wall tile
    firstRow.push_back(new Tile("???", 128, 0, false, false)); //wall tile
    firstRow.push_back(new Tile("???", 160, 0, false, false)); //wall tile
    firstRow.push_back(new Tile("???", 192, 0, false, false)); //wall tile
    firstRow.push_back(new Tile("???", 224, 0, false, false)); //wall tile
    tiles.push_back(firstRow);

    std::vector<Tile *> secondRow;
    firstRow.push_back(new Tile("???", 0, 32, false, false)); //wall tile
    firstRow.push_back(new Tile("???", 32, 32, true, false)); //ground tile
    firstRow.push_back(new Tile("???", 64, 32, true, false)); //ground tile
    firstRow.push_back(new Tile("???", 96, 32, true, false)); //ground tile
    firstRow.push_back(new Tile("???", 128, 32, true, false)); //ground tile
    firstRow.push_back(new Tile("???", 160, 32, true, false)); //ground tile
    firstRow.push_back(new Tile("???", 192, 32, true, false)); //ground tile
    firstRow.push_back(new Tile("???", 224, 32, false, false)); //wall tile
    tiles.push_back(secondRow);

    std::vector<Tile *> thirdRow;
    firstRow.push_back(new Tile("???", 0, 64, false, false)); //wall tile
    firstRow.push_back(new Tile("???", 32, 64, true, false)); //ground tile
    firstRow.push_back(new Tile("???", 64, 64, true, false)); //ground tile
    firstRow.push_back(new Tile("???", 96, 64, true, false)); //ground tile
    firstRow.push_back(new Tile("???", 128, 64, true, false)); //ground tile
    firstRow.push_back(new Tile("???", 160, 64, true, false)); //ground tile
    firstRow.push_back(new Tile("???", 192, 64, true, false)); //ground tile
    firstRow.push_back(new Tile("???", 224, 64, false, false)); //wall tile
    tiles.push_back(thirdRow);

    std::vector<Tile *> fourthRow;
    firstRow.push_back(new Tile("???", 0, 96, false, false)); //wall tile
    firstRow.push_back(new Tile("???", 32, 96, true, false)); //ground tile
    firstRow.push_back(new Tile("???", 64, 96, true, false)); //ground tile
    firstRow.push_back(new Tile("???", 96, 96, true, false)); //ground tile
    firstRow.push_back(new Tile("???", 128, 96, true, false)); //ground tile
    firstRow.push_back(new Tile("???", 160, 96, true, false)); //ground tile
    firstRow.push_back(new Tile("???", 192, 96, true, false)); //ground tile
    firstRow.push_back(new Tile("???", 224, 96, false, false)); //wall tile
    tiles.push_back(fourthRow);

    std::vector<Tile *> fifthRow;
    firstRow.push_back(new Tile("???", 0, 128, false, false)); //wall tile
    firstRow.push_back(new Tile("???", 32, 128, false, false)); //wall tile
    firstRow.push_back(new Tile("???", 64, 128, false, false)); //wall tile
    firstRow.push_back(new Tile("???", 96, 128, false, false)); //wall tile
    firstRow.push_back(new Tile("???", 200, 128, false, false)); //wall tile
    firstRow.push_back(new Tile("???", 160, 128, false, false)); //wall tile
    firstRow.push_back(new Tile("???", 192, 128, false, false)); //wall tile
    firstRow.push_back(new Tile("???", 224, 128, false, false)); //wall tile
    tiles.push_back(fifthRow);
}