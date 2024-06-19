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

void Game::initEnemies() {
    // Criar uma lista ligada de inimigos

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

    std::random_device generator;
    std::uniform_int_distribution<int> available_enemies(1, 11);
    std::uniform_int_distribution<int> available_bosses(1, 5);

    for (int i = 1; i <= enemies; i++) {
        int enemy_id_draw = available_enemies(generator);

        // Adicionar cada inimigo ao fim da lista

        std::cout << "Inimigo " << i << ": " << this->getEnemyName(enemy_id_draw) << "\n";
    }

    int boss_id_draw = available_bosses(generator);

    std::cout << "Chefe: " << this->getBossName(boss_id_draw) << "\n";

    // Adicionar o boss ao final da lista

    this->enemy = new Enemy();

}

Game::Game() {
    this->util = new Util();

    this->initWindow();
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

    this->initPlayer();
    this->initEnemies();
}

Game::~Game() {
    delete this->player;
    delete this->util;
//    delete this->tileMap;
}

std::string Game::getEnemyName(int enemy_id) {
    switch (enemy_id) {
        case Enemies::GREEN_SLIME:
            return "Green Slime";
        case Enemies::RED_SLIME:
            return "Red Slime";
        case Enemies::BLUE_SLIME:
            return "Blue Slime";
        case Enemies::CURSED_GREEN_SLIME:
            return "Cursed Green Slime";
        case Enemies::FLYING_DEMON:
            return "Flying Demon";
        case Enemies::FLYING_EYE:
            return "Flying Eye";
        case Enemies::MUSHROOM:
            return "Mushroom";
        case Enemies::CURSED_MUSHROOM:
            return "Cursed Mushroom";
        case Enemies::SKELETON_WARRIOR:
            return "Skeleton Warrior";
        case Enemies::CURSED_SKELETON:
            return "Cursed Skeleton";
        case Enemies::GOBLIN:
            return "Goblin";
        default:
            return "Unknown";
    }
}

std::string Game::getBossName(int boss_id) {
    switch (boss_id) {
        case Bosses::EVIL_WIZARD:
            return "Evil Wizard";
        case Bosses::NECROMANCER:
            return "Necromancer";
        case Bosses::KNIGHT:
            return "Knight";
        case Bosses::NIGHT_BORNE:
            return "Night Borne";
        case Bosses::BRINGER_OF_DEATH:
            return "Bringer of Death";
        default:
            return "Unknown";
    }
}

void Game::updateInput() {
    if (sf::Keyboard::isKeyPressed(this->keyboardMappings["KEY_MOVE_LEFT"])) {
        this->player->move(-1.f);
    } else if (sf::Keyboard::isKeyPressed(this->keyboardMappings["KEY_MOVE_RIGHT"])) {
        this->player->move(1.f);
    }
}

void Game::updatePlayer() {
    this->player->update();
}

void Game::updateEnemies() {
    this->enemy->update();
}

void Game::update() {
    while (this->window.pollEvent(this->ev)) {
        if (this->ev.type == sf::Event::Closed) {
            this->window.close();
        } else if (this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::Escape) {
            this->window.close();
        }
    }

    this->updateInput();
    this->updatePlayer();
    this->updateEnemies();
//    this->updateTileMap();
}

void Game::renderPlayer() {
    this->player->setPosition(this->player->getPosition().x ,this->window.getSize().y - this->player->getGlobalBounds().height - 130);
    this->player->render(this->window);
}

void Game::renderEnemies() {
    this->enemy->setPosition(this->enemy->getPosition().x, this->window.getSize().y - this->enemy->getGlobalBounds().height - 130);
    this->enemy->render(this->window);
}

void Game::render() {
    this->window.clear();

    if (!backgroundTexture.loadFromFile("../assets/sprites/game-background.png")) {
        std::cout << "ERRO::BACKGROUND::Não foi possível carregar o background do game!" << "\n";
    }

    backgroundSprite.setTexture(backgroundTexture);

    this->window.draw(backgroundSprite);

//    this->renderTileMap();
    this->renderPlayer();
    this->renderEnemies();

    this->window.display();
}

const sf::RenderWindow & Game::getWindow() {
    return this->window;
}
