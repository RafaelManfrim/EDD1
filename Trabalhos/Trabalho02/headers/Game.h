#pragma once

#include "../headers/Player.h"
#include "../headers/Enemy.h"
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

enum Bosses {
    EVIL_WIZARD = 1, // OK, evil_wizard.png (2000x128 - 8 img) rotacionar
    NECROMANCER = 2, // OK, necromancer.png (1280x64 - 8 img) rotacionar
    KNIGHT = 3, // OK, knight.png (800x85 - 8 img) rotacionar
    NIGHT_BORNE = 4, // OK, night_borne.png (720x64 - 9 img) rotacionar
    BRINGER_OF_DEATH = 5 // OK, bringer_of_death.png (1120x64 - 8 img)
};

class Game {

private:
    sf::RenderWindow window;
    sf::Event ev;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    Player* player;
    std::map<std::string, sf::Keyboard::Key> keyboardMappings;

    Enemy* enemy;

    void initWindow();
    void initInput();
    void initPlayer();
    void initEnemies();

public:
    Game();
    virtual ~Game();

    Util* util;

    int difficulty;
    int gender, life, attack, defense, luck;

    std::string getBossName(int boss_id);

    void updateInput();
    void updatePlayer();
    void updateEnemies();
    void update();

    void renderPlayer();
    void renderEnemies();
    void render();

    const sf::RenderWindow& getWindow();
};
