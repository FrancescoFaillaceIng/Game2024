cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 17)
set(GOOGLETEST_VERSION 1.15.2)

add_subdirectory(googletest/)
set(gtest_DIR googletest)


set(Classi2 ../Include/Game.h ../Source/Game.cpp ../Include/Map/Map.h ../Source/Map/Map.cpp ../Include/Map/Tile.h ../Source/Map/Tile.cpp
        ../Include/World.h ../Source/World.cpp ../Source/Entity.cpp ../Include/Entity.h ../Source/Characters/Characters.cpp
        ../Include/Characters/Characters.h ../Source/Characters/Hero.cpp ../Include/Characters/Hero.h ../Include/ResourceHolder.h
        ../Include/ResourceIdentifier.h ../Include/Objects/Object.h ../Source/Objects/Object.cpp ../Include/Objects/ObjectFactory.h
        ../Source/Objects/ObjectFactory.cpp ../Include/Objects/Weapon.h ../Source/Objects/Weapon.cpp ../Include/Objects/StWeapon.h
        ../Source/Objects/StWeapon.cpp ../Include/Characters/Enemy.h ../Source/Characters/Enemy.cpp ../Source/Characters/MeleeEnemy.cpp
        ../Include/Characters/MeleeEnemy.h ../Source/Random.cpp ../Include/Random.h ../Source/Characters/CharacterFactory.cpp
        ../Include/Characters/CharacterFactory.h ../Source/Inventory.cpp ../Include/Inventory.h ../Source/Strategy/Strategy.cpp
        ../Include/Strategy/Strategy.h ../Source/Strategy/PatrolStrategy.cpp ../Include/Strategy/PatrolStrategy.h ../Source/Strategy/SeekStrategy.cpp
        ../Include/Strategy/SeekStrategy.h ../Source/Projectiles/Projectile.cpp ../Include/Projectiles/Projectile.h
        ../Source/Projectiles/StProjectile.cpp ../Include/Projectiles/StProjectile.h ../Source/Projectiles/ProjectileFactory.cpp
        ../Include/Projectiles/ProjectileFactory.h ../Include/Observer/Observer.h ../Include/Observer/Subject.h ../Source/Observer/mObserver.cpp
        ../Include/Observer/mObserver.h ../Source/Objects/Coins.cpp ../Include/Objects/Coins.h ../Source/Objects/Potion.cpp
        ../Include/Objects/Potion.h ../Source/LifeBars/LifeBars.cpp ../Include/LifeBars/LifeBars.h ../Source/LifeBars/BarsFactory.cpp
        ../Include/LifeBars/BarsFactory.h ../Include/Menus/Button.h ../Source/Menus/Button.cpp ../Include/Menus/Game_menu.h
        ../Source/Menus/Game_menu.cpp ../Include/Menus/PowerupMenu.h ../Source/Menus/PowerupMenu.cpp)

include_directories(${gtest_DIR}/include)
include_directories(${SFML_INCLUDE_DIR})

set(SOURCES_TESTS mainTest.cpp Movements.cpp Collision.cpp)

add_executable(test ${Classi2} ${SOURCES_TESTS})

target_link_libraries(test sfml-graphics sfml-window sfml-system gtest gtest_main gmock )