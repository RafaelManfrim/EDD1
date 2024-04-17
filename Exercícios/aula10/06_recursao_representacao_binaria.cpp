#include <iostream>

using namespace std;

//Escreva uma função recursiva que, dado um número inteiro positivo n,
//retorne a representação binária de n.

string representacao_binaria(int n) {
    int quociente = static_cast<int>(n / 2);
    int resto = n % 2;

    if(quociente == 0) {
        return to_string(resto);
    }

    return representacao_binaria(quociente) + to_string(resto);
}

int main() {
    cout << representacao_binaria(6);
    return 0;
}
