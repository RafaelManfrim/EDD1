#include <iostream>

using namespace std;

int main() {
    int numero;
    cout << "Informe um número: ";
    cin >> numero;

    if(numero & 1) {
        cout << "O número é ímpar";
    } else {
        cout << "O número é par";
    }

    return 0;
}