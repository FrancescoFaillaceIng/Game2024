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

    const sf::Sprite &getSprite();
    virtual ~Entity() = 0;

    Direction getDirection() const;

    void setDirection(Direction direction);
    void setRect(const sf::RectangleShape &rect);
    void setTexture(const sf::Texture &texture);
    void setSprite(const sf::Sprite &sprite);

    const sf::RectangleShape &getRect() const;
    const sf::Texture &getTexture() const;

protected:
    Direction direction;

    sf::RectangleShape rect;
    sf::Texture texture;
    sf::Sprite sprite;
};


#endif //GAME_ENTITY_H
