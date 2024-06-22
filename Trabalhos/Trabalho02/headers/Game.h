#pragma once

#include "../headers/Player.h"
#include "../headers/Enemy.h"
#include "../headers/Util.h"
#include "../headers/EnemyQueue.h"

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
    sf::View camera;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    Player* player;
    std::map<std::string, sf::Keyboard::Key> keyboardMappings;

    void initWindow();
    void initInput();
    void initPlayer();
    void initCamera();
    void initEnemies();

public:
    Game();
    virtual ~Game();

    Util* util;

    int difficulty;
    int gender, life, attack, defense, luck;
    int map_size;

    bool movementDisabled;

    EnemyQueue* enemyQueue;

    void getMapSizeByDifficulty(int difficulty_id);

    float calculateDistance(const sf::Vector2f& point1, const sf::Vector2f& point2) const;

    void updateInput();
    void updatePlayer();
    void updateEnemies();
    void updateCamera();
    void update();

    void renderBackground();
    void renderPlayer();
    void renderEnemies();
    void render();

    const sf::RenderWindow& getWindow();
};
