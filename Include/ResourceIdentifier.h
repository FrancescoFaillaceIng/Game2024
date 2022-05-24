//
// Created by Francesco on 20/06/2021.
//

#ifndef GAME_RESOURCEIDENTIFIER_H
#define GAME_RESOURCEIDENTIFIER_H


// Forward declaration of SFML classes
namespace sf {
    class Texture;
}

namespace Textures {
    enum ID {
        MeleeHero,
        StHero,
        AoeHero,

        fighter,
        shooter,

        StWeapon,

        StProjectile,
        AoeProjectile,

        WallText,
        FloorText,
    };
}

// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

//It will be called a lot
typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;



#endif //GAME_RESOURCEIDENTIFIER_H
