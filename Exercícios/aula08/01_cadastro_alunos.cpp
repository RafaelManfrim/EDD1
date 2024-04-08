#include <iostream>

using namespace std;

enum Disciplinas {
    Arquitetura,
    POO,
    ED,
    Redes,
    Analise,
    Num_Disciplinas,
};

enum Escolhas {
    Adicionar = 1,
    Visualizar = 2,
    Sair = 3,
};

struct Disciplina {
    string nome;
    double nota;
};

struct Aluno {
    string nome;
    int idade;
    int numero_matricula;
    Disciplina disciplinas[Num_Disciplinas];
};

void cadastrar_aluno(Aluno &aluno) {
    cout << "Digite o nome do aluno: ";
    cin >> aluno.nome;

    cout << "Digite a idade do aluno: ";
    cin >> aluno.idade;

    cout << "Informe o número da matrícula desse aluno: ";
    cin >> aluno.numero_matricula;

    for (int i = 0; i < Num_Disciplinas; i++) {
        Disciplina disciplina;

        switch (i) {
            case Arquitetura:
                disciplina.nome = "Arquitetura";
                break;
            case POO:
                disciplina.nome = "POO";
                break;
            case ED:
                disciplina.nome = "ED";
                break;
            case Redes:
                disciplina.nome = "Redes";
                break;
            case Analise:
                disciplina.nome = "Analise";
                break;
            default:
                continue;
        }

        cout << "Digite a nota de " + disciplina.nome << ": ";
        cin >> disciplina.nota;

        aluno.disciplinas[i] = disciplina;
    }
}

void exibir_aluno(const Aluno &aluno) {
    cout << "Nome do aluno: " << aluno.nome << endl;
    cout << "Idade do aluno: " << aluno.idade << endl;
    cout << "Número de matrícula do aluno: " << aluno.numero_matricula << endl;

    for (int i = 0; i < Num_Disciplinas; i++) {
        cout << "Nota de " << aluno.disciplinas[i].nome << ": " << aluno.disciplinas[i].nota << endl;
    }

    cout << endl;
}

int main() {
    Aluno *alunos;
    int escolha = 0, qdte_alunos = 0;

    while(true) {
        cout << "Menu: " << endl;
        cout << "1. Adicionar aluno" << endl;
        cout << "2. Ver alunos cadastrados" << endl;
        cout << "3. Sair" << endl;
        cout << "Opção: ";
        cin >> escolha;

        Aluno *temp_alunos = new Aluno[qdte_alunos + 1];
        Aluno aluno;

        switch (escolha) {
            case Adicionar:
                for (int j = 0; j < qdte_alunos; j++) {
                    temp_alunos[j] = alunos[j];
                }

                cadastrar_aluno(aluno);

                temp_alunos[qdte_alunos] = aluno;

                delete[] alunos;
                alunos = temp_alunos;

                qdte_alunos++;
                break;

            case Visualizar:
                for(int i = 0; i < qdte_alunos; i++) {
                    cout << "Aluno " << i+1 << ":" << endl;
                    exibir_aluno(alunos[i]);
                }
                break;

            case Sair:
                delete[] alunos;
                return 0;
            default:
                cout << "Escolha uma opção válida!" << endl;
                break;
        }

//        delete[] temp_alunos;
    }
}