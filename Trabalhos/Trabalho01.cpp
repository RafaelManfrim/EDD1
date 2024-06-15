#include <iostream>
#include <random>
#include <locale>
#include <unistd.h>
//#headers <fstream>

#ifdef _WIN32
#headers <windows.h>
#endif

using namespace std;

#define MAX_NAMES_PER_CLASS 5

enum Classes {
    Guerreiro,
    Ladrao,
    Arqueiro,
    Berseker,
    Feiticeiro,
    Tanque,
    Cacador,
    Necromante,
    NUMBER_OF_CLASSES
};

struct Character {
    string nickname;
    int character_class;
    int life;
    int attack;
    int defense;
    int luck;
    string special_attack;
    Character *defeated_characters;
    int num_defeated_characters;
};

struct StackName {
    string name;
    StackName* next_name;
};

struct NamesStack {
    StackName* top_name;
};

bool is_names_stack_empty(NamesStack* stack) {
    return stack->top_name == nullptr;
}

string get_name_from_stack(NamesStack* stack) {
    StackName* temp = stack->top_name;
    string popped_value = stack->top_name->name;
    stack->top_name = stack->top_name->next_name;

    delete temp;

    return popped_value;
}

string character_class_name(int &class_id) {
    switch(class_id) {
        case Guerreiro:
            return "Guerreiro";
        case Ladrao:
            return "Ladrão";
        case Arqueiro:
            return "Arqueiro";
        case Berseker:
            return "Berseker";
        case Feiticeiro:
            return "Feiticeiro";
        case Tanque:
            return "Tanque";
        case Cacador:
            return "Caçador";
        case Necromante:
            return "Necromante";
        default:
            return "-";
    }
}

void display_character_statistics(Character &character) {
    cout << "Nome: " << character.nickname << endl;
    cout << "Classe: " << character_class_name(character.character_class) << endl;

    cout << "Vida: " << character.life << " | Ataque: " << character.attack;
    cout << " | Defesa: " << character.defense << " | Sorte: " << character.luck << endl;

    cout << "Ataque Especial: " << character.special_attack << endl;

    if(character.num_defeated_characters > 0) {
        cout << "Personagens Derrotados: " << endl;

        for (int i = 0; i < character.num_defeated_characters; i++) {
            cout << character.defeated_characters[i].nickname << "("
                 << character_class_name(character.defeated_characters[i].character_class) << ")";
            cout << endl;
        }
    }
}

Character create_character(string &nickname, int &character_class, int &life, int &attack, int &defense, int &luck) {
    Character new_character;
    new_character.nickname = nickname;
    new_character.character_class = character_class;
    new_character.life = life;
    new_character.attack = attack;
    new_character.defense = defense;
    new_character.luck = luck;

    switch(character_class) {
        case Guerreiro:
            new_character.special_attack = "Fúria dos Titãs";
            break;
        case Ladrao:
            new_character.special_attack = "Emboscada Sinistra";
            break;
        case Arqueiro:
            new_character.special_attack = "Flecha mortal";
            break;
        case Berseker:
            new_character.special_attack = "Tormenta Voraz";
            break;
        case Feiticeiro:
            new_character.special_attack = "Labaredas Infernais";
            break;
        case Tanque:
            new_character.special_attack = "Martelo da Carnificina";
            break;
        case Cacador:
            new_character.special_attack = "Golpe do Predador";
            break;
        case Necromante:
            new_character.special_attack = "Explosão de Almas";
            break;
        default:
            new_character.special_attack = "Ataque Especial";
            break;
    }

    new_character.defeated_characters = nullptr;
    new_character.num_defeated_characters = 0;

    return new_character;
}

