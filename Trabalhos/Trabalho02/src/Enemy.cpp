#include <iostream>

#include "../headers/Enemy.h"

void Enemy::initTexture() {
    std::string path;

    if(this->type == 1) {
        path = "../assets/sprites/enemies/" + this->filename;
    } else if (this->type == 2) {
        path = "../assets/sprites/bosses/" + this->filename;
    }

    if (!this->textureSheet.loadFromFile(path)) {
        std::cout << "ERRO::ENEMY::Não foi possível carregar a textura do inimigo!" << "\n";
    }
}

void Enemy::initSprite() {
    this->sprite.setTexture(this->textureSheet);
    this->currentFrame = sf::IntRect(0, 0, this->sprite_width, this->image_height);

    this->sprite.setTextureRect(this->currentFrame);

    if (this->type == 1) {
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
    } else {
        if (this->rotate) {
            if (this->filename == "evil_wizard.png") {
                this->sprite.setScale(-5.f, 5.f);
            } else if (this->filename == "necromancer.png") {
                this->sprite.setScale(-7.f, 7.f);
            } else if (this->filename == "knight.png") {
                this->sprite.setScale(-4.f, 4.f);
            } else if (this->filename == "night_borne.png") {
                this->sprite.setScale(-10.f, 10.f);
            }
        } else {
            this->sprite.setScale(7.f, 7.f);
        }
    }

    this->sprite.setPosition(this->sprite.getPosition().x + 1600 * position, 720 - this->getGlobalBounds().height - 131);
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

void Enemy::getBossData() {
    switch (this->enemy_id) {
        case Bosses::EVIL_WIZARD:
            this->image_width = 2000;
            this->image_height = 128;
            this->sprites_count = 8;
            this->sprite_width = 250;
            this->rotate = true;
            this->filename = "evil_wizard.png";
            break;
        case Bosses::NECROMANCER:
            this->image_width = 1280;
            this->image_height = 64;
            this->sprites_count = 8;
            this->sprite_width = 160;
            this->rotate = true;
            this->filename = "necromancer.png";
            break;
        case Bosses::KNIGHT:
            this->image_width = 800;
            this->image_height = 85;
            this->sprites_count = 8;
            this->sprite_width = 100;
            this->rotate = true;
            this->filename = "knight.png";
            break;
        case Bosses::NIGHT_BORNE:
            this->image_width = 720;
            this->image_height = 64;
            this->sprites_count = 9;
            this->sprite_width = 80;
            this->rotate = true;
            this->filename = "night_borne.png";
            break;
        case Bosses::BRINGER_OF_DEATH:
            this->image_width = 1120;
            this->image_height = 64;
            this->sprites_count = 8;
            this->sprite_width = 140;
            this->rotate = false;
            this->filename = "bringer_of_death.png";
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

Enemy::Enemy(int enemy_id, int position, int type) : enemy_id(enemy_id), position(position), type(type) {
    if(this->type == 1) {
        this->getEnemyData();
    } else if(this->type == 2) {
        this->getBossData();
    }

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

std::string Enemy::getBossName(int boss_id) {
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