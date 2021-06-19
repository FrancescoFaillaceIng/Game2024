cmake_minimum_required(VERSION 3.19)
project(Game)

set(CMAKE_CXX_STANDARD 14)

add_executable(Game main.cpp Include/Game.h Source/Game.cpp Include/Map/Map.h Source/Map/Map.cpp Include/Map/Tile.h Source/Map/Tile.cpp Include/World.h Source/World.cpp Source/Entity.cpp Include/Entity.h Source/Characters/Characters.cpp Include/Characters/Characters.h Source/Characters/Hero.cpp Include/Characters/Hero.h Include/Textures/ResourceHolder.h Include/Textures/ResourceIdentifier.h)

find_package(SFML 2 COMPONENTS network audio graphics window system REQUIRED)

target_link_libraries(Game sfml-graphics sfml-window sfml-system)