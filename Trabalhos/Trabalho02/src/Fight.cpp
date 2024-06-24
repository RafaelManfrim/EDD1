#include <iostream>
#include <random>
#include <unistd.h>

#include "../headers/Fight.h"


Fight::Fight(Player& player, Enemy& enemy): player(player), enemy(enemy) {
    std::cout << "Luta contra " << enemy.getEnemyName() << " iniciada!" << std::endl;

    std::random_device generator;
    std::uniform_int_distribution<int> first_attack_possibilities(1,2);

    int life_buff = 0, attack_buff = 0, defense_buff = 0, luck_buff = 0;

    switch(player.getItemInUse().type) {
        case ItemType::LIFE:
            life_buff = player.getItemInUse().buff;
            break;
        case ItemType::ATTACK:
            attack_buff = player.getItemInUse().buff;
            break;
        case ItemType::DEFENSE:
            defense_buff = player.getItemInUse().buff;
            break;
        case ItemType::LUCK:
            luck_buff = player.getItemInUse().buff;
            break;
        default:
            break;
    }

    player.life += life_buff;
    player.attack += attack_buff;
    player.defense += defense_buff;
    player.luck += luck_buff;

    int turn = 1;
    this->winner = 0;
    int dodges = 0, special_attacks = 0;

    this->player_fighter = new Fighter(player.life, player.attack, player.defense, player.luck, 1);
    this->enemy_fighter = new Fighter(enemy.life, enemy.attack, enemy.defense, enemy.luck, 2);

    std::cout << "Sua vida: " << player_fighter->getRemainingLife() << std::endl;
    std::cout << "Vida de " << enemy.getEnemyName() << ": " << enemy_fighter->getRemainingLife() << std::endl;

    while (turn <= 10){
        std::cout << "Turno " << turn << " --------------------------- " << std::endl;
        int first_to_attack = first_attack_possibilities(generator);

        if(first_to_attack == 1) {
            if(enemy_fighter->getRemainingBleedingRounds() > 0) {
                int bleeding_damage = ceil(enemy.life * 0.05 + (player.attack + attack_buff) * 2);

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
                int bleeding_damage = ceil((player.life - life_buff) * 0.05 + enemy.attack * 2);

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
                int bleeding_damage = ceil((player.life - life_buff) * 0.05 + enemy.attack * 2);

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
                int bleeding_damage = ceil(enemy.life * 0.05 + (player.attack + attack_buff) * 2);

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

    player.life -= life_buff;
    player.attack -= attack_buff;
    player.defense -= defense_buff;
    player.luck -= luck_buff;

    if (player_fighter->getRemainingLife() > 0 && enemy_fighter->getRemainingLife() > 0) {
        if (player_fighter->getTotalDamageDealt() < enemy_fighter->getTotalDamageDealt()) {
            winner = 1;
        } else {
            winner = 2;
        }
    }

    std::cout << "Seu dano: " << enemy_fighter->getTotalDamageDealt() << std::endl;
    std::cout << "Dano " << enemy.getEnemyName() << ": " << player_fighter->getTotalDamageDealt() << std::endl;
    std::cout << "Sua vida restante: " << player_fighter->getRemainingLife() << std::endl;
    std::cout << "Vida restante " << enemy.getEnemyName() << ": " << enemy_fighter->getRemainingLife() << std::endl;
    std::cout << "Turnos ocorridos: " << turn << std::endl;
    std::cout << "Quantidade de ataques especiais: " << special_attacks << std::endl;
    std::cout << "Quantidade de esquivas: " << dodges << std::endl << std::endl;

    player.decrementItemDuration();

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