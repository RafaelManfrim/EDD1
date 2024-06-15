#include <iostream>
#include <string>

using namespace std;

int main() {
    unsigned int n, fatorial=1;
    cout << "Digite um número inteiro não negativo: " << endl;
    cin >> n;
    while(n >= 1) {
        fatorial *= n;
        n--;
    }

    cout << "O fatorial desse número é: " << fatorial << endl;
    return 0;
}
