#include <iostream>

using namespace std;

int somar(int n1, int n2) {
    return n1 + n2;
}

int main() {
    int a = 4, b = 5;
    int soma = somar(a, b);
    cout << "O valor da soma é: " << soma;

    return 0;
}