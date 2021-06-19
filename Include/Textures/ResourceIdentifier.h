//
// Created by Francesco on 19/06/2021.
//

#ifndef GAME_RESOURCEIDENTIFIER_H
#define GAME_RESOURCEIDENTIFIER_H


namespace sf {
    class Texture;
}

namespace Textures {
    enum ID {
        //hero
        stHero,
        aoeHero,
    };
}

// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

//It will be called a lot
typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;

#endif //GAME_RESOURCEIDENTIFIER_H
