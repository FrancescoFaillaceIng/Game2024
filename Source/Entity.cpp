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

void Entity::setRect(const sf::RectangleShape &rect) {
    Entity::rect = rect;
}

const sf::Texture &Entity::getTexture() const {
    return texture;
}

void Entity::setTexture(const sf::Texture &texture) {
    Entity::texture = texture;
}

void Entity::setSprite(const sf::Sprite &sprite) {
    Entity::sprite = sprite;
}
