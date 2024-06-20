#include <iostream>

#include "../headers/Enemy.h"

void Enemy::initVariables() {
    this->animState = ENEMY_ANIMATION_STATES::ENEMY_IDLE;
}

void Enemy::initTexture() {
    // Carregar a textura do inimigo de acordo com seu id (possivelmente terá uma função para isso)

    std::string path = "../assets/sprites/enemies/goblin/goblin-2.png";

    if (!this->textureSheet.loadFromFile(path)) {
        std::cout << "ERRO::ENEMY::Não foi possível carregar a textura do inimigo!" << "\n";
    }
}

void Enemy::initSprite() {
    // Teremos que verificar o tamanho do sprite de cada inimigo

    this->sprite.setTexture(this->textureSheet);
    this->currentFrame = sf::IntRect(0, 0, 150, 101);

    this->sprite.setTextureRect(this->currentFrame);
    this->sprite.setScale(-4.f, 4.f);

    this->sprite.setPosition(this->sprite.getPosition().x + 1000, 720 - this->getGlobalBounds().height - 131);
}

void Enemy::initAnimations() {
    this->animationTimer.restart();
    this->animationSwitch = true;
    this->currentFrame.left = 0.f;
}

void Enemy::initPhysics() {
    this->velocityMax = 2.f;
    this->velocityMin = 1.0f;
    this->acceleration = 2.0f;
    this->drag = 0.70f;
}

Enemy::Enemy() {
    this->initVariables();
    this->initTexture();
    this->initSprite();
    this->initAnimations();
    this->initPhysics();
}

Enemy::~Enemy() {

}

bool Enemy::getAnimSwitch() {
    bool anim_switch = this->animationSwitch;

    if (this->animationSwitch)
        this->animationSwitch = false;

    return anim_switch;
}

const sf::Vector2f Enemy::getPosition() const {
    return this->sprite.getPosition();
}

const sf::FloatRect Enemy::getGlobalBounds() const {
    return this->sprite.getGlobalBounds();
}

void Enemy::setPosition(const float x, const float y) {
    this->sprite.setPosition(x, y);
}

void Enemy::resetAnimationTimer() {
    this->animationTimer.restart();
    this->animationSwitch = true;
}

void Enemy::move(const float dir_x) {
    this->velocity.x += dir_x * this->acceleration;

    if (std::abs(this->velocity.x) > this->velocityMax) {
        this->velocity.x = this->velocityMax * ((this->velocity.x < 0.f) ? -1.f : 1.f);
    }
}

void Enemy::updatePhysics() {
    this->velocity *= this->drag;

    if (std::abs(this->velocity.x) < this->velocityMin)
        this->velocity.x = 0.f;

    if(std::abs(this->velocity.x) <= 1.f)
        this->velocity.x = 0.f;

    this->sprite.move(this->velocity);
}

void Enemy::updateMovement() {
    this->animState = ENEMY_ANIMATION_STATES::ENEMY_IDLE;
}

void Enemy::updateAnimations() {
    if (this->animState == ENEMY_ANIMATION_STATES::ENEMY_IDLE) {
        if (this->animationTimer.getElapsedTime().asMilliseconds() >= 320.f || this->getAnimSwitch()) {
            this->currentFrame.top = 0.f;
            this->currentFrame.left += 150.f;
            if (this->currentFrame.left > 450.f)
                this->currentFrame.left = 0;

            this->animationTimer.restart();
            this->sprite.setTextureRect(this->currentFrame);
        }

    } else {
        this->animationTimer.restart();
    }
}

void Enemy::update() {
    this->updateMovement();
    this->updateAnimations();
    this->updatePhysics();
}

void Enemy::render(sf::RenderTarget & target) {
    target.draw(this->sprite);

//    sf::CircleShape circ;
//    circ.setFillColor(sf::Color::Red);
//    circ.setRadius(2.f);
//    circ.setPosition(this->sprite.getPosition());
//
//    target.draw(circ);
}