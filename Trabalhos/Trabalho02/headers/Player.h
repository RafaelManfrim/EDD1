#pragma once

#include <SFML/Graphics.hpp>

#include "Inventory.h"

enum PLAYER_ANIMATION_STATES {IDLE = 0, MOVING_LEFT, MOVING_RIGHT};

enum PlayerGender {
    MASCULINO = 1,
    FEMININO = 2
};

class Player {
private:
    sf::Sprite sprite;
    sf::Texture textureSheet;
    sf::Clock animationTimer;

    short animState;
    sf::IntRect currentFrame;
    bool animationSwitch;

    sf::Vector2f velocity;
    float velocityMax;
    float velocityMin;
    float acceleration;
    float drag;

    Inventory inventory;

    int item_in_use;

    void initVariables();
    void initTexture();
    void initSprite();
    void initAnimations();
    void initPhysics();

public:
    Player(int &gender, int &life, int &attack, int &defense, int &luck);
    virtual ~Player();

    int &gender, &life, &attack, &defense, &luck;

    bool getAnimSwitch();
    const sf::Vector2f getPosition() const;
    const sf::FloatRect getGlobalBounds() const;
    const sf::Vector2f getCenter() const;

    void addItemToInventory(int type, int buff, int duration);
    void removeItemFromInventory(const std::string& name);
    void removeUsedItemFromInventory();
    void displayInventory() const;
    bool inventoryIsEmpty() const;
    void useItem(int index);
    Item getItemInUse() const;
    void decrementItemDuration();

    void setPosition(const float x, const float y);

    void resetAnimationTimer();
    void move(const float dir_x);
    void updatePhysics();
    void updateMovement();
    void updateAnimations();
    void update();
    void render(sf::RenderTarget& target);
};
