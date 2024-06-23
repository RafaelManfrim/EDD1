#pragma once

#include "./Player.h"
#include "./Enemy.h"
#include "./Fighter.h"

class Fight {
public:
    Fight(Player& player, Enemy& enemy);
    ~Fight();

    Fighter* player_fighter;
    Fighter* enemy_fighter;

    int getWinner();
private:
    int winner;

    Player& player;
    Enemy& enemy;
};