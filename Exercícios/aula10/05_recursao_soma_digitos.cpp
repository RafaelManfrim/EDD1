#include <iostream>

using namespace std;

int soma_digitos_numero(int n) {
    int quociente = static_cast<int>(n / 10);
    int resto = n % 10;

    if(quociente == 0) {
        return resto;
    }

    return resto + soma_digitos_numero(quociente);
}

int main() {
    cout << soma_digitos_numero(14675);
    return 0;
}
