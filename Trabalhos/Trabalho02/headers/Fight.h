#pragma once

#include "./Player.h"
#include "./Enemy.h"
#include "./Fighter.h"
#include "./Util.h"

class Fight {
public:
    Fight(sf::RenderWindow &window, Player& player, Enemy& enemy, Util* util, int map_size);

    ~Fight();

    int map_size;
    Util* util;
    sf::RenderWindow &window;
    Fighter* player_fighter;
    Fighter* enemy_fighter;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    int getWinner();
private:
    int winner;

    Player& player;
    Enemy& enemy;

    void renderBackground();
    void update();
};