#include <iostream>
#include <string>

using namespace std;

/*
  Escreva um programa que solicite ao usuário uma string e imprima essa string
verticalmente. Use o objeto string de C++. Precisa obrigatoriamente usar um
ponteiro para obter o endereço da variável de tipo String e utilizá-lo para fazer a
impressão.
*/

int main() {
    string palavra;
    cout << "Digite uma palavra: ";
    cin >> palavra;

    char *ptr = &palavra[0];

    while (*ptr != '\0') {
        cout << *ptr << endl;
        ptr++;
    }

    return 0;
}