Character create_player_character() {
    string nickname;
    cout << "Informe o nome do seu personagem: ";
    cin >> nickname;

    int character_class;
    bool is_valid_class = false;

    while(!is_valid_class) {
        cout << "Escolha sua classe: " << endl;
        cout << "1. Guerreiro" << endl;
        cout << "2. Ladrão" << endl;
        cout << "3. Arqueiro" << endl;
        cout << "4. Berseker" << endl;
        cout << "5. Feiticeiro" << endl;
        cout << "6. Tanque" << endl;
        cout << "7. Cacador" << endl;
        cout << "8. Necromante" << endl;
        cout << "A opção desejada é: ";
        cin >> character_class;

        switch (character_class) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
                is_valid_class = true;
                break;
            default:
                cout << "Informe uma classe válida!" << endl;
                break;
        }
    }

    int life = 0, attack = 0, defense = 0, luck = 0, remaining_points = 10, input;

    cout << endl << "Você tem 10 pontos para distribuir entre Vida, Ataque, Defesa e Sorte!" << endl;

    while(true) {
        cout << "Vida: ";
        cin >> input;

        if(input <= remaining_points && input >= 0) {
            life = input;
            remaining_points -= life;
            break;
        } else {
            cout << "Esse número é maior do que os pontos que você tem disponíveis, insira outro valor!" << endl;
        }
    }

    cout << "Você ainda tem " << remaining_points << " restantes!" << endl;

    while(true) {
        cout << "Ataque: ";
        cin >> input;

        if(input <= remaining_points && input >= 0) {
            attack = input;
            remaining_points -= attack;
            break;
        } else {
            cout << "Esse número é maior do que os pontos que você tem disponíveis, insira outro valor!" << endl;
        }
    }

    cout << "Você ainda tem " << remaining_points << " restantes!" << endl;

    while(true) {
        cout << "Defesa: ";
        cin >> input;

        if(input <= remaining_points && input >= 0) {
            defense = input;
            remaining_points -= defense;
            break;
        } else {
            cout << "Esse número é maior do que os pontos que você tem disponíveis, insira outro valor!" << endl;
        }
    }

    cout << "Você ainda tem " << remaining_points << " restantes!" << endl;

    while(true) {
        cout << "Sorte: ";
        cin >> input;

        if(input <= remaining_points && input >= 0) {
            luck = input;
            remaining_points -= luck;
            break;
        } else {
            cout << "Esse número é maior do que os pontos que você tem disponíveis, insira outro valor!" << endl;
        }
    }

    cout << endl;

    character_class -= 1;

    return create_character(
        nickname,
        character_class,
        life,
        attack,
        defense,
        luck
    );
}

Character create_bot_character(NamesStack (&character_names)[NUMBER_OF_CLASSES]) {
    random_device generator;
    uniform_int_distribution<int> available_classes(0,NUMBER_OF_CLASSES - 1);
    int class_id_draw = available_classes(generator);
    string name_draw;

    int counter = 0;

    while(true) {
        if(counter == 0 && !is_names_stack_empty(&character_names[class_id_draw])) {
            name_draw = get_name_from_stack(&character_names[class_id_draw]);
            break;
        }

        int random_stack = available_classes(generator);

        if(!is_names_stack_empty(&character_names[random_stack])) {
            name_draw = get_name_from_stack(&character_names[random_stack]);
            break;
        }

         if (counter >= 2) {
             int class_id_incremental = 0;

             while(true) {
                   if(!is_names_stack_empty(&character_names[class_id_incremental])) {
                       name_draw = get_name_from_stack(&character_names[class_id_incremental]);
                       break;
                   }

                 class_id_incremental++;
             }

             break;
         }

        counter++;
    }

    int life = 0, attack = 0, defense = 0, luck = 0;

    switch (class_id_draw) {
        case Guerreiro:
            life = 2;
            attack = 3;
            defense = 3;
            luck = 2;
            break;
        case Ladrao:
            life = 2;
            attack = 5;
            defense = 1;
            luck = 2;
            break;
        case Arqueiro:
            life = 1;
            attack = 6;
            defense = 1;
            luck = 1;
            break;
        case Berseker:
            life = 3;
            attack = 5;
            defense = 1;
            luck = 1;
            break;
        case Feiticeiro:
            life = 3;
            attack = 4;
            defense = 1;
            luck = 2;
            break;
        case Tanque:
            life = 4;
            attack = 1;
            defense = 4;
            luck = 1;
            break;
        case Cacador:
            life = 1;
            attack = 3;
            defense = 4;
            luck = 2;
            break;
        case Necromante:
            life = 5;
            attack = 3;
            defense = 1;
            luck = 1;
            break;
        default:
            break;
    }

    return create_character(name_draw, class_id_draw, life, attack, defense, luck);
}

void list_characters(Character* &characters, int &number_of_characters) {
    for(int i = 0; i < number_of_characters; i++) {
        cout << "Personagem " << i + 1 << ":" << endl;
        display_character_statistics(characters[i]);
        cout << endl;
    }
}

