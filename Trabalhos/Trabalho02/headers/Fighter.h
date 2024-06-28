#pragma once

#include "Util.h"

class Fighter {
public:
    Fighter(Util* util, int &life, int &attack, int &defense, int &luck, int fighter_id);
    ~Fighter();

    Util* util;

    void performAttack(Fighter &defender, int &dodges, int &special_attacks);

    void generateRandomDamageRange(int &a, int &b);
    void generateRandomDodgeChanceRange(Fighter &defender, int &a, int &b);
    void generateRandomSpecialAttackChanceRange(int &a, int &b);

    int getRemainingLife();
    int getTotalDamageDealt();
    int getRemainingBleedingRounds();

    void applyBleeding(int rounds);
    void takeDamage(int damage);
    void increaseDamageDealt(int damage);

    int getLife();
    int getAttack();
    int getDefense();
    int getLuck();
private:
    int &life, &attack, &defense, &luck, fighter_id;

    int remaining_life;
    int remaining_bleeding_rounds;
    int total_damage_dealt;
};

