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

enum Enemies {
    GREEN_SLIME = 1,
    RED_SLIME = 2,
    BLUE_SLIME = 3,
    CURSED_GREEN_SLIME = 4,
    FLYING_DEMON = 5,
    FLYING_EYE = 6,
    MUSHROOM =  7,
    CURSED_MUSHROOM = 8,
    SKELETON_WARRIOR = 9,
    CURSED_SKELETON = 10,
    GOBLIN = 12,
};

enum Bosses {
    EVIL_WIZARD = 1,
    NECROMANCER = 2,
    KNIGHT = 3,
    NIGHT_BORNE = 4,
    BRINGER_OF_DEATH = 5
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
