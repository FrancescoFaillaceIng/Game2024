//
// Created by Francesco on 18/06/2021.
//

#include <memory>
#include "../Include/World.h"

World::World(std::shared_ptr<sf::RenderWindow> window, const TextureHolder &textures): window(window),
    textures(textures), hero(new Hero(Hero::HeroType::StRanged, textures)), stweapon(new StWeapon(textures)){

    createObjects();
}

void World::Update() {
    hero->Update();
}

void World::draw() {
    drawObject();
    drawHero();
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
    else if (key == sf::Keyboard::Space){
        Shoot();
    }
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
                (*iter)->equipped = true;
                iter = collectableObject.erase(iter);
                if (iter == collectableObject.end())
                    break;

            }
        }
    }
}

void World::Shoot() {
    if(hero->Shoot()){
        std::shared_ptr<Weapon> mWeapon = std::dynamic_pointer_cast<Weapon>(hero->weapon);
        //TODO proiettili
    }
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