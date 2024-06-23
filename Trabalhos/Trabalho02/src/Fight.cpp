#include <iostream>
#include <random>
#include <unistd.h>

#include "../headers/Fight.h"


Fight::Fight(Player& player, Enemy& enemy): player(player), enemy(enemy) {
//    std::cout << player.nickname << "(" << character_class_name(fighter1.character_class) << ")";
//    cout << " x ";
//    cout << fighter2.nickname << "(" << character_class_name(fighter2.character_class) << ")" << endl;

    std::cout << "Luta contra " << enemy.getEnemyName() << " iniciada!" << std::endl;

    std::random_device generator;
    std::uniform_int_distribution<int> first_attack_possibilities(1,2);

    int turn = 1;
    this->winner = 0;
    int dodges = 0, special_attacks = 0;

    this->player_fighter = new Fighter(player.life, player.attack, player.defense, player.luck);
    this->enemy_fighter = new Fighter(enemy.life, enemy.attack, enemy.defense, enemy.luck);

    while (turn <= 10){
        std::cout << "Turno " << turn << " --------------------------- " << std::endl;
        int first_to_attack = first_attack_possibilities(generator);

        if(first_to_attack == 1) {
            if(enemy_fighter->getRemainingBleedingRounds() > 0) {
                int bleeding_damage = ceil(enemy.life * 0.05 + player.attack * 2);

                std::cout << enemy.getEnemyName() << " recebeu " << bleeding_damage << " de dano de sangramento." << std::endl;
                sleep(1);

                enemy_fighter->takeDamage(bleeding_damage);
                enemy_fighter->applyBleeding(-1);

                std::cout << "Vida restante de " << enemy.getEnemyName() << ": " << enemy_fighter->getRemainingLife() << std::endl;

                if(enemy_fighter->getRemainingLife() <= 0) {
                    std::cout << "Você venceu!!!" << std::endl;
                    sleep(1);
                    winner = 1;
                    break;
                }
            }

            if(player_fighter->getRemainingBleedingRounds() > 0) {
                int bleeding_damage = ceil(player.life * 0.05 + enemy.attack * 2);

                std::cout << "Você recebeu " << bleeding_damage << " de dano de sangramento." << std::endl;
                sleep(1);

                player_fighter->takeDamage(bleeding_damage);
                player_fighter->applyBleeding(-1);

                std::cout << "Sua vida restante: " << player_fighter->getRemainingLife() << std::endl;

                if(player_fighter->getRemainingLife() <= 0) {
                    std::cout << "Você perdeu..." << std::endl;
                    sleep(1);
                    winner = 2;
                    break;
                }
            }

            player_fighter->performAttack(*enemy_fighter, dodges, special_attacks);

            std::cout << "Vida restante de " << enemy.getEnemyName() << ": " << enemy_fighter->getRemainingLife() << std::endl;

            if(enemy_fighter->getRemainingLife() <= 0) {
                std::cout << "Você venceu!!!" << std::endl;
                sleep(1);
                winner = 1;
                break;
            }

            enemy_fighter->performAttack(*player_fighter, dodges, special_attacks);

            std::cout << "Sua vida restante: " << player_fighter->getRemainingLife() << std::endl;

            if(player_fighter->getRemainingLife() <= 0) {
                std::cout << "Você perdeu..." << std::endl;
                sleep(1);
                winner = 2;
                break;
            }
        } else if(first_to_attack == 2) {
            if(player_fighter->getRemainingBleedingRounds() > 0) {
                int bleeding_damage = ceil(player.life * 0.05 + enemy.attack * 2);

                std::cout << "Você recebeu " << bleeding_damage << " de dano de sangramento." << std::endl;
                sleep(1);

                player_fighter->takeDamage(bleeding_damage);
                player_fighter->applyBleeding(-1);

                std::cout << "Sua vida restante: " << player_fighter->getRemainingLife() << std::endl;

                if(player_fighter->getRemainingLife() <= 0) {
                    std::cout << "Você perdeu..." << std::endl;
                    sleep(1);
                    winner = 2;
                    break;
                }
            }

            if(enemy_fighter->getRemainingBleedingRounds() > 0) {
                int bleeding_damage = ceil(enemy.life * 0.05 + player.attack * 2);

                std::cout << enemy.getEnemyName() << " recebeu " << bleeding_damage << " de dano de sangramento." << std::endl;
                sleep(1);

                enemy_fighter->takeDamage(bleeding_damage);
                enemy_fighter->applyBleeding(-1);

                std::cout << "Vida restante de " << enemy.getEnemyName() << ": " << enemy_fighter->getRemainingLife() << std::endl;

                if(enemy_fighter->getRemainingLife() <= 0) {
                    std::cout << "Você venceu!!!" << std::endl;
                    sleep(1);
                    winner = 1;
                    break;
                }
            }


            enemy_fighter->performAttack(*player_fighter, dodges, special_attacks);

            std::cout << "Sua vida restante: " << player_fighter->getRemainingLife() << std::endl;

            if(player_fighter->getRemainingLife() <= 0) {
                std::cout << "Você perdeu..." << std::endl;
                sleep(1);
                winner = 2;
                break;
            }

            player_fighter->performAttack(*enemy_fighter, dodges, special_attacks);

            std::cout << "Vida restante de " << enemy.getEnemyName() << ": " << enemy_fighter->getRemainingLife() << std::endl;

            if(enemy_fighter->getRemainingLife() <= 0) {
                std::cout << "Você venceu!!!" << std::endl;
                sleep(1);
                winner = 1;
                break;
            }
        }
        turn++;
    }


    if (player_fighter->getRemainingLife() > 0 && enemy_fighter->getRemainingLife() > 0) {
        if (player_fighter->getTotalDamageCaused() > enemy_fighter->getTotalDamageCaused()) {
            winner = 1;
        } else {
            winner = 2;
        }
    }

    std::cout << "Seu dano: " << player_fighter->getTotalDamageCaused() << std::endl;
    std::cout << "Dano " << enemy.getEnemyName() << ": " << enemy_fighter->getTotalDamageCaused() << std::endl;
    std::cout << "Sua vida restante: " << player_fighter->getRemainingLife() << std::endl;
    std::cout << "Vida restante " << enemy.getEnemyName() << ": " << enemy_fighter->getRemainingLife() << std::endl;
    std::cout << "Turnos ocorridos: " << turn << std::endl;
    std::cout << "Quantidade de ataques especiais: " << special_attacks << std::endl;
    std::cout << "Quantidade de esquivas: " << dodges << std::endl << std::endl;

//    if(winner == 1) {
//        Character *temp = new Character[fighter1.num_defeated_characters + 1];
//
//        for (int i = 0; i < fighter1.num_defeated_characters; i++) {
//            temp[i] = fighter1.defeated_characters[i];
//        }
//
//        temp[fighter1.num_defeated_characters] = fighter2;
//        delete[] fighter1.defeated_characters;
//        fighter1.defeated_characters = temp;
//        fighter1.num_defeated_characters++;
//
//        return fighter1;
//    }
//
//    Character *temp = new Character[fighter2.num_defeated_characters + 1];
//
//    for (int i = 0; i < fighter2.num_defeated_characters; i++) {
//        temp[i] = fighter2.defeated_characters[i];
//    }
//
//    temp[fighter2.num_defeated_characters] = fighter1;
//    delete[] fighter2.defeated_characters;
//    fighter2.defeated_characters = temp;
//    fighter2.num_defeated_characters++;
//
//    return fighter2;
}

Fight::~Fight() {
    delete this->player_fighter;
    delete this->enemy_fighter;
}

int Fight::getWinner() {
    return this->winner;
}