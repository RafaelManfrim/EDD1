#include <iostream>

using namespace std;

/*
  Escreva um programa que solicite ao usuário o tamanho de um vetor de inteiros
e, em seguida, aloque dinamicamente memória para o vetor. Peça ao usuário
para inserir os elementos e calcule a soma deles.
*/

int main() {
   int tamanho, i, soma = 0;
   cout << "Informe o tamanho do vetor: ";
   cin >> tamanho;

   if(tamanho <= 0) {
       cout << "O tamanho do vetor precisa ser maior que 0!";
       return 0;
   }

   int *vetor = new int[tamanho];

   for (i = 0; i < tamanho; i++) {
       cout << "Informe o " << i + 1 << "º valor: ";
       cin >> vetor[i];
       soma += vetor[i];
   }

   cout << "A soma dos números é: " << soma;

   return 0;
}