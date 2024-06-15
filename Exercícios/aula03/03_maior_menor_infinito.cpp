/*Escreva um programa que leia um conjunto de valores inteiros e positivos e
determine qual o menor e maior valor do conjunto; a leitura de um valor
negativo encerra a leitura do conjunto, e esse valor n�o ser� considerado.*/

#include <iostream>

using namespace std;

int main() {
    int numero = 0, maior = 0, menor = 0;
    
    cout << "Digite um numero inteiro: ";
    cin >> numero;
    
    if (numero < 0) {
       cout << "O programa foi finalizado sem numeros!" << endl;
       system("Pause");
       return 0;
    }
    
    maior = numero;
    menor = numero;
    
    
    while(true){
        cout << "Digite um numero inteiro: ";
        cin >> numero;

        if (numero < 0) {
           cout << "O menor numero eh: " << menor << " e o maior eh: " << maior << endl;
           system("Pause");
           return 0;
        }

        if (numero > maior){
           maior = numero;
        }

        if (numero < menor) {
           menor = numero;
        }
    }
}
