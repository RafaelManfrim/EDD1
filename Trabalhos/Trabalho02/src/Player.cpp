#include <iostream>

#include "../headers/Player.h"

void Player::initVariables() {
    this->animState = PLAYER_ANIMATION_STATES::IDLE;
}

void Player::initTexture() {
    std::string path = this->gender == PlayerGender::MASCULINO ? "../assets/sprites/player/man.png" : "../assets/sprites/player/woman.png";

    if (!this->textureSheet.loadFromFile(path)) {
        std::cout << "ERRO::PLAYER::Não foi possível carregar a textura do jogador!" << "\n";
    }
}

void Player::initSprite() {
    this->sprite.setTexture(this->textureSheet);
    this->currentFrame = sf::IntRect(0, 0, 80, 64);

    this->sprite.setTextureRect(this->currentFrame);
    this->sprite.setScale(-4.f, 4.f);

    this->setPosition(this->getPosition().x + 300 ,720 - this->getGlobalBounds().height - 131);
}

void Player::initAnimations() {
    this->animationTimer.restart();
    this->animationSwitch = true;
    this->currentFrame.left = 0.f;
}

void Player::initPhysics() {
    this->velocityMax = 5.f;
    this->velocityMin = 1.0f;
    this->acceleration = 2.0f;
    this->drag = 0.70f;
}

Player::Player(Util* util, int &gender, int &life, int &attack, int &defense, int &luck): util(util), gender(gender), life(life), attack(attack), defense(defense), luck(luck) {
    this->initVariables();
    this->initTexture();
    this->initSprite();
    this->initAnimations();
    this->initPhysics();
    this->inventory = new Inventory(this->util);
    this->item_in_use = 0;
}

Player::~Player() {

}

bool Player::getAnimSwitch() {
    bool anim_switch = this->animationSwitch;

    if (this->animationSwitch)
        this->animationSwitch = false;

    return anim_switch;
}

const sf::Vector2f Player::getPosition() const {
    return this->sprite.getPosition();
}

const sf::FloatRect Player::getGlobalBounds() const {
    return this->sprite.getGlobalBounds();
}

const sf::Vector2f Player::getCenter() const {
    sf::FloatRect bounds = this->sprite.getGlobalBounds();
    return sf::Vector2f(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
}

void Player::addItemToInventory(int type, int buff, int duration) {
    std::string name = inventory->getItemNameByType(type);

    inventory->addItem(name, buff, type, duration);
}

void Player::removeItemFromInventory(const std::string& name) {
    inventory->removeItem(name);
}

void Player::displayInventory() const {
    inventory->displayInventory();
}

bool Player::inventoryIsEmpty() const {
    return inventory->isEmpty();
}

void Player::useItem(int index) {
    this->item_in_use = index;
}

void Player::setPosition(const float x, const float y) {
    this->sprite.setPosition(x, y);
}

void Player::resetAnimationTimer() {
    this->animationTimer.restart();
    this->animationSwitch = true;
}

void Player::move(const float dir_x) {
    this->velocity.x += dir_x * this->acceleration;

    if (std::abs(this->velocity.x) > this->velocityMax) {
        this->velocity.x = this->velocityMax * ((this->velocity.x < 0.f) ? -1.f : 1.f);
    }
}

void Player::updatePhysics() {
    this->velocity *= this->drag;

    if (std::abs(this->velocity.x) < this->velocityMin)
        this->velocity.x = 0.f;

    if(std::abs(this->velocity.x) <= 1.f)
        this->velocity.x = 0.f;

    this->sprite.move(this->velocity);
}

void Player::updateMovement() {
    if(this->velocity.x > 0.f)
        this->animState = PLAYER_ANIMATION_STATES::MOVING_RIGHT;
    else if(this->velocity.x < 0.f)
        this->animState = PLAYER_ANIMATION_STATES::MOVING_LEFT;
    else
        this->animState = PLAYER_ANIMATION_STATES::IDLE;
}

void Player::updateAnimations() {
    float speedPercent = (std::abs(this->velocity.x) / this->velocityMax);

    if (this->animState == PLAYER_ANIMATION_STATES::IDLE) {
        if (this->animationTimer.getElapsedTime().asMilliseconds() >= 320.f || this->getAnimSwitch()) {
            this->currentFrame.top = 0.f;
            this->currentFrame.left += 80.f;
            if (this->currentFrame.left > 320.f)
                this->currentFrame.left = 0;

            this->animationTimer.restart();
            this->sprite.setTextureRect(this->currentFrame);
        }
    }
    else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_RIGHT) {
        if (this->animationTimer.getElapsedTime().asMilliseconds() >= 64.f / speedPercent || this->getAnimSwitch()) {
            this->currentFrame.top = 128.f;
            this->currentFrame.left += 80.f;
            if (this->currentFrame.left > 560.f)
                this->currentFrame.left = 0;

            this->animationTimer.restart();
            this->sprite.setTextureRect(this->currentFrame);
        }

        this->sprite.setScale(-4.f, 4.f);
        this->sprite.setOrigin(0.f, 0.f);
    }
    else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_LEFT) {
        if (this->animationTimer.getElapsedTime().asMilliseconds() >= 64.f / speedPercent || this->getAnimSwitch()) {
            this->currentFrame.top = 128.f;
            this->currentFrame.left += 80.f;
            if (this->currentFrame.left > 560.f)
                this->currentFrame.left = 0;

            this->animationTimer.restart();
            this->sprite.setTextureRect(this->currentFrame);
        }

        this->sprite.setScale(4.f, 4.f);
        this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 4.f, 0.f);
    }
    else
        this->animationTimer.restart();
}

void Player::update() {
    this->updateMovement();
    this->updateAnimations();
    this->updatePhysics();
}

void Player::render(sf::RenderTarget & target) {
    target.draw(this->sprite);
}

Item Player::getItemInUse() const {
    return inventory->getItemByIndex(this->item_in_use);
}

void Player::decrementItemDuration() {
    inventory->decrementDuration(this->item_in_use);
}

int Player::getInventorySize() {
    return inventory->getSize();
}
