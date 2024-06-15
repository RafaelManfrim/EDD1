#include <iostream>

using namespace std;

/*
  Escreva um programa que utilize o vetor anterior e exiba o maior e o menor
valor.
*/

int main() {
    int vetor[10], i, soma = 0, maior = 0, menor;
    cout << "Digite 10 valores" << endl;

    for (i = 0; i < 10; i++) {
        cout << "Digite o " << i + 1 << "º número: ";
        cin >> vetor[i];
    }

    cout << "Os valores armazenados são: " << endl;
    for (i = 0; i < 10; i++) {
        soma += vetor[i];

        if (vetor[i] > maior) {
            maior = vetor[i];
        }

        if (vetor[i] < menor) {
            menor = vetor[i];
        }

        if(i == 9) {
            cout << vetor[i] << endl;
            continue;
        }

        cout << vetor[i] << " - ";
    }

    cout << "A soma de todos os valores é: " << soma << endl;
    cout << "O maior número é: " << maior << endl;
    cout << "O menor número é: " << menor << endl;

    return 0;
}