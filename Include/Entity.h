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
    virtual ~Entity() = 0;

    Direction getDirection() const;

    void setDirection(Direction direction);
    void setTexture(const sf::Texture &texture);

    const sf::RectangleShape &getRect() const;

    sf::RectangleShape rect;
protected:
    Direction direction;

    sf::Texture texture;
    sf::Sprite sprite;
};


#endif //GAME_ENTITY_H
