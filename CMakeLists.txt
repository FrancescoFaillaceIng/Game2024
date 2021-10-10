cmake_minimum_required(VERSION 3.19)
project(Game)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Tests)

set(Classi Include/Game.h Source/Game.cpp Include/Map/Map.h Source/Map/Map.cpp Include/Map/Tile.h Source/Map/Tile.cpp
        Include/World.h Source/World.cpp Source/Entity.cpp Include/Entity.h Source/Characters/Characters.cpp
        Include/Characters/Characters.h Source/Characters/Hero.cpp Include/Characters/Hero.h Include/ResourceHolder.h
        Include/ResourceIdentifier.h Include/Objects/Object.h Source/Objects/Object.cpp Include/Objects/Weapon.h
        Source/Objects/Weapon.cpp Include/Objects/StWeapon.h Source/Objects/StWeapon.cpp
        Source/Objects/ObjectFactory.cpp Include/Objects/ObjectFactory.h)

add_executable(Game main.cpp ${Classi})

add_library(Game_Tests ${Classi})

find_package(SFML 2 COMPONENTS network audio graphics window system REQUIRED)

target_link_libraries(Game sfml-graphics sfml-window sfml-system)