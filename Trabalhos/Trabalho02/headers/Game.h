#pragma once

#include "../headers/Player.h"
#include "../headers/Enemy.h"
#include "../headers/Util.h"
#include "../headers/EnemyQueue.h"
#include "./Fight.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

enum class GameState {
    PLAYING,
    VICTORY,
    DEFEAT
};

enum Difficulty {
    EASY = 1,
    MEDIUM = 2,
    HARD = 3
};

class Game {

private:
    GameState gameState;
    sf::Music music;

    sf::RenderWindow window;
    sf::Event ev;
    sf::View camera;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    Player* player;
    Fight* fight;

    std::map<std::string, sf::Keyboard::Key> keyboardMappings;

    void initWindow();
    void initInput();
    void initPlayer();
    void initCamera();
    void initEnemies();

//    void startFight(Enemy* enemy);

public:
    Game();
    virtual ~Game();

    Util* util;

    int difficulty;
    int gender, player_life, player_attack, player_defense, player_luck;
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

    void resetCamera();

    void renderBackground();
    void renderPlayer();
    void renderEnemies();

    void renderVictory();
    void renderDefeat();

    void render();

    const sf::RenderWindow& getWindow();
};
