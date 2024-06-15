#include <iostream>

using namespace std;

/*
  Escreva um programa que solicite 10 valores inteiros do usuário e armazene-os
em um vetor.
*/

int main() {
  int vetor[10], i;
  cout << "Digite 10 valores" << endl;

  for (i = 0; i < 10; i++) {
    cout << "Digite o " << i + 1 << "º número: ";
    cin >> vetor[i];
  }

  cout << "Os valores armazenados são: " << endl;
  for (i = 0; i < 10; i++) {
    if(i == 9) {
      cout << vetor[i];
      continue;
    }

    cout << vetor[i] << " - ";
  }

  return 0;
}