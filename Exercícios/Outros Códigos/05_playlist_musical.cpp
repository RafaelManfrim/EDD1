#include <iostream>
#include <cstring>
#include <limits>

using namespace std;

struct Musica {
    char* nome;
    int duracao;
};

void listaMusicas(Musica* playlist, int &qtde_musicas) {
    cout << "Quantidade de músicas: " << qtde_musicas << endl;
    for(int i = 0; i < qtde_musicas; i++) {
        cout << "Nome da Musica: " << playlist[i].nome << endl;
        cout << "Duracao: " << playlist[i].duracao << " minutos" << endl;
    }
}

void adicionaMusica(Musica* playlist, int &qtde_musicas, char* nome, int duracao) {
    Musica novaMusica;
    novaMusica.nome = new char[strlen(nome) + 1];
    strcpy(novaMusica.nome, nome);
    novaMusica.duracao = duracao;
    playlist[qtde_musicas++] = novaMusica;
}

void exibirMenu() {
    cout << "=== Menu ===" << endl;
    cout << "1. Adicionar Música" << endl;
    cout << "2. Listar Músicas" << endl;
    cout << "3. Sair" << endl;
    cout << "Sua opção: ";
}

int main() {
    Musica playlist[2];
    int qtde_musicas = 0;
    int opcao;

    while(true) {
        exibirMenu();
        cin >> opcao;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcao) {
            case 1:
                if(qtde_musicas == 2) {
                    cout << "A playlist está cheia!" << endl;
                    continue;
                }

                char nome[101];
                int duracao;
                cout << "Informe o nome da música: ";
                cin.getline(nome, 101);
                cout << "Informe a duração: ";
                cin >> duracao;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                adicionaMusica(playlist, qtde_musicas, nome, duracao);
                break;
            case 2:
                listaMusicas(playlist, qtde_musicas);
                break;
            case 3:
                for (int i = 0; i < qtde_musicas; i++) {
                    delete[] playlist[i].nome;
                }

                cout << "Obrigado por usar nossa playlist!";
                return 0;
            default:
                cout << "Informe uma opção válida!" << endl;
        }
    }
}
