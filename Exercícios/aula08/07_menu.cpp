#include <iostream>

using namespace std;

enum Opcoes {
    VisualizarPerfil = 1,
    EditarConfiguracoes = 2,
    Sair = 3
};

void exibir_menu() {
    cout << "==== Menu ====" << endl;
    cout << "1. Visualizar Perfil" << endl;
    cout << "2. Editar Configurações" << endl;
    cout << "3. Sair" << endl;
    cout << "Sua opção desejada: ";
}

int main() {
    int opcao;
    while(true) {
        exibir_menu();
        cin >> opcao;

        switch (opcao) {
            case VisualizarPerfil:
                cout << "Visualizando Perfil!";
                break;
            case EditarConfiguracoes:
                cout << "Editando Configurações!";
                break;
            case Sair:
                cout << "Saindo...";
                return 0;
            default:
                cout << "Digite uma opção válida!";
        }

        cout << endl << endl;
    }
}
