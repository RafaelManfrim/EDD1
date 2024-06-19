#pragma once

#include <SFML/Graphics.hpp>

enum ENEMY_ANIMATION_STATES {ENEMY_IDLE = 0};

class Enemy {
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

    void initVariables();
    void initTexture();
    void initSprite();
    void initAnimations();
    void initPhysics();

public:
    Enemy();
    virtual ~Enemy();

    bool getAnimSwitch();
    const sf::Vector2f getPosition() const;
    const sf::FloatRect getGlobalBounds() const;

    void setPosition(const float x, const float y);

    void resetAnimationTimer();
    void move(const float dir_x);
    void updatePhysics();
    void updateMovement();
    void updateAnimations();
    void update();
    void render(sf::RenderTarget& target);
};
