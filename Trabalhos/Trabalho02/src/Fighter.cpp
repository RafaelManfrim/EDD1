#include <iostream>
#include <random>
#include <unistd.h>

#include "../headers/Fighter.h"

Fighter::Fighter(int &life, int &attack, int &defense, int &luck): life(life), attack(attack), defense(defense), luck(luck) {
    this->remaining_life = 100 + life * 20;
    this->remaining_bleeding_rounds = 0;
    this->total_damage_caused = 0;
}

Fighter::~Fighter() {

}

void Fighter::generateRandomDamageRange(int &a, int &b) {
    switch(this->luck) {
        case 0:
            a = 8;
            b = 15;
            break;
        case 1:
            a = 9;
            b = 15;
            break;
        case 2:
            a = 9;
            b = 16;
            break;
        case 3:
            a = 10;
            b = 16;
            break;
        case 4:
            a = 10;
            b = 17;
            break;
        case 5:
            a = 11;
            b = 17;
            break;
        case 6:
            a = 11;
            b = 18;
            break;
        case 7:
            a = 12;
            b = 18;
            break;
        case 8:
            a = 12;
            b = 19;
            break;
        case 9:
            a = 13;
            b = 19;
            break;
        case 10:
            a = 13;
            b = 20;
            break;
        case 11:
            a = 14;
            b = 20;
            break;
        case 12:
            a = 14;
            b = 21;
            break;
        case 13:
            a = 15;
            b = 21;
            break;
        case 14:
            a = 15;
            b = 22;
            break;
        case 15:
            a = 16;
            b = 22;
            break;
        case 16:
            a = 16;
            b = 23;
            break;
        case 17:
            a = 17;
            b = 23;
            break;
        case 18:
            a = 17;
            b = 24;
            break;
        case 19:
            a = 18;
            b = 24;
            break;
        case 20:
            a = 18;
            b = 25;
            break;
        default:
            a = 0;
            b = 0;
            break;
    }
}


void Fighter::generateRandomDodgeChanceRange(Fighter &defender, int &a, int &b) {
    switch(defender.getLuck()) {
        case 0:
            a = 0;
            b = 16;
            break;
        case 1:
            a = 0;
            b = 15;
            break;
        case 2:
            a = 0;
            b = 14;
            break;
        case 3:
            a = 0;
            b = 13;
            break;
        case 4:
            a = 0;
            b = 12;
            break;
        case 5:
            a = 0;
            b = 11;
            break;
        case 6:
            a = 0;
            b = 10;
            break;
        case 7:
            a = 0;
            b = 9;
            break;
        case 8:
            a = 0;
            b = 8;
            break;
        case 9:
            a = 0;
            b = 7;
            break;
        case 10:
            a = 0;
            b = 6;
            break;
        case 11:
            a = 0;
            b = 5;
            break;
        case 12:
            a = 0;
            b = 4;
            break;
        case 13:
            a = 0;
            b = 3;
            break;
        case 14:
            a = 0;
            b = 2;
            break;
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
            a = 0;
            b = 1;
            break;
        default:
            a = 0;
            b = 16;
            break;
    }
}


void Fighter::generateRandomSpecialAttackChanceRange(int &a, int &b) {
    switch(this->luck) {
        case 0:
            a = 0;
            b = 16;
            break;
        case 1:
            a = 0;
            b = 15;
            break;
        case 2:
            a = 0;
            b = 14;
            break;
        case 3:
            a = 0;
            b = 13;
            break;
        case 4:
            a = 0;
            b = 12;
            break;
        case 5:
            a = 0;
            b = 11;
            break;
        case 6:
            a = 0;
            b = 10;
            break;
        case 7:
            a = 0;
            b = 9;
            break;
        case 8:
            a = 0;
            b = 8;
            break;
        case 9:
            a = 0;
            b = 7;
            break;
        case 10:
            a = 0;
            b = 6;
            break;
        case 11:
            a = 0;
            b = 5;
            break;
        case 12:
            a = 0;
            b = 4;
            break;
        case 13:
            a = 0;
            b = 3;
            break;
        case 14:
            a = 0;
            b = 2;
            break;
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
            a = 0;
            b = 1;
            break;
        default:
            a = 0;
            b = 16;
            break;
    }
}


void Fighter::performAttack(Fighter &defender, int &dodges, int &special_attacks) {
    std::random_device generator;
    int a, b;

    this->generateRandomDodgeChanceRange(defender, a, b);

    std::uniform_int_distribution<int> dodge_possibility(a,b);
    int dodge = dodge_possibility(generator);
    if(dodge == 0) {
        dodges++;
//        std::cout << atacante.nickname << " ataca: " << std::endl << defensor.nickname << " desviou..." << std::endl;
        sleep(1);
        return;
    }

    this->generateRandomDamageRange(a, b);
    std::uniform_int_distribution<int> random_damage_range(a,b);
    int random_damage = random_damage_range(generator);
    int damage = 15 + this->attack * 5 - defender.getDefense() * 5 + random_damage;

    generateRandomSpecialAttackChanceRange(a, b);
    std::uniform_int_distribution<int> randomSpecialAttackChanceRange(a,b);
    int special_attack = randomSpecialAttackChanceRange(generator);

    if(special_attack == 0) {
        special_attacks++;
//        std::cout << atacante.nickname << " está usando o ataque " << atacante.special_attack << std::endl;
        sleep(1);
        damage = ceil(damage + damage * 0.4);

        std::uniform_int_distribution<int> bleeding_chance(0,2);
        int bleeding = bleeding_chance(generator);
        if(bleeding == 0) {
            std::uniform_int_distribution<int> bleeding_turns_chance(2,6);
            int bleeding_turns = bleeding_turns_chance(generator);
            std::cout << "O ataque especial causou sangramento de: " << bleeding_turns << " turnos" << std::endl;
            sleep(1);
            defender.applyBleeding(bleeding_turns);
        }
    } else {
//        std::cout << atacante.nickname << " ataca: " << std::endl;
        sleep(1);
    }

    defender.takeDamage(damage);
    defender.increaseDamageDealt(damage);
}

int Fighter::getRemainingLife() {
    return this->remaining_life;
}

int Fighter::getTotalDamageCaused() {
    return this->total_damage_caused;
}

int Fighter::getRemainingBleedingRounds() {
    return this->remaining_bleeding_rounds;
}

void Fighter::applyBleeding(int rounds) {
    this->remaining_bleeding_rounds += rounds;
}

void Fighter::takeDamage(int damage) {
    this->remaining_life -= damage;
}

void Fighter::increaseDamageDealt(int damage) {
    this->total_damage_caused += damage;
}

int Fighter::getLife() {
    return this->life;
}

int Fighter::getAttack() {
    return this->attack;
}

int Fighter::getDefense() {
    return this->defense;
}

int Fighter::getLuck() {
    return this->luck;
}