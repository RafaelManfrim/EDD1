#include <iostream>
#include <random>

#include "../headers/Game.h"
#include "../headers/Menu.h"
#include "../headers/DifficultyMenu.h"
#include "../headers/GenderMenu.h"
#include "../headers/AttributesMenu.h"

void Game::initWindow() {
    this->window.create(sf::VideoMode(1280, 720), "ED - T2", sf::Style::Close | sf::Style::Titlebar);
    this->window.setPosition(sf::Vector2i(100,100));
    this->window.setFramerateLimit(144);
}

void Game::initInput() {
    this->keyboardMappings["KEY_MOVE_LEFT"] = sf::Keyboard::Key::A;
    this->keyboardMappings["KEY_MOVE_RIGHT"] = sf::Keyboard::Key::D;
}

void Game::initPlayer() {
    this->player = new Player(this->gender);
}

void Game::initCamera() {
    this->camera = sf::View(sf::FloatRect(0, 0, 1280, 720));
}

void Game::initEnemies() {
    int enemies = 0;

    switch (this->difficulty) {
        case Difficulty::EASY:
            enemies = 5;
            break;
        case Difficulty::MEDIUM:
            enemies = 7;
            break;
        case Difficulty::HARD:
            enemies = 9;
            break;
    }

    this->enemyQueue = new EnemyQueue(enemies);
}

Game::Game() {
    this->util = new Util();

    this->initWindow();
    this->initCamera();
    this->initInput();

    Menu * menu = new Menu(this->window, this->util);
    menu->run_menu();
    delete menu;
    menu = nullptr;

    this->difficulty = 1;

    auto * difficultyMenu = new DifficultyMenu(this->window, this->util, this->difficulty);
    difficultyMenu->run_menu();
    delete difficultyMenu;
    difficultyMenu = nullptr;

    this->getMapSizeByDifficulty(this->difficulty);

    auto * genderMenu = new GenderMenu(this->window, this->util, this->gender);
    genderMenu->run_menu();
    delete genderMenu;
    genderMenu = nullptr;

    this->life = 0;
    this->attack = 0;
    this->defense = 0;
    this->luck = 0;

    auto * attributesMenu = new AttributesMenu(this->window, this->util, this->life, this->attack, this->defense, this->luck);
    attributesMenu->run_menu();
    delete attributesMenu;
    attributesMenu = nullptr;

    this->movementDisabled = false;

    this->initPlayer();
    this->initEnemies();
}

Game::~Game() {
    delete this->player;
    delete this->util;
//    delete this->tileMap;
    delete this->enemyQueue;
}

void Game::getMapSizeByDifficulty(int difficulty_id) {
    switch (difficulty_id) {
        case Difficulty::EASY:
            this->map_size = 6 * 1800;
            break;
        case Difficulty::MEDIUM:
            this->map_size = 8 * 1800;
            break;
        case Difficulty::HARD:
        default:
            this->map_size = 10 * 1800;
            break;
    }
}

void Game::updateInput() {
    if(this->movementDisabled) {
       return;
    }

    if (sf::Keyboard::isKeyPressed(this->keyboardMappings["KEY_MOVE_LEFT"])) {
        this->player->move(-1.f);
    } else if (sf::Keyboard::isKeyPressed(this->keyboardMappings["KEY_MOVE_RIGHT"])) {
        this->player->move(1.f);
    }
}

void Game::updatePlayer() {
    this->player->update();

    sf::Vector2f playerPosition = this->player->getPosition();
    sf::Vector2f cameraCenter = this->camera.getCenter();
    sf::Vector2f cameraSize = camera.getSize();

    float borderLeftOfCamera = cameraCenter.x - cameraSize.x / 2 + 256.f;
    float borderRightOfCamera = cameraCenter.x + cameraSize.x - 256.f;

    if (playerPosition.x < borderLeftOfCamera) {
        this->player->setPosition(borderLeftOfCamera, playerPosition.y);
    } else if (playerPosition.x + this->player->getGlobalBounds().width > borderRightOfCamera) {
        this->player->setPosition(borderRightOfCamera - this->player->getGlobalBounds().width, playerPosition.y);
    }
}


void Game::updateCamera() {
    sf::Vector2f playerPosition = this->player->getPosition();
    sf::Vector2f cameraCenter = this->camera.getCenter();

    if (playerPosition.x - cameraCenter.x > -320) {
        this->camera.setCenter(playerPosition.x + 320, cameraCenter.y);
    }

    if (this->camera.getCenter().x > float (this->map_size) - 640) {
        this->camera.setCenter(float (this->map_size - 640), this->camera.getCenter().y);
    }
}

void Game::updateEnemies() {
    std::vector<Enemy*> enemies = this->enemyQueue->getEnemies();

    for (auto* enemy : enemies) {
        enemy->update();
    }
//    if (!this->enemyQueue->isEmpty()) {
//        Enemy* currentEnemy = this->enemyQueue->pop();
//        currentEnemy->update();
//
////        if (currentEnemy->isDead()) {
////            delete currentEnemy;
////        } else {
////            this->enemyQueue->push(currentEnemy);
////        }
//    }
}

void Game::update() {
    while (this->window.pollEvent(this->ev)) {
        if (this->ev.type == sf::Event::Closed) {
            this->window.close();
        } else if (this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::Escape) {
            this->window.close();
        }
    }

    this->updateCamera();
    this->updateInput();
    this->updatePlayer();
    this->updateEnemies();

//    this->updateTileMap();
}

void Game::renderBackground() {
    if (!backgroundTexture.loadFromFile("../assets/sprites/game-background.png")) {
        std::cout << "ERRO::BACKGROUND::Não foi possível carregar o background do game!" << "\n";
    }

    backgroundSprite.setTexture(backgroundTexture);

    float backgroundWidth = float (backgroundTexture.getSize().x);
    int horizontalTiles = static_cast<int>(std::ceil(float (map_size) / backgroundWidth)) + 1;

    for (int i = 0; i < horizontalTiles; ++i) {
        backgroundSprite.setPosition(float (i) * backgroundWidth, 0);
        this->window.draw(backgroundSprite);
    }
}

void Game::renderPlayer() {
    this->player->render(this->window);
}

void Game::renderEnemies() {
    std::vector<Enemy*> enemies = this->enemyQueue->getEnemies();

    for (auto* enemy : enemies) {
        enemy->render(this->window);
    }
//    std::queue<Enemy*> tempQueue = this->enemyQueue->getQueue();
//
//    while (!tempQueue.empty()) {
//        Enemy* currentEnemy = tempQueue.front();
//        currentEnemy->render(this->window);
//        tempQueue.pop();
//    }
}

void Game::render() {
    this->window.clear();

    this->window.setView(this->camera);

    this->renderBackground();

//    this->renderTileMap();
    this->renderPlayer();
    this->renderEnemies();

    this->window.display();
}

const sf::RenderWindow & Game::getWindow() {
    return this->window;
}
