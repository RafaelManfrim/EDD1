#pragma once

#include <SFML/Graphics.hpp>

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

    void initVariables();
    void initTexture();
    void initSprite();
    void initAnimations();
    void initPhysics();

public:
    Player(int &gender);
    virtual ~Player();

    int &gender;

    bool getAnimSwitch();
    const sf::Vector2f getPosition() const;
    const sf::FloatRect getGlobalBounds() const;
    const sf::Vector2f getCenter() const;

    void setPosition(const float x, const float y);

    void resetAnimationTimer();
    void move(const float dir_x);
    void updatePhysics();
    void updateMovement();
    void updateAnimations();
    void update();
    void render(sf::RenderTarget& target);
};
