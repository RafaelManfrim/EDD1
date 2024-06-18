#include <iostream>

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
}

Game::~Game() {
    delete this->player;
    delete this->util;
//    delete this->tileMap;
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
//    this->updateTileMap();
}

void Game::renderPlayer() {
    this->player->setPosition(this->player->getPosition().x,this->window.getSize().y - this->player->getGlobalBounds().height - 130);
    this->player->render(this->window);
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

    this->window.display();
}

const sf::RenderWindow & Game::getWindow() {
    return this->window;
}
