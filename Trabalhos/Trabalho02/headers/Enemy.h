#pragma once

#include <SFML/Graphics.hpp>

enum EnemyType {
    NORMAL = 1,
    BOSS = 2
};

enum Enemies {
    GREEN_SLIME = 1,
//    RED_SLIME = 2,
//    BLUE_SLIME = 3,
    CURSED_GREEN_SLIME = 2,
    FLYING_DEMON = 3,
    FLYING_EYE = 4,
    MUSHROOM =  5,
    CURSED_MUSHROOM = 6,
    SKELETON_WARRIOR = 7,
    CURSED_SKELETON = 8,
    GOBLIN = 9,
};

enum Bosses {
    EVIL_WIZARD = 1,
    NECROMANCER = 2,
    KNIGHT = 3,
    NIGHT_BORNE = 4,
//    BRINGER_OF_DEATH = 5
};

class Enemy {
public:
    Enemy(int enemy_id, int position, int type, int &difficulty);
    virtual ~Enemy();

    int &difficulty;
    int life, attack, defense, luck;

    const sf::Vector2f getPosition() const;
    const sf::FloatRect getGlobalBounds() const;
    const sf::Vector2f getCenter() const;

    std::string getEnemyName();
    std::string getBossName(int boss_id);
    int getEnemyType();

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
