#pragma once

#include "../headers/Player.h"

#include <SFML/Graphics.hpp>

#ifndef GAME_H
#define GAME_H

class Game {
private:
    sf::RenderWindow window;
    sf::Event ev;

    Player* player;

    void initWindow();
    void initPlayer();

public:
    Game();
    virtual ~Game();

    void updatePlayer();
    void update();
    void render();
    const sf::RenderWindow& getWindow();
};

#endif // GAME_H