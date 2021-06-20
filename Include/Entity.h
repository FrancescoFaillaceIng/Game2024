//
// Created by Francesco on 18/06/2021.
//

#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include <SFML/Graphics.hpp>

class Entity {
public:
    enum Direction{
        up,
        down,
        left,
        right
    };

    virtual const sf::Sprite &getSprite();
    //virtual ~Entity() = 0;

    sf::RectangleShape rect;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Text text;

    Direction direction;
};


#endif //GAME_ENTITY_H