void calculaProbabilidadeDanoRandomico(Character &atacante, int &a, int &b) {
    switch(atacante.luck) {
        case 0:
            a = 7;
            b = 14;
            break;
        case 1:
            a = 8;
            b = 14;
            break;
        case 2:
            a = 8;
            b = 15;
            break;
        case 3:
            a = 9;
            b = 15;
            break;
        case 4:
            a = 9;
            b = 16;
            break;
        case 5:
            a = 10;
            b = 16;
            break;
        case 6:
            a = 10;
            b = 17;
            break;
        case 7:
            a = 11;
            b = 17;
            break;
        case 8:
            a = 11;
            b = 18;
            break;
        case 9:
            a = 12;
            b = 18;
            break;
        case 10:
            a = 12;
            b = 19;
            break;
        default:
            a = 7;
            b = 17;
            break;
    }
}

void calculaProbabilidadeAtaqueEspecial(Character &atacante, int &a, int &b) {
    switch(atacante.luck) {
        case 0:
            a = 0;
            b = 14;
            break;
        case 1:
            a = 0;
            b = 13;
            break;
        case 2:
            a = 0;
            b = 12;
            break;
        case 3:
            a = 0;
            b = 11;
            break;
        case 4:
            a = 0;
            b = 10;
            break;
        case 5:
            a = 0;
            b = 9;
            break;
        case 6:
            a = 0;
            b = 8;
            break;
        case 7:
            a = 0;
            b = 7;
            break;
        case 8:
            a = 0;
            b = 6;
            break;
        case 9:
            a = 0;
            b = 5;
            break;
        case 10:
            a = 0;
            b = 4;
            break;
        default:
            a = 0;
            b = 15;
            break;
    }
}

void calculaProbabilidadeDesvio(Character &defensor, int &a, int &b) {
    switch(defensor.luck) {
        case 0:
            a = 0;
            b = 14;
            break;
        case 1:
            a = 0;
            b = 13;
            break;
        case 2:
            a = 0;
            b = 12;
            break;
        case 3:
            a = 0;
            b = 11;
            break;
        case 4:
            a = 0;
            b = 10;
            break;
        case 5:
            a = 0;
            b = 9;
            break;
        case 6:
            a = 0;
            b = 8;
            break;
        case 7:
            a = 0;
            b = 7;
            break;
        case 8:
            a = 0;
            b = 6;
            break;
        case 9:
            a = 0;
            b = 5;
            break;
        case 10:
            a = 0;
            b = 4;
            break;
        default:
            a = 0;
            b = 15;
            break;
    }

    if (defensor.character_class == Arqueiro) { // Medida para maior balanceamento
        b -= 3;
    }
}

void ataque(
    Character &atacante,
    Character &defensor,
    int &danoAtacante,
    int &vidaDefensor,
    int &qtdeAtaqueEspecial,
    int &qtdeEsquivas,
    int &tempoSangramentoDefensor
    ) {
    random_device generator;
    int a, b;

    calculaProbabilidadeDesvio(defensor, a, b);
    uniform_int_distribution<int> Possib_desvio(a,b);
    int desvioOcorre = Possib_desvio(generator);
    if(desvioOcorre == 0) {
        qtdeEsquivas++;
        cout << atacante.nickname << " ataca: " << endl << defensor.nickname << " desviou..." << endl;
        sleep(1);
        return;
    }

    calculaProbabilidadeDanoRandomico(atacante, a, b);
    uniform_int_distribution<int> Possib_danoRandomico(a,b);
    int DanoRandomico = Possib_danoRandomico(generator);
    int danoAtaque = 15 + atacante.attack * 5 - defensor.defense * 5 + DanoRandomico;

    if(defensor.character_class == Tanque) { // Regra para balancear
        danoAtaque -= 1;
    } else if(defensor.character_class == Berseker) {
        danoAtaque += 2;
    }

    calculaProbabilidadeAtaqueEspecial(atacante, a, b);
    uniform_int_distribution<int> Possib_ataqueEspecial(a,b);
    int ataqueEspecialOcorre = Possib_ataqueEspecial(generator);

    if(ataqueEspecialOcorre == 0) {
        qtdeAtaqueEspecial++;
        cout << atacante.nickname << " está usando o ataque " << atacante.special_attack << endl;
        sleep(1);
        danoAtaque = ceil(danoAtaque + danoAtaque * 0.4);

        uniform_int_distribution<int> Possib_sangramento(0,2);
        int resultadoSangramento = Possib_sangramento(generator);
        if(resultadoSangramento == 0) {
            uniform_int_distribution<int> Possib_TurnoSangramento(2,6);
            int turnoSangramento = Possib_TurnoSangramento(generator);
            cout << "O ataque especial causou sangramento de: " << turnoSangramento << " turnos" << endl;
            sleep(1);
            tempoSangramentoDefensor += turnoSangramento;
        }
    } else {
        cout << atacante.nickname << " ataca: " << endl;
        sleep(1);
    }

    vidaDefensor -= danoAtaque;
    danoAtacante += danoAtaque;
}

