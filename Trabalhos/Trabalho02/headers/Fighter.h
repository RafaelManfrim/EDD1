#pragma once

class Fighter {
public:
    Fighter(int &life, int &attack, int &defense, int &luck);
    ~Fighter();

    void performAttack(Fighter &defender, int &dodges, int &special_attacks);

    void generateRandomDamageRange(int &a, int &b);
    void generateRandomDodgeChanceRange(Fighter &defender, int &a, int &b);
    void generateRandomSpecialAttackChanceRange(int &a, int &b);

    int getRemainingLife();
    int getTotalDamageCaused();
    int getRemainingBleedingRounds();

    void applyBleeding(int rounds);
    void takeDamage(int damage);
    void increaseDamageDealt(int damage);

    int getLife();
    int getAttack();
    int getDefense();
    int getLuck();
private:
    int &life, &attack, &defense, &luck;

    int remaining_life;
    int remaining_bleeding_rounds;
    int total_damage_caused;
};

