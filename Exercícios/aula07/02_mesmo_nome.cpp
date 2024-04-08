#include <iostream>

using namespace std;

int a = 1;

void funcao() {
    cout << "a -> funcao: " << a << endl; // global
    int a = 2;
    cout << "a -> funcao novamente: " << a << endl; // local
}

int main() {
    cout << "a -> main: " << a << endl; // global
    funcao();
    cout << "a -> main novamente: " << a << endl; // global

    return 0;
}

// A declaração da variável "a" dentro da função, substitui o valor apenas dentro do escopo da função.
// Fora do escopo da função, continua sendo usada a variável global