Character combat(Character &fighter1, Character &fighter2) {
    cout << fighter1.nickname << "(" << character_class_name(fighter1.character_class) << ")";
    cout << " x ";
    cout << fighter2.nickname << "(" << character_class_name(fighter2.character_class) << ")" << endl;

    random_device generator;
    uniform_int_distribution<int> ataquePersonagem(1,2);

    int turno = 1;
    int danoPersonagem1 = 0, danoPersonagem2 = 0;
    int vidaPersonagem1 = 100 + fighter1.life * 20, vidaPersonagem2 = 100 + fighter2.life * 20;
    int tempoSangramentoPersonagem1 = 0, tempoSangramentoPersonagem2 = 0;
    int qtdeEsquivas = 0, qtdeAtaqueEspecial = 0;
    int personagemVitorioso = 0;
    while (turno <= 10){
        cout << "Turno " << turno << " --------------------------- " << endl;
        int personagem_atacar = ataquePersonagem(generator);
        if(personagem_atacar == 1) {
            if(tempoSangramentoPersonagem2 > 0) {
                int danoSangramento = ceil(vidaPersonagem2 * 0.05 + fighter1.attack * 2);
                cout << fighter2.nickname << " recebeu " << danoSangramento << " de dano de sangramento." << endl;
                sleep(1);
                vidaPersonagem2 -= danoSangramento;
                tempoSangramentoPersonagem2--;

                cout << "Vida restante de " << fighter2.nickname << ": " << vidaPersonagem2 << endl;

                if(vidaPersonagem2 <= 0) {
                    cout << fighter1.nickname << " venceu!!!" << endl;
                    sleep(1);
                    personagemVitorioso = 1;
                    break;
                }
            } else if(tempoSangramentoPersonagem1 > 0) {
                int danoSangramento = ceil(vidaPersonagem1 * 0.05 + fighter2.attack * 2);
                cout << fighter1.nickname << " recebeu " << danoSangramento << " de dano de sangramento." << endl;
                sleep(1);
                vidaPersonagem1 -= danoSangramento;
                tempoSangramentoPersonagem1--;

                cout << "Vida restante de " << fighter1.nickname << ": " << vidaPersonagem1 << endl;

                if(vidaPersonagem1 <= 0) {
                    cout << fighter2.nickname << " venceu!!!" << endl;
                    sleep(1);
                    personagemVitorioso = 2;
                    break;
                }
            }

            ataque(
                fighter1,
                fighter2,
                danoPersonagem1,
                vidaPersonagem2,
                qtdeAtaqueEspecial,
                qtdeEsquivas,
                tempoSangramentoPersonagem2
                );

            cout << "Vida restante de " << fighter2.nickname << ": " << vidaPersonagem2 << endl;

            if(vidaPersonagem2 <= 0) {
                cout << fighter1.nickname << " venceu!!!" << endl;
                sleep(1);
                personagemVitorioso = 1;
                break;
            }

            ataque(
                fighter2,
                fighter1,
                danoPersonagem2,
                vidaPersonagem1,
                qtdeAtaqueEspecial,
                qtdeEsquivas,
                tempoSangramentoPersonagem1
                );

            cout << "Vida restante de " << fighter1.nickname << ": " << vidaPersonagem1 << endl;

            if(vidaPersonagem1 <= 0) {
                cout << fighter2.nickname << " venceu!!!" << endl;
                sleep(1);
                personagemVitorioso = 2;
                break;
            }
        } else if(personagem_atacar == 2) {
            if(tempoSangramentoPersonagem1 > 0) {
                int danoSangramento = ceil(vidaPersonagem1 * 0.05 + fighter2.attack * 2);
                cout << fighter1.nickname << " recebeu " << danoSangramento << " de dano de sangramento." << endl;
                sleep(1);
                vidaPersonagem1 -= danoSangramento;
                tempoSangramentoPersonagem1--;

                cout << "Vida restante de " << fighter1.nickname << ": " << vidaPersonagem1 << endl;

                if(vidaPersonagem1 <= 0) {
                    cout << fighter2.nickname << " venceu!!!" << endl;
                    sleep(1);
                    personagemVitorioso = 2;
                    break;
                }

            } else if(tempoSangramentoPersonagem2 > 0) {
                int danoSangramento = ceil(vidaPersonagem2 * 0.05 + fighter1.attack * 2);
                cout << "O personagem " << fighter2.nickname << " recebeu " << danoSangramento << " de dano de sangramento." << endl;
                sleep(1);
                vidaPersonagem2 -= danoSangramento;
                tempoSangramentoPersonagem2--;

                cout << "Vida restante de " << fighter2.nickname << ": " << vidaPersonagem2 << endl;

                if(vidaPersonagem2 <= 0) {
                    cout << fighter1.nickname << " venceu!!!" << endl;
                    sleep(1);
                    personagemVitorioso = 1;
                    break;
                }
            }


            ataque(
                fighter2,
                fighter1,
                danoPersonagem2,
                vidaPersonagem1,
                qtdeAtaqueEspecial,
                qtdeEsquivas,
                tempoSangramentoPersonagem1
                );

            cout << "Vida restante de " << fighter1.nickname << ": " << vidaPersonagem1 << endl;

            if(vidaPersonagem1 <= 0) {
                cout << fighter2.nickname << " venceu!!!" << endl;
                sleep(1);
                personagemVitorioso = 2;
                break;
            }

            ataque(
                fighter1,
                fighter2,
                danoPersonagem1,
                vidaPersonagem2,
                qtdeAtaqueEspecial,
                qtdeEsquivas,
                tempoSangramentoPersonagem2
                );

            cout << "Vida restante de " << fighter2.nickname << ": " << vidaPersonagem2 << endl;

            if(vidaPersonagem2 <= 0) {
                cout << fighter1.nickname << " venceu!!!" << endl;
                sleep(1);
                personagemVitorioso = 1;
                break;
            }
        }
        turno++;
    }

    if(vidaPersonagem1 > 0 && vidaPersonagem2 > 0) {
        if(danoPersonagem1 > danoPersonagem2) {
            personagemVitorioso = 1;
        }

        personagemVitorioso = 2;
    }
    cout << endl;

    cout << "Dano " << fighter1.nickname << ": " << danoPersonagem1 << endl;
    cout << "Dano " << fighter2.nickname << ": " << danoPersonagem2 << endl;
    cout << "Vida restante " << fighter1.nickname << ": " << vidaPersonagem1 << endl;
    cout << "Vida restante " << fighter2.nickname << ": " << vidaPersonagem2 << endl;
    cout << "Turnos ocorridos: " << turno << endl;
    cout << "Quantidade de ataques especiais: " << qtdeAtaqueEspecial << endl;
    cout << "Quantidade de esquivas: " << qtdeEsquivas << endl << endl;

    if(personagemVitorioso == 1) {
        Character *temp = new Character[fighter1.num_defeated_characters + 1];

        for (int i = 0; i < fighter1.num_defeated_characters; i++) {
            temp[i] = fighter1.defeated_characters[i];
        }

        temp[fighter1.num_defeated_characters] = fighter2;
        delete[] fighter1.defeated_characters;
        fighter1.defeated_characters = temp;
        fighter1.num_defeated_characters++;

        return fighter1;
    }

    Character *temp = new Character[fighter2.num_defeated_characters + 1];

    for (int i = 0; i < fighter2.num_defeated_characters; i++) {
        temp[i] = fighter2.defeated_characters[i];
    }

    temp[fighter2.num_defeated_characters] = fighter1;
    delete[] fighter2.defeated_characters;
    fighter2.defeated_characters = temp;
    fighter2.num_defeated_characters++;

    return fighter2;
}

