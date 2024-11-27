//
// Created by erosp on 16/06/2021.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <memory>
#include "LifeBars/BarsFactory.h"
#include "World.h"
#include "Menus/Game_menu.h"
#include "Menus/PowerupMenu.h"

class Game {
public:
    Game();
    void play();

private:
    void render();
    void processEvents(sf::Clock &shootingClock);
    void Update(sf::Clock &damageClock);
    void LifeBarUpdate();
    void loadTextures();


    TextureHolder textureHolder;

    std::shared_ptr<Game_menu> game_menu;
    std::shared_ptr<PowerupMenu> powerupMenu;

    std::shared_ptr<sf::RenderWindow> mWindow;
    std::shared_ptr<World> world;
    std::shared_ptr<sf::View> view;
    std::shared_ptr<Map> map;
    std::shared_ptr<LifeBars> hero_lifebar;

    BarsFactory barsFactory;

    static const sf::Time TimePerFrame;

    bool isPowerUpMenuActive;

};
#endif //GAME_GAME_H
