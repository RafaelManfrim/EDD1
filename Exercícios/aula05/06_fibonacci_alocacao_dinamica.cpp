#include <iostream>

using namespace std;

/*
  Escreva um programa que solicite um número inteiro positivo n ao usuário e
aloque dinamicamente um vetor para armazenar os primeiros n números da
sequência de Fibonacci. Imprima a sequência resultante.
*/

int* fibonacci(int n){
    int *fibonacci_sequence = new int[n];

    fibonacci_sequence[0] = 0;

    if(n == 1) {
        return fibonacci_sequence;
    }

    fibonacci_sequence[1] = 1;

    for (int i = 2; i < n; i++) {
        fibonacci_sequence[i] = fibonacci_sequence[i - 1] + fibonacci_sequence[i - 2];
    }

    return fibonacci_sequence;
}

int main() {
    int qtde_numeros = 0;

    cout << "Informe a quantidade de números da sequência: ";
    cin >> qtde_numeros;

    int *fibonacci_sequence = fibonacci(qtde_numeros);

    cout << "Sequência de Fibonacci com os primeiros " << qtde_numeros << " números:" << endl;
    for (int i = 0; i < qtde_numeros; i++) {
        cout << fibonacci_sequence[i] << " ";
    }

    delete[] fibonacci_sequence;

    return 0;
}