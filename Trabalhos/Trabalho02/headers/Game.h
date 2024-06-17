#pragma once

#include "../headers/Player.h"

#include <SFML/Graphics.hpp>

enum Difficulty {
    EASY = 1,
    MEDIUM = 2,
    HARD = 3
};

class Game {

private:
    sf::RenderWindow window;
    sf::Event ev;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    Player* player;
    std::map<std::string, sf::Keyboard::Key> keyboardMappings;

    void initWindow();
    void initInput();
    void initPlayer();

public:
    Game();
    virtual ~Game();

    int difficulty;

    void updateInput();
    void updatePlayer();
    void update();

    void renderPlayer();
    void render();

    const sf::RenderWindow& getWindow();
};
