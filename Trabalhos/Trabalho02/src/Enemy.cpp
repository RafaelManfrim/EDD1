#include <iostream>

#include "../headers/Enemy.h"

void Enemy::initTexture() {
    std::string path = "../assets/sprites/enemies/" + this->filename;

    if (!this->textureSheet.loadFromFile(path)) {
        std::cout << "ERRO::ENEMY::Não foi possível carregar a textura do inimigo!" << "\n";
    }
}

void Enemy::initSprite() {
    this->sprite.setTexture(this->textureSheet);
    this->currentFrame = sf::IntRect(0, 0, this->sprite_width, this->image_height);

    this->sprite.setTextureRect(this->currentFrame);

    if (this->rotate) {
        if (this->image_height == 32 || (this->image_height == 64 && sprite_width == 150)) {
            this->sprite.setScale(-4.f, 4.f);
        } else if(this->image_height == 64 && sprite_width == 64) {
            this->sprite.setScale(-5.f, 5.f);
        } else {
            this->sprite.setScale(-3.f, 3.f);
        }
    } else {
        if (this->image_height == 32 || (this->image_height == 64 && sprite_width == 80)) {
            if(this->sprite_width == 32) {
                this->sprite.setScale(5.f, 5.f);
            } else {
                this->sprite.setScale(4.f, 4.f);
            }
        } else {
            this->sprite.setScale(3.f, 3.f);
        }
    }

    this->sprite.setPosition(this->sprite.getPosition().x + 600, 720 - this->getGlobalBounds().height - 131);
}

void Enemy::initAnimations() {
    this->animationTimer.restart();
    this->currentFrame.left = 0.f;
}

void Enemy::getEnemyData() {
    switch (this->enemy_id) {
        case Enemies::GREEN_SLIME:
            this->image_width = 672;
            this->image_height = 32;
            this->sprites_count = 7;
            this->sprite_width = 96;
            this->rotate = false;
            this->filename = "green_slime.png";
            break;
        case Enemies::RED_SLIME:
            this->image_width = 672;
            this->image_height = 32;
            this->sprites_count = 7;
            this->sprite_width = 96;
            this->rotate = false;
            this->filename = "red_slime.png";
            break;
        case Enemies::BLUE_SLIME:
            this->image_width = 672;
            this->image_height = 32;
            this->sprites_count = 7;
            this->sprite_width = 96;
            this->rotate = false;
            this->filename = "blue_slime.png";
            break;
        case Enemies::CURSED_GREEN_SLIME:
            this->image_width = 160;
            this->image_height = 32;
            this->sprites_count = 5;
            this->sprite_width = 32;
            this->rotate = false;
            this->filename = "cursed_green_slime.png";
            break;
        case Enemies::FLYING_DEMON:
            this->image_width = 324;
            this->image_height = 71;
            this->sprites_count = 4;
            this->sprite_width = 81;
            this->rotate = false;
            this->filename = "flying_demon.png";
            break;
        case Enemies::FLYING_EYE:
            this->image_width = 1200;
            this->image_height = 64;
            this->sprites_count = 8;
            this->sprite_width = 150;
            this->rotate = true;
            this->filename = "flying_eye.png";
            break;
        case Enemies::MUSHROOM:
            this->image_width = 560;
            this->image_height = 64;
            this->sprites_count = 7;
            this->sprite_width = 80;
            this->rotate = false;
            this->filename = "mushroom.png";
            break;
        case Enemies::CURSED_MUSHROOM:
            this->image_width = 600;
            this->image_height = 64;
            this->sprites_count = 4;
            this->sprite_width = 150;
            this->rotate = true;
            this->filename = "cursed_mushroom.png";
            break;
        case Enemies::SKELETON_WARRIOR:
            this->image_width = 600;
            this->image_height = 64;
            this->sprites_count = 4;
            this->sprite_width = 150;
            this->rotate = true;
            this->filename = "skeleton_warrior.png";
            break;
        case Enemies::CURSED_SKELETON:
            this->image_width = 256;
            this->image_height = 64;
            this->sprites_count = 4;
            this->sprite_width = 64;
            this->rotate = true;
            this->filename = "cursed_skeleton.png";
            break;
        case Enemies::GOBLIN:
            this->image_width = 600;
            this->image_height = 64;
            this->sprites_count = 4;
            this->sprite_width = 150;
            this->rotate = true;
            this->filename = "goblin.png";
            break;
        default:
            this->image_width = 0;
            this->image_height = 0;
            this->sprites_count = 0;
            this->sprite_width = 0;
            this->rotate = false;
            this->filename = "unknown.png";
            break;
    }
}

Enemy::Enemy(int enemy_id, int position) : enemy_id(enemy_id), position(position) {
    this->getEnemyData();
    this->initTexture();
    this->initSprite();
    this->initAnimations();
}

Enemy::~Enemy() {

}

const sf::Vector2f Enemy::getPosition() const {
    return this->sprite.getPosition();
}

const sf::FloatRect Enemy::getGlobalBounds() const {
    return this->sprite.getGlobalBounds();
}

std::string Enemy::getEnemyName() {
    switch (this->enemy_id) {
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

void Enemy::setPosition(const float x, const float y) {
    this->sprite.setPosition(x, y);
}

void Enemy::updateAnimations() {
    if (this->animationTimer.getElapsedTime().asMilliseconds() >= 320.f) {
        this->currentFrame.top = 0.f;
        this->currentFrame.left += this->sprite_width;
        if (this->currentFrame.left > this->image_width - this->sprite_width)
            this->currentFrame.left = 0;

        this->animationTimer.restart();
        this->sprite.setTextureRect(this->currentFrame);
    }
}

void Enemy::update() {
    this->updateAnimations();
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