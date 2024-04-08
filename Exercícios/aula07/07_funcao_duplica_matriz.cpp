#include <iostream>

using namespace std;

int colunas = 4;
int linhas = 5;

void duplica_valores_matriz(int **matriz) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] *= 2;
        }
    }
}

int main() {
    int **matriz = new int*[linhas];
    for (int i = 0; i < linhas; i++)
        matriz[i] = new int[colunas];
    cout << endl;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = i * 2 + j;
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    duplica_valores_matriz(matriz);

    cout << endl;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < linhas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
    return 0;
}