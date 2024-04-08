#include <iostream>

using namespace std;

/*
  Escreva um programa que inicie com um vetor com 10 valores inteiros e exiba a
média dos valores ímpares. Verifique se há valores ímpares no vetor.
*/

int main() {
    int vetor[10], i, media_impares, soma_impares = 0, qtde_impares = 0;
    cout << "Digite 10 valores" << endl;

    for (i = 0; i < 10; i++) {
        cout << "Digite o " << i + 1 << "º número: ";
        cin >> vetor[i];
    }

    cout << "Os valores armazenados são: " << endl;

    for (i = 0; i < 10; i++) {
        if (vetor[i] % 2 == 1) {
            qtde_impares++;
            soma_impares += vetor[i];
        }

        if(i == 9) {
            cout << vetor[i] << endl;
            continue;
        }

        cout << vetor[i] << " - ";
    }

    if(qtde_impares == 0) {
        cout << "Não há números ímpares!";
        return 0;
    }

    media_impares = soma_impares / qtde_impares;

    cout << "Temos " << qtde_impares << " números ímpares, sua média é: " << media_impares;

    return 0;
}