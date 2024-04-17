#include <iostream>

using namespace std;

enum Opcoes {
    CadastrarFuncionario = 1,
    CalcularMediaSalarialEquipe = 2,
    ListarFuncionarios = 3,
    Sair = 4
};

struct Funcionario {
    string nome;
    string cargo;
    float salario;
    string data_contratacao;
};

void cadastrar_funcionario(Funcionario* &funcionarios, int &qtde_funcionarios) {
    string nome, cargo, data_contratacao;
    float salario;

    cout << "Informe o nome do novo funcionário: ";
    cin >> nome;

    cout << "Informe o cargo: ";
    cin >> cargo;

    cout << "Informe o salário: ";
    cin >> salario;

    cout << "Informe a data da contratação: ";
    cin >> data_contratacao;

    Funcionario *temp_funcionarios = new Funcionario[qtde_funcionarios + 1];

    Funcionario funcionario;
    funcionario.nome = nome;
    funcionario.cargo = cargo;
    funcionario.salario = salario;
    funcionario.data_contratacao = data_contratacao;

    for (int i = 0; i < qtde_funcionarios; i++) {
        temp_funcionarios[i] = funcionarios[i];
    }

    temp_funcionarios[qtde_funcionarios++] = funcionario;

    delete[] funcionarios;
    funcionarios = temp_funcionarios;
}

void calcular_media_salarial_equipe(Funcionario* &funcionarios, int &qtde_funcionarios) {
    float soma_salarios = 0;

    for(int i = 0; i < qtde_funcionarios; i++) {
        soma_salarios += funcionarios[i].salario;
    }

    float media_salarial = soma_salarios / qtde_funcionarios;

    cout << "A média salarial da equipe é: " << media_salarial << endl;
}

void listar_funcionarios(Funcionario* &funcionarios, int &qtde_funcionarios) {
    for(int i = 0; i < qtde_funcionarios; i++) {
        cout << funcionarios[i].nome << " - " << funcionarios[i].cargo << endl;
        cout << "Salário: " << funcionarios[i].salario << endl;
        cout << "Data da Contratação: " << funcionarios[i].data_contratacao << endl;

        cout << endl;
    }
}

void exibir_menu() {
    cout << "======= Menu =======" << endl;
    cout << "1. Cadastrar Funcionário" << endl;
    cout << "2. Calcular Média Salarial da Equipe" << endl;
    cout << "3. Listar Funcionários" << endl;
    cout << "4. Sair" << endl;
    cout << "Opção: ";
}

int main() {
    Funcionario *funcionarios = nullptr;
    int opcao, qtde_funcionarios = 0;

    while(true) {
        exibir_menu();
        cin >> opcao;
        cout << endl;

        switch(opcao) {
            case CadastrarFuncionario:
                cadastrar_funcionario(funcionarios, qtde_funcionarios);
                cout << endl;
                break;
            case CalcularMediaSalarialEquipe:
                calcular_media_salarial_equipe(funcionarios, qtde_funcionarios);
                cout << endl;
                break;
            case ListarFuncionarios:
                listar_funcionarios(funcionarios, qtde_funcionarios);
                break;
            case Sair:
                cout << "Obrigado por usar a aplicação!";
                return 0;
            default:
                cout << "Selecione uma opção válida!" << endl << endl;
                break;
        }
    }
}
