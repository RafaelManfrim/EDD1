#include <iostream>

using namespace std;

enum Escolhas {
    Adicionar = 1,
    Remover = 2,
    Listar = 3,
    Buscar = 4,
    Sair = 5
};

struct Contato {
    string nome;
    string telefone;
    string email;
};

void exibir_menu() {
    cout << "Menu: " << endl;
    cout << "1. Adicionar contato" << endl;
    cout << "2. Remover contato" << endl;
    cout << "3. Listar contatos" << endl;
    cout << "4. Buscar contato" << endl;
    cout << "5. Sair" << endl;
    cout << "Opção: ";
}

void cadastrar_contato(Contato &contato) {
    cout << "Digite o nome do contato: ";
    cin >> contato.nome;

    cout << "Digite o telefone do contato: ";
    cin >> contato.telefone;

    cout << "Informe o e-mail do contato: ";
    cin >> contato.email;
}

void listar_contatos(const Contato &contatos, int &qtde_contatos) {
    for(int i = 0; i < qtde_contatos; i++) {
        cout << "Aluno " << i+1 << ":" << endl;
        exibir_contato(contatos[i]);
    }
}

void exibir_contato(const Contato &contato) {
    cout << "Nome do contato: " << contato.nome << endl;
    cout << "Telefone do contato: " << contato.telefone << endl;
    cout << "E-mail do contato: " << contato.email << endl;
    cout << endl;
}

void buscar_contato() {
    exibir_contato();
}

int main() {
    Contato *contatos;
    int escolha = 0, qtde_contatos = 0;

    while(true) {
        exibir_menu();
        cin >> escolha;

        Contato *temp_contatos = new Contato[qtde_contatos + 1];
        Contato contato;

        switch (escolha) {
            case Adicionar:
                for (int j = 0; j < qtde_contatos; j++) {
                    temp_contatos[j] = contatos[j];
                }

                cadastrar_contato(contato);

                temp_contatos[qtde_contatos] = contato;

                delete[] contatos;
                contatos = temp_contatos;

                qtde_contatos++;
                break;
            case Remover:
                break;
            case Listar:
                listar_contatos(*contatos, qtde_contatos);
                break;
            case Buscar:
                break;
            case Sair:
                delete[] contatos;
                return 0;
                break;
            default:
                cout << "Escolha uma opção válida!" << endl;
                break;
        }
    }
}