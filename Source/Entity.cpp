//
// Created by Francesco on 18/06/2021.
//

#include "../Include/Entity.h"

const sf::Sprite &Entity::getSprite() {
    return sprite;
}

Entity::~Entity() {}

Entity::Direction Entity::getDirection() const {
    return direction;
}

void Entity::setDirection(Entity::Direction direction) {
    Entity::direction = direction;
}

const sf::RectangleShape &Entity::getRect() const {
    return rect;
}

void Entity::setTexture(const sf::Texture &texture) {
    Entity::texture = texture;
}

