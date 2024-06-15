#include <iostream>

using namespace std;

/*
  Escreva um programa que solicite ao usuário dois números inteiros e, em
seguida, troque seus valores usando ponteiros.
*/

int main() {
    int n1, n2;
    int *p1 = &n1, *p2 = &n2;

    cout << "Informe o primeiro número: ";
    cin >> n1;
    cout << "Informe o segundo número: ";
    cin >> n2;

    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    cout << "O primeiro número agora é: " << n1 << endl;
    cout << "O segundo número agora é: " << n2 << endl;

    return 0;
}