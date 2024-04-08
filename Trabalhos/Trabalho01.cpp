#include <iostream>
#include <random>

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
            life = 3;
            attack = 3;
            defense = 3;
            luck = 1;
            break;
        case Ladrao:
            life = 2;
            attack = 4;
            defense = 1;
            luck = 3;
            break;
        case Arqueiro:
            life = 1;
            attack = 6;
            defense = 1;
            luck = 1;
            break;
        case Berseker:
            life = 4;
            attack = 4;
            defense = 1;
            luck = 1;
            break;
        case Feiticeiro:
            life = 2;
            attack = 3;
            defense = 1;
            luck = 5;
            break;
        case Tanque:
            life = 4;
            attack = 1;
            defense = 4;
            luck = 1;
            break;
        case Cacador:
            life = 1;
            attack = 4;
            defense = 4;
            luck = 1;
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

Character combat(Character &fighter1, Character &fighter2) {
    cout << fighter1.nickname << "(" << character_class_name(fighter1.character_class) << ")";
    cout << " x ";
    cout << fighter2.nickname << "(" << character_class_name(fighter2.character_class) << ")" << endl;

    // Poderá durar no máximo 10 turnos. Se nenhum dos dois personagens forem derrotados ao
    // fim dos 10, o personagem que causou mais dano será considerado o vencedor.

    // O sangramento deve ser calculado no início de cada turno, portanto, um personagem pode ser derrotado
    // sem receber dano de ataque no turno.

    // Caso ambos os personagens fiquem sem vida devido a sangrarem no início do turno, um dos dois
    // personagens será sorteado para avançar e o outro será considerado derrotado.

    // Cada personagem ataca por vez, e será sorteado quem será o primeiro a atacar.

    // Cada personagem atacará uma vez por turno. Ou seja, ambos os personagens atacam em um turno, a não
    // ser que um deles seja derrotado.

    // O ataque especial poderá ocorrer aleatoriamente durante um turno de combate. Ou seja, em vez do ataque normal,
    // ocorrerá o ataque especial. Este ataque causará mais dano do que um ataque normal.

    // O ataque especial também poderá causar sangramento, onde o outro personagem sangrará por um número
    // de turnos calculado aleatoriamente (mínimo de 2 turnos, máximo de 6). O sangramento causará
    // uma perda (pequena) de vida a cada turno, independente do dano recebido no turno.

    // Reduza os pontos de vida do alvo considerando o ATQ de quem
    // ataca, a DEF de quem defende, e um número sorteado (RND) que influenciará neste cálculo.

    // Se um personagem ficar com VID zero ou menos, ele é derrotado e removido do jogo.

    // Ao fim de cada combate seu jogo deve exibir uma tabela com as estatísticas do combate, considerando
    // dano efetuado por cada personagem, vida restante de cada personagem, número de rounds ocorridos, e
    // quantos ataques especiais ocorreram.

    cout << "O personagem " << fighter1.nickname << " venceu!!!" << endl;

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

        if (i != 0) {
            character = create_bot_character(character_names);
        } else {
            character = create_player_character();
        }

        characters[i] = character;
    }

    cout << "\033[1m" << "Personagens do Torneio: " << "\033[0m" << endl << endl;

    list_characters(characters, size);

    Character *round_characters = characters;

    int max_rounds = ceil(log2(size));

    for (int round = 1; round <= max_rounds; round++) {
        cout << endl << "\033[1m" << "Rodada " << round << ":" << "\033[0m" << endl << endl;
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
        }
    }

    delete[] characters;
}

int main(){
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
}
