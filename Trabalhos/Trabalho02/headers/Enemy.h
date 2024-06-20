#pragma once

#include <SFML/Graphics.hpp>

enum Enemies {
    GREEN_SLIME = 1,
    RED_SLIME = 2,
    BLUE_SLIME = 3,
    CURSED_GREEN_SLIME = 4,
    FLYING_DEMON = 5,
    FLYING_EYE = 6,
    MUSHROOM =  7,
    CURSED_MUSHROOM = 8,
    SKELETON_WARRIOR = 9,
    CURSED_SKELETON = 10,
    GOBLIN = 11,
};

class Enemy {
private:
    int enemy_id;
    int image_width, image_height, sprites_count, sprite_width;
    bool rotate;
    std::string filename;

    int position;

    sf::Sprite sprite;
    sf::Texture textureSheet;
    sf::Clock animationTimer;
    sf::IntRect currentFrame;

    void initTexture();
    void initSprite();
    void initAnimations();

    void getEnemyData();

public:
    Enemy(int enemy_id, int position);
    virtual ~Enemy();

    const sf::Vector2f getPosition() const;
    const sf::FloatRect getGlobalBounds() const;

    std::string getEnemyName();

    void setPosition(const float x, const float y);

    void updateAnimations();
    void update();
    void render(sf::RenderTarget& target);
};
