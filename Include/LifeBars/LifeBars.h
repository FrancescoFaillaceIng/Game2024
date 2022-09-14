//
// Created by Francesco on 21/07/2022.
//

#ifndef GAME_LIFEBARS_H
#define GAME_LIFEBARS_H

#include <SFML/Graphics.hpp>

#include "../ResourceHolder.h"
#include "../ResourceIdentifier.h"

class LifeBars {
public:
    LifeBars(float x, float y, const TextureHolder &textures);

    const sf::Sprite &getSprite() const;

    void update(float x, float y, int herolife);

    sf::RectangleShape rect;
    sf::Texture texture;

    const TextureHolder &textures;

protected:
    sf::Sprite sprite;


};


#endif //GAME_LIFEBARS_H
