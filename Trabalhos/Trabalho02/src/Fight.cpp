#include <iostream>
#include <random>
#include <unistd.h>

#include "../headers/Fight.h"


Fight::Fight(sf::RenderWindow &window, Player& player, Enemy& enemy, Util* util, int map_size):
    window(window), player(player), enemy(enemy), util(util), map_size(map_size) {

    util->addTextToList("Luta contra " + enemy.getEnemyName() + " iniciada!");
    this->update();

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

    this->player_fighter = new Fighter(this->util, player.life, player.attack, player.defense, player.luck, 1);
    this->enemy_fighter = new Fighter(this->util, enemy.life, enemy.attack, enemy.defense, enemy.luck, 2);

    this->util->addTextToList("Sua vida: " + std::to_string(player_fighter->getRemainingLife()));
    this->util->addTextToList("Vida de " + enemy.getEnemyName() + ": " + std::to_string(enemy_fighter->getRemainingLife()));
    this->update();

    this->player.resetAnimationTimer();

    while (turn <= 10){
        this->util->addTextToList("Turno " + std::to_string(turn));
        this->update();

        int first_to_attack = first_attack_possibilities(generator);

        if(first_to_attack == 1) {
            if(enemy_fighter->getRemainingBleedingRounds() > 0) {
                int bleeding_damage = ceil(enemy.life * 0.05 + (player.attack + attack_buff) * 2);

                this->util->addTextToList(enemy.getEnemyName() + " recebeu " + std::to_string(bleeding_damage) + " de dano de sangramento.");
                this->update();

                enemy_fighter->takeDamage(bleeding_damage);
                enemy_fighter->applyBleeding(-1);

                this->util->addTextToList("Vida restante de " + enemy.getEnemyName() + ": " + std::to_string(enemy_fighter->getRemainingLife()));
                this->update();

                if(enemy_fighter->getRemainingLife() <= 0) {
                    this->util->addTextToList("Voce venceu!!!");
                    this->update();
                    winner = 1;
                    break;
                }
            }

            if(player_fighter->getRemainingBleedingRounds() > 0) {
                int bleeding_damage = ceil((player.life - life_buff) * 0.05 + enemy.attack * 2);

                this->util->addTextToList("Voce recebeu " + std::to_string(bleeding_damage) + " de dano de sangramento.");
                this->update();

                player_fighter->takeDamage(bleeding_damage);
                player_fighter->applyBleeding(-1);

                this->util->addTextToList("Sua vida restante: " + std::to_string(player_fighter->getRemainingLife()));
                this->update();

                if(player_fighter->getRemainingLife() <= 0) {
                    this->util->addTextToList("Voce perdeu...");
                    this->update();
                    winner = 2;
                    break;
                }
            }

            player_fighter->performAttack(*enemy_fighter, dodges, special_attacks);
            this->update();
            sleep(1);

            this->util->addTextToList("Vida restante de " + enemy.getEnemyName() + ": " + std::to_string(enemy_fighter->getRemainingLife()));
            this->update();

            if(enemy_fighter->getRemainingLife() <= 0) {
                this->util->addTextToList("Voce venceu!!!");
                this->update();
                winner = 1;
                break;
            }

            enemy_fighter->performAttack(*player_fighter, dodges, special_attacks);
            this->update();
            sleep(1);

            this->util->addTextToList("Sua vida restante: " + std::to_string(player_fighter->getRemainingLife()));
            this->update();

            if(player_fighter->getRemainingLife() <= 0) {
                this->util->addTextToList("Voce perdeu...");
                this->update();
                winner = 2;
                break;
            }
        } else if(first_to_attack == 2) {
            if(player_fighter->getRemainingBleedingRounds() > 0) {
                int bleeding_damage = ceil((player.life - life_buff) * 0.05 + enemy.attack * 2);

                this->util->addTextToList("Voce recebeu " + std::to_string(bleeding_damage) + " de dano de sangramento.");
                this->update();

                player_fighter->takeDamage(bleeding_damage);
                player_fighter->applyBleeding(-1);

                this->util->addTextToList("Sua vida restante: " + std::to_string(player_fighter->getRemainingLife()));
                this->update();

                if(player_fighter->getRemainingLife() <= 0) {
                    this->util->addTextToList("Voce perdeu...");
                    this->update();
                    winner = 2;
                    break;
                }
            }

            if(enemy_fighter->getRemainingBleedingRounds() > 0) {
                int bleeding_damage = ceil(enemy.life * 0.05 + (player.attack + attack_buff) * 2);

                this->util->addTextToList(enemy.getEnemyName() + " recebeu " + std::to_string(bleeding_damage) + " de dano de sangramento.");
                this->update();

                enemy_fighter->takeDamage(bleeding_damage);
                enemy_fighter->applyBleeding(-1);

                this->util->addTextToList("Vida restante de " + enemy.getEnemyName() + ": " + std::to_string(enemy_fighter->getRemainingLife()));
                this->update();

                if(enemy_fighter->getRemainingLife() <= 0) {
                    this->util->addTextToList("Voce venceu!!!");
                    this->update();
                    winner = 1;
                    break;
                }
            }

            enemy_fighter->performAttack(*player_fighter, dodges, special_attacks);
            this->update();
            sleep(1);

            this->util->addTextToList("Sua vida restante: " + std::to_string(player_fighter->getRemainingLife()));
            this->update();

            if(player_fighter->getRemainingLife() <= 0) {
                this->util->addTextToList("Voce perdeu...");
                this->update();
                winner = 2;
                break;
            }

            player_fighter->performAttack(*enemy_fighter, dodges, special_attacks);
            this->update();
            sleep(1);

            this->util->addTextToList("Vida restante de " + enemy.getEnemyName() + ": " + std::to_string(enemy_fighter->getRemainingLife()));
            this->update();

            if(enemy_fighter->getRemainingLife() <= 0) {
                this->util->addTextToList("Voce venceu!!!");
                this->update();
                winner = 1;
                break;
            }
        }
        turn++;

        sleep(1);
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
}

Fight::~Fight() {
    delete this->player_fighter;
    delete this->enemy_fighter;
}

int Fight::getWinner() {
    return this->winner;
}

void Fight::renderBackground() {
    if (!backgroundTexture.loadFromFile("../assets/sprites/game-background.png")) {
        std::cout << "ERRO::BACKGROUND::Não foi possível carregar o background do game!" << "\n";
    }

    backgroundSprite.setTexture(backgroundTexture);

    float backgroundWidth = float (backgroundTexture.getSize().x);
    int horizontalTiles = static_cast<int>(std::ceil(float (map_size) / backgroundWidth)) + 1;

    for (int i = 0; i < horizontalTiles; ++i) {
        backgroundSprite.setPosition(float (i) * backgroundWidth, 0);
        this->window.draw(backgroundSprite);
    }
}

void Fight::update() {
    this->window.clear();
    this->renderBackground();
    this->player.update();
    this->player.render(this->window);
    this->enemy.update();
    this->enemy.render(this->window);
    util->renderTexts();
    this->window.display();
}