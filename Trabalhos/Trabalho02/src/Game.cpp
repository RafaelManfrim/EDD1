#include "../headers/Game.h"

void Game::initWindow() {
    this->window.create(sf::VideoMode(1280, 720), "ED - T2", sf::Style::Close | sf::Style::Titlebar);
}

void Game::initPlayer()
{
    this->player = new Player();
}

Game::Game() {
    this->initWindow();
    this->initPlayer();
}

Game::~Game() {
    delete this->player;
//    delete this->tileMap;
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

//    this->updateInput();

    this->updatePlayer();

//    this->updateCollision();

//    this->updateTileMap();
}

void Game::render() {
    this->window.clear();

//    this->renderTileMap();
//    this->renderPlayer();

    this->window.display();
}

const sf::RenderWindow & Game::getWindow() {
    return this->window;
}