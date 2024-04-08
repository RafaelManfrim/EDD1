#include <iostream>

using namespace std;

/*
  Escreva um programa que leia um número indeterminado de notas de alunos até
que seja inserido um valor negativo. Use alocação dinâmica para armazenar as
notas em um vetor e, em seguida, calcule a média.
*/

int main() {
   float *notas;
   int qtde_notas = 0;
   float nota, soma_notas = 0;

   while(true) {
       cout << "Digite o valor da " << qtde_notas + 1 << "ª nota: ";
       cin >> nota;

       if(nota < 0) {
           float media = soma_notas / (float) qtde_notas;
           cout << "A média das notas é: " << media;

           return 0;
       }

       float *temp_notas = new float[qtde_notas + 1];

       for (int i = 0; i < qtde_notas; i++) {
           temp_notas[i] = notas[i];
       }

       temp_notas[qtde_notas] = nota;

       delete[] notas;
       notas = temp_notas;

       soma_notas += nota;
       qtde_notas++;

   }
}