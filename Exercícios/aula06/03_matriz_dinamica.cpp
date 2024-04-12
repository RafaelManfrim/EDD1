#include <iostream>
#include <random>

using namespace std;

int main() {
    int linhas, colunas, profundidade;

    cout << "Vamos criar uma Matriz Alocada Dinâmicamente de 3 Dimensões!" << endl;
    cout << "Informe o número de linhas: ";
    cin >> linhas;
    cout << "Informe o número de colunas: ";
    cin >> colunas;
    cout << "Informe a profundidade: ";
    cin >> profundidade;

    int i, j, k;
    int ***matriz = new int**[linhas];

    for (i = 0; i < linhas; i++) {
        matriz[i] = new int*[colunas];

        for(j = 0; j < colunas; j++) {
            matriz[i][j] = new int[profundidade];
        }
    }

    cout << endl << "A matriz está sendo preenchida!" << endl;

    random_device generator;
    uniform_int_distribution<int> available_positions(0,255);

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            for (k = 0; k < profundidade; k++) {
                matriz[i][j][k] = available_positions(generator);
            }
        }
    }

    cout << endl << "Valores da Matriz: " << endl;

    for (i = 0; i < linhas; i++) {
        cout << "Linha " << i + 1 << endl;

        for (j = 0; j < colunas; j++) {
            cout << "Coluna " << j + 1 << ": " << endl;

            for (k = 0; k < profundidade; k++) {
                cout << "Profundidade " << k + 1 << ": " << matriz[i][j][k] << endl;
            }
        }
    }

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            delete[] matriz[i][j];
        }
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}
