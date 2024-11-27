cmake_minimum_required(VERSION 3.24)
project(Game)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.5.1)
FetchContent_MakeAvailable(SFML)

set(CMAKE_CXX_STANDARD 17)

set(Classi Include/Game.h Source/Game.cpp Include/Map/Map.h Source/Map/Map.cpp Include/Map/Tile.h Source/Map/Tile.cpp
        Include/World.h Source/World.cpp Source/Entity.cpp Include/Entity.h Source/Characters/Characters.cpp
        Include/Characters/Characters.h Source/Characters/Hero.cpp Include/Characters/Hero.h Include/ResourceHolder.h
        Include/ResourceIdentifier.h Include/Objects/Object.h Source/Objects/Object.cpp Include/Objects/ObjectFactory.h
        Source/Objects/ObjectFactory.cpp Include/Objects/Weapon.h Source/Objects/Weapon.cpp Include/Objects/StWeapon.h
        Source/Objects/StWeapon.cpp Include/Characters/Enemy.h Source/Characters/Enemy.cpp Source/Characters/MeleeEnemy.cpp
        Include/Characters/MeleeEnemy.h Source/Random.cpp Include/Random.h Source/Characters/CharacterFactory.cpp
        Include/Characters/CharacterFactory.h Source/Inventory.cpp Include/Inventory.h Source/Strategy/Strategy.cpp
        Include/Strategy/Strategy.h Source/Strategy/PatrolStrategy.cpp Include/Strategy/PatrolStrategy.h Source/Strategy/SeekStrategy.cpp
        Include/Strategy/SeekStrategy.h Source/Projectiles/Projectile.cpp Include/Projectiles/Projectile.h
        Source/Projectiles/StProjectile.cpp Include/Projectiles/StProjectile.h Source/Projectiles/ProjectileFactory.cpp
        Include/Projectiles/ProjectileFactory.h Include/Observer/Observer.h Include/Observer/Subject.h Source/Observer/mObserver.cpp
        Include/Observer/mObserver.h Source/Objects/Coins.cpp Include/Objects/Coins.h Source/Objects/Potion.cpp
        Include/Objects/Potion.h Source/LifeBars/LifeBars.cpp Include/LifeBars/LifeBars.h Source/LifeBars/BarsFactory.cpp
        Include/LifeBars/BarsFactory.h)

add_executable(Game main.cpp ${Classi}
        Source/Menus/Game_menu.cpp
        Include/Menus/Game_menu.h
        Include/Menus/Game_menu.h
        Source/Menus/Button.cpp
        Include/Menus/Button.h
        Include/Menus/Button.h
        Source/Menus/PowerupMenu.cpp
        Include/Menus/PowerupMenu.h)

add_library(Game_Tests ${Classi} )

target_link_libraries(Game sfml-graphics sfml-window sfml-system)

include_directories(${SFML_INCLUDE_DIR})
add_subdirectory(Tests)