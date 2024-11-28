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
    void Update(sf::Clock &damageClock, sf::Clock &menuClock);
    void LifeBarUpdate();
    void UpdateSpeedText();
    void UpdateAttackDamageText();
    void UpdateCoinsText();
    void UpdateGameOverText();
    void loadTextures();

    sf::Font font;
    sf::Text speedText;
    sf::Text attackDamageText;
    sf::Text coinsText;
    sf::Text gameOverText;

    sf::RectangleShape speedTextBackground;
    sf::RectangleShape attackDamageTextBackground;
    sf::RectangleShape coinsTextBackground;
    sf::RectangleShape gameOverTextBackground;

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
    bool isGameOver;

};
#endif //GAME_GAME_H