void create_tournament(int size) {
    string initial_names[NUMBER_OF_CLASSES][MAX_NAMES_PER_CLASS] = {
    {"Ragnar Blacksteel", "Valeria Ironheart", "Thane Stonehammer", "Sif Thunderblade", "Aldric Bloodfist"},
    {"Talia Shadowcloak", "Remy Nightshade", "Kieran Swiftfoot", "Lyra Whisperwind", "Darius Blackthorn"},
    {"Elara Sunshot", "Orion Frostwind", "Nia Starfall", "Finn Hawkeye", "Bryn Oakenshade"},
    {"Gromm Firebeard", "Kaida Bloodrage", "Draven Skullcrusher", "Helga Thunderfury", "Bjorn Ironclaw"},
    {"Alaric Shadowcaster", "Selene Moonspell", "Lucian Darkflame", "Isolde Frostbloom", "Thalia Stormcaller"},
    {"Braddock Stoneguard", "Ursa Ironhide", "Thorin Boulderfist", "Kaela Steelwall", "Grimgar Shieldbreaker"},
    {"Asher Windrunner", "Lyra Wildheart", "Dante Shadowstalk", "Freya Frostfang", "Orion Swiftblade"},
    {"Mordecai Darkhand", "Lilith Bloodgrave", "Xander Deathbringer", "Evelynn Bonecaller", "Theron Grimshadow"}
    };

    int i, j;
    NamesStack character_names[NUMBER_OF_CLASSES];

    random_device generator;

    for (i = 0; i < NUMBER_OF_CLASSES; i++) {
        character_names[i].top_name = nullptr;

        int positions[] = {0, 1, 2, 3, 4};

        for (int k = MAX_NAMES_PER_CLASS - 1; k > 0; k--) {
            uniform_int_distribution<int> available_positions(0,k);
            int l = available_positions(generator);
            int temp = positions[k];
            positions[k] = positions[l];
            positions[l] = temp;
        }

        for (j = 0; j < MAX_NAMES_PER_CLASS; ++j) {
            StackName* new_stack_name = new StackName();
            new_stack_name->name = initial_names[i][positions[j]];
            new_stack_name->next_name = character_names[i].top_name;
            character_names[i].top_name = new_stack_name;
        }
    }

    Character *characters = new Character[size];

    for(i = 0; i < size; i++) {
        Character character;

//        CÓDIGO PARA AVALIAÇÃO DO BALANCEAMENTO
//        character = create_bot_character(character_names);

        if (i != 0) {
            character = create_bot_character(character_names);
        } else {
            character = create_player_character();
        }

        characters[i] = character;
    }

    cout << "Personagens do Torneio: " << endl << endl;

    list_characters(characters, size);

    Character *round_characters = characters;

    int max_rounds = ceil(log2(size));

    for (int round = 1; round <= max_rounds; round++) {
        cout << endl << "========================= Rodada " << round << " ========================= " << endl << endl << endl;
        int current_round_size = size / static_cast<int>(pow(2, round - 1));
        int next_round_size = size / static_cast<int>(pow(2, round));

        bool is_last_round = round == max_rounds;

        if(!is_last_round) {
            Character *next_round_characters = new Character[next_round_size];

            int next_round_counter = 0;

            for (int k = 0; k < current_round_size; k+=2) {
                next_round_characters[next_round_counter++] = combat(round_characters[k], round_characters[k + 1]);
            }

            round_characters = next_round_characters;
        } else {
            Character tournament_winner = combat(round_characters[0], round_characters[1]);

            cout << endl << endl << "O vencedor do torneio foi: " << endl;
            display_character_statistics(tournament_winner);

// CÓDIGO PARA AVALIAÇÃO DO BALANCEAMENTO
//            string filename = to_string(size) + ".txt";
//            std::ofstream arquivo(filename, std::ios_base::app);
//
//            if (arquivo.is_open()) {
//                arquivo << character_class_name(tournament_winner.character_class) << endl;
//                arquivo.close();
//            }
        }
    }

    delete[] characters;
}

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif

    int tournament_size = 0;

    while(true) {
        cout << "Informe o tamanho do Torneiro RPG desejado (8, 16 ou 32): ";
        cin >> tournament_size;

        if(tournament_size == 32 || tournament_size == 16 || tournament_size == 8) {
            create_tournament(tournament_size);

            return 0;
        } else {
            cout << "Informe um tamanho válido!" << endl;
        }
    }

// CÓDIGO PARA AVALIAÇÃO DO BALANCEAMENTO
//    for(int i = 8; i <= 32; i+=8){
//        for (int j = 1; j <= 15000; j++) {
//            if(i != 24) {
//                create_tournament(i);
//            }
//        }
//    }
}
