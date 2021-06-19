//
// Created by Francesco on 18/06/2021.
//

#include "../Include/World.h"

World::World() {
    gridLength = 8;
    setUpInitialState();
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

void World::setUpTiles() {
    tiles.clear();
    std::vector<Tile *> firstRow;
    firstRow.push_back(new Tile("Resources/single_door.png", 0, 0, false, false)); //wall tile
    firstRow.push_back(new Tile("Resources/single_door.png", 50, 0, true, true)); //exit tile
    firstRow.push_back(new Tile("Resources/single_door.png", 100, 0, false, false)); //wall tile
    firstRow.push_back(new Tile("Resources/single_door.png", 150, 0, false, false)); //wall tile
    firstRow.push_back(new Tile("Resources/single_door.png", 200, 0, false, false)); //wall tile
    firstRow.push_back(new Tile("Resources/single_door.png", 250, 0, false, false)); //wall tile
    firstRow.push_back(new Tile("Resources/single_door.png", 300, 0, false, false)); //wall tile
    firstRow.push_back(new Tile("Resources/single_door.png", 350, 0, false, false)); //wall tile
    tiles.push_back(firstRow);

    std::vector<Tile *> secondRow;
    firstRow.push_back(new Tile("Resources/single_door.png", 0, 50, false, false)); //wall tile
    firstRow.push_back(new Tile("Resources/single_door.png", 50, 50, true, false)); //ground tile
    firstRow.push_back(new Tile("Resources/single_door.png", 100, 50, true, false)); //ground tile
    firstRow.push_back(new Tile("Resources/single_door.png", 150, 50, true, false)); //ground tile
    firstRow.push_back(new Tile("Resources/single_door.png", 200, 50, true, false)); //ground tile
    firstRow.push_back(new Tile("Resources/single_door.png", 250, 50, true, false)); //ground tile
    firstRow.push_back(new Tile("Resources/single_door.png", 300, 50, true, false)); //ground tile
    firstRow.push_back(new Tile("Resources/single_door.png", 350, 50, false, false)); //wall tile
    tiles.push_back(secondRow);

    std::vector<Tile *> thirdRow;
    firstRow.push_back(new Tile("Resources/single_door.png", 0, 100, false, false)); //wall tile
    firstRow.push_back(new Tile("Resources/single_door.png", 50, 100, true, false)); //ground tile
    firstRow.push_back(new Tile("Resources/single_door.png", 100, 100, true, false)); //ground tile
    firstRow.push_back(new Tile("Resources/single_door.png", 150, 100, true, false)); //ground tile
    firstRow.push_back(new Tile("Resources/single_door.png", 200, 100, true, false)); //ground tile
    firstRow.push_back(new Tile("Resources/single_door.png", 250, 100, true, false)); //ground tile
    firstRow.push_back(new Tile("Resources/single_door.png", 300, 100, true, false)); //ground tile
    firstRow.push_back(new Tile("Resources/single_door.png", 350, 100, false, false)); //wall tile
    tiles.push_back(thirdRow);

    std::vector<Tile *> fourthRow;
    firstRow.push_back(new Tile("Resources/single_door.png", 0, 150, false, false)); //wall tile
    firstRow.push_back(new Tile("Resources/single_door.png", 50, 150, true, false)); //ground tile
    firstRow.push_back(new Tile("Resources/single_door.png", 100, 150, true, false)); //ground tile
    firstRow.push_back(new Tile("Resources/single_door.png", 150, 150, true, false)); //ground tile
    firstRow.push_back(new Tile("Resources/single_door.png", 200, 150, true, false)); //ground tile
    firstRow.push_back(new Tile("Resources/single_door.png", 250, 150, true, false)); //ground tile
    firstRow.push_back(new Tile("Resources/single_door.png", 300, 150, true, false)); //ground tile
    firstRow.push_back(new Tile("Resources/single_door.png", 350, 150, false, false)); //wall tile
    tiles.push_back(fourthRow);

    std::vector<Tile *> fifthRow;
    firstRow.push_back(new Tile("Resources/single_door.png", 0, 200, false, false)); //wall tile
    firstRow.push_back(new Tile("Resources/single_door.png", 50, 200, false, false)); //wall tile
    firstRow.push_back(new Tile("Resources/single_door.png", 100, 200, false, false)); //wall tile
    firstRow.push_back(new Tile("Resources/single_door.png", 150, 200, false, false)); //wall tile
    firstRow.push_back(new Tile("Resources/single_door.png", 200, 200, false, false)); //wall tile
    firstRow.push_back(new Tile("Resources/single_door.png", 250, 200, false, false)); //wall tile
    firstRow.push_back(new Tile("Resources/single_door.png", 300, 200, false, false)); //wall tile
    firstRow.push_back(new Tile("Resources/single_door.png", 350, 200, false, false)); //wall tile
    tiles.push_back(fifthRow);
}