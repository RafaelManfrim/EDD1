#include <iostream>

using namespace std;

/*
  Escreva um programa que utilize o vetor anterior e calcule a soma de todos os
seus elementos.
*/

int main() {
    int vetor[10], i, soma = 0;
    cout << "Digite 10 valores" << endl;

    for (i = 0; i < 10; i++) {
        cout << "Digite o " << i + 1 << "º número: ";
        cin >> vetor[i];
    }

    cout << "Os valores armazenados são: " << endl;
    for (i = 0; i < 10; i++) {
        soma += vetor[i];

        if(i == 9) {
            cout << vetor[i] << endl;
            continue;
        }

        cout << vetor[i] << " - ";
    }

    cout << "A soma de todos os valores é: " << soma;

    return 0;
}