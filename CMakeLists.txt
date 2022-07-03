cmake_minimum_required(VERSION 3.19)
project(Game)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Tests)

set(Classi Include/Game.h Source/Game.cpp Include/Map/Map.h Source/Map/Map.cpp Include/Map/Tile.h Source/Map/Tile.cpp
        Include/World.h Source/World.cpp Source/Entity.cpp Include/Entity.h Source/Characters/Characters.cpp
        Include/Characters/Characters.h Source/Characters/Hero.cpp Include/Characters/Hero.h Include/ResourceHolder.h
        Include/ResourceIdentifier.h Include/Objects/Object.h Source/Objects/Object.cpp Include/Objects/ObjectFactory.h
        Source/Objects/ObjectFactory.cpp Include/Objects/Weapon.h Source/Objects/Weapon.cpp Include/Objects/StWeapon.h
        Source/Objects/StWeapon.cpp)

add_executable(Game main.cpp ${Classi} Include/Characters/Enemy.h Source/Characters/Enemy.cpp Source/Characters/MeleeEnemy.cpp
        Include/Characters/MeleeEnemy.h Source/Random.cpp Include/Random.h Source/Characters/CharacterFactory.cpp
        Include/Characters/CharacterFactory.h Source/Inventory.cpp Include/Inventory.h Source/Strategy/Strategy.cpp
        Include/Strategy/Strategy.h Source/Strategy/PatrolStrategy.cpp Include/Strategy/PatrolStrategy.h Source/Strategy/SeekStrategy.cpp
        Include/Strategy/SeekStrategy.h Source/Projectiles/Projectile.cpp Include/Projectiles/Projectile.h
        Source/Projectiles/StProjectile.cpp Include/Projectiles/StProjectile.h Source/Projectiles/ProjectileFactory.cpp
        Include/Projectiles/ProjectileFactory.h)

add_library(Game_Tests ${Classi})

find_package(SFML 2 COMPONENTS network audio graphics window system REQUIRED)

target_link_libraries(Game sfml-graphics sfml-window sfml-system)