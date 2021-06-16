//
// Created by erosp on 16/06/2021.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <memory>
#include <SFML/Graphics.hpp>

class Game {
public:
    Game();
    void play();

private:
    void render();
    void processEvents();

    std::shared_ptr<sf::RenderWindow> Window;
};
#endif //GAME_GAME_H
