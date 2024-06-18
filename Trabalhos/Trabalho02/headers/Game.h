#pragma once

#include "../headers/Player.h"
#include "../headers/Util.h"

#include <SFML/Graphics.hpp>

enum Difficulty {
    EASY = 1,
    MEDIUM = 2,
    HARD = 3
};

enum PlayerGender {
    MASCULINO = 1,
    FEMININO = 2
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

    Util* util;

    int difficulty;
    int gender, life, attack, defense, luck;

    void updateInput();
    void updatePlayer();
    void update();

    void renderPlayer();
    void render();

    const sf::RenderWindow& getWindow();
};
