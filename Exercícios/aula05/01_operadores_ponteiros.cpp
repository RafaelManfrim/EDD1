#include <iostream>

using namespace std;

/*
  Escreva um programa que declare dois inteiros e dois ponteiros para esses
inteiros. Realize soma, subtração, multiplicação, e divisão, entre os inteiros,
usando apenas os seus respectivos ponteiros.
*/

int main() {
    int n1, n2;
    int *p1 = &n1, *p2 = &n2;

    cout << "Informe o primeiro número: ";
    cin >> n1;
    cout << "Informe o segundo número: ";
    cin >> n2;

    cout << "A soma desses números é: " << *p1 + *p2 << endl;
    cout << "A subtração desses números é: " << *p1 - *p2 << endl;
    cout << "A multiplicação desses números é: " << *p1 * *p2 << endl;
    cout << "A divisão desses números é: " << *p1 / *p2 << endl;

    return 0;
}