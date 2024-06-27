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
    this->player = new Player(this->gender, this->player_life, this->player_attack, this->player_defense, this->player_luck);
}

void Game::initCamera() {
    this->camera = sf::View(sf::FloatRect(0, 0, 1280, 720));
}

void Game::initEnemies() {
    this->enemyQueue = new EnemyQueue(this->difficulty);
}

Game::Game() {
    this->gameState = GameState::PLAYING;

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

    this->player_life = 0;
    this->player_attack = 0;
    this->player_defense = 0;
    this->player_luck = 0;

    auto * attributesMenu = new AttributesMenu(
            this->window,
            this->util,
            this->player_life,
            this->player_attack,
            this->player_defense,
            this->player_luck
            );

    attributesMenu->run_menu();
    delete attributesMenu;
    attributesMenu = nullptr;

    this->movementDisabled = false;

    this->initPlayer();
    this->initEnemies();

    if (!this->music.openFromFile("../assets/music/music.ogg")) {
        std::cout << "ERRO:MUSIC::Não foi possível carregar a música do game!" << "\n";
    }

    this->music.setLoop(true);
    this->music.play();

    this->fight = nullptr;

    this->waitingForItemSelection = false;
    this->selectedItemIndex = -1;
}

Game::~Game() {
    delete this->player;
    delete this->util;
//    delete this->tileMap;
    delete this->enemyQueue;
    delete this->fight;
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

float Game::calculateDistance(const sf::Vector2f& point1, const sf::Vector2f& point2) const {
    return std::abs(point1.x - point2.x);
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
    if (this->gameState != GameState::PLAYING) {
        return;
    }

    std::vector<Enemy*> enemies = this->enemyQueue->getEnemies();

    if (!enemies.empty()) {
        enemies.front()->update();

        float distance = calculateDistance(this->player->getCenter(), enemies.front()->getCenter());

        if(distance <= 950) {
            this->movementDisabled = true;

            if (this->fight == nullptr) {
                if (!this->player->inventoryIsEmpty() && !this->waitingForItemSelection && this->selectedItemIndex == -1) {
                    std::cout << "Seu inventário: " << std::endl;
                    this->player->displayInventory();
                    std::cout << "Informe o número do item que você deseja usar nessa luta: ";
                    this->waitingForItemSelection = true;
                }

                if(!this->waitingForItemSelection) {
                    this->fight = new Fight(*this->player, *enemies.front());

                    if (this->fight->getWinner() == 1) {
                        if(enemies.front()->getEnemyType() == EnemyType::BOSS) {
                            std::cout << "Você venceu o jogo!" << std::endl;
                            this->gameState = GameState::VICTORY;

                            this->music.stop();

                            if (!this->music.openFromFile("../assets/music/victory.ogg")) {
                                std::cout << "ERRO:MUSIC::Não foi possível carregar a música de vitória!" << "\n";
                            }

                            this->music.play();

                            return;
                        }

                        std::random_device generator;
                        std::uniform_int_distribution<int> drop_item_possibility(0,1);

                        if(drop_item_possibility(generator) == 1) {
                            std::cout << "Você ganhou um item!" << std::endl;

                            std::uniform_int_distribution<int> item_possibility(1,4);
                            int item_type = item_possibility(generator);

                            std::uniform_int_distribution<int> item_duration(1,3);
                            int duration = item_duration(generator);

                            this->player->addItemToInventory(item_type, 1, duration);
                        }

                        this->selectedItemIndex = -1;
                        this->movementDisabled = false;
                        this->enemyQueue->pop();

                        delete this->fight;
                        this->fight = nullptr;
                    } else {
                        std::cout << "Você perdeu!" << std::endl;
                        this->gameState = GameState::DEFEAT;

                        this->music.stop();

                        if (!this->music.openFromFile("../assets/music/defeat.ogg")) {
                            std::cout << "ERRO:MUSIC::Não foi possível carregar a música de derrota!" << "\n";
                        }

                        this->music.play();

                        delete this->fight;
                        this->fight = nullptr;
                    }
                }
            }
        }
    }
}

void Game::update() {
    while (this->window.pollEvent(this->ev)) {
        if (this->ev.type == sf::Event::Closed) {
            this->window.close();
        } else if (this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::Escape) {
            this->window.close();
        } else if (
                this->waitingForItemSelection &&
                (this->ev.key.code == sf::Keyboard::Num1 ||
                this->ev.key.code == sf::Keyboard::Num2 ||
                this->ev.key.code == sf::Keyboard::Num3 ||
                this->ev.key.code == sf::Keyboard::Num4 ||
                this->ev.key.code == sf::Keyboard::Num5 ||
                this->ev.key.code == sf::Keyboard::Num6 ||
                this->ev.key.code == sf::Keyboard::Num7 ||
                this->ev.key.code == sf::Keyboard::Num8 ||
                this->ev.key.code == sf::Keyboard::Num9)
                ) {
            selectedItemIndex = this->ev.key.code - 26;
            if(selectedItemIndex > this->player->getInventorySize()) {
                selectedItemIndex = -1;
                return;
            }
            this->player->useItem(selectedItemIndex);
            this->waitingForItemSelection = false;
        }
    }

    this->updateCamera();
    this->updateInput();
    this->updatePlayer();
    this->updateEnemies();
}

void Game::resetCamera() {
    this->camera.setCenter(640, 360);
    this->window.setView(this->camera);
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
}

void Game::renderVictory() {
    this->resetCamera();

    backgroundTexture = sf::Texture();

    if (!backgroundTexture.loadFromFile("../assets/sprites/victory-background.jpeg")) {
        std::cout << "ERRO::BACKGROUND::Não foi possível carregar a imagem de vitória!" << "\n";
    }

    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0, 0);

    this->window.draw(backgroundSprite);
}

void Game::renderDefeat() {
    this->resetCamera();

    backgroundTexture = sf::Texture();

    if (!backgroundTexture.loadFromFile("../assets/sprites/defeat-background.jpeg")) {
        std::cout << "ERRO::BACKGROUND::Não foi possível carregar a imagem de derrota!" << "\n";
    }

    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0, 0);

    this->window.draw(backgroundSprite);
}

void Game::render() {
    this->window.clear();

    if (this->gameState == GameState::PLAYING) {
        this->window.setView(this->camera);
        this->renderBackground();
        this->renderPlayer();
        this->renderEnemies();
    } else if (this->gameState == GameState::VICTORY) {
        this->renderVictory();
    } else if (this->gameState == GameState::DEFEAT) {
        this->renderDefeat();
    }

    this->window.display();
}

const sf::RenderWindow & Game::getWindow() {
    return this->window;
}
