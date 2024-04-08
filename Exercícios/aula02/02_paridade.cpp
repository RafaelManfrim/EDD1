#include <iostream>

using namespace std;

int main(){
    int numero;
    cout << "Digite um número: " << endl;
    cin >> numero;
    if (numero % 2 == 0) {
        cout << "Esse número é par";
    } else {
        cout << "Esse número é ímpar";
    }
    return 0;
}
