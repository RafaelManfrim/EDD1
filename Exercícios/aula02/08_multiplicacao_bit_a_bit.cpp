#include <iostream>

using namespace std;

int main() {
    int numero;
    cout << "Informe um número: ";
    cin >> numero;

    numero = numero << 1;

    cout << "O número multiplicado por 2 é: " << numero;

    return 0;
}