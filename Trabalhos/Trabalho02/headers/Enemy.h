#pragma once

#include <SFML/Graphics.hpp>

enum EnemyType {
    NORMAL = 1,
    BOSS = 2
};

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

enum Bosses {
    EVIL_WIZARD = 1,
    NECROMANCER = 2,
    KNIGHT = 3,
    NIGHT_BORNE = 4,
    BRINGER_OF_DEATH = 5
};

class Enemy {
public:
    Enemy(int enemy_id, int position, int type);
    virtual ~Enemy();

    const sf::Vector2f getPosition() const;
    const sf::FloatRect getGlobalBounds() const;

    std::string getEnemyName();
    std::string getBossName(int boss_id);

    void setPosition(const float x, const float y);

    void updateAnimations();
    void update();
    void render(sf::RenderTarget& target);
protected:
    int enemy_id;
    int type;
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
    void getBossData();
private:

};
