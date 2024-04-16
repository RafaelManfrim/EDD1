#include <iostream>

using namespace std;

int soma_inteiros_validos(int n) {
    if(n == 0) {
        return n;
    } else if(n % 2 == 1) {
        return soma_inteiros_validos(n - 1);
    }

    return n + soma_inteiros_validos(n - 1);
}

int main() {
    cout << soma_inteiros_validos(6);
    return 0;
}
