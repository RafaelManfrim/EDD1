#include <iostream>

using namespace std;

int main(){
    int numero;
    cout << "Digite um número: " << endl;
    cin >> numero;
    if (numero > 0) {
        cout << "Esse número é positivo";
    } else if (numero < 0) {
        cout << "Esse número é negativo";
    } else {
        cout << "Esse número é 0";
    }
    return 0;
}
