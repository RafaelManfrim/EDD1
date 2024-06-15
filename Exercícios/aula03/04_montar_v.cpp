#include <iostream>

using namespace std;

int main() {
    int numero_final, numero_linha;
    cout << "Digite um número para a montagem do triângulo: ";
    cin >> numero_final;

    for(numero_linha = 1; numero_linha <= numero_final; numero_linha++) {
        int qtde_digitos_numero_final = (int) to_string(numero_final).size();
        int qtde_digitos_numero_linha = (int) to_string(numero_linha).size();

        int i;

        for(i = numero_linha; i > 1; i--) {
            cout << " ";
        }

        if (numero_linha == numero_final) {
            int j;

            for(j = qtde_digitos_numero_final; j > 1; j--) {
                cout << " ";
            }

            cout << numero_linha;
        } else {
            cout << numero_linha;

            int k, numero_espacos;
            numero_espacos = (numero_final - numero_linha) * 2 + qtde_digitos_numero_final;

            if (qtde_digitos_numero_final == qtde_digitos_numero_linha) {
                numero_espacos = qtde_digitos_numero_final + (numero_final - numero_linha - 1) * 2;
            }

            if (qtde_digitos_numero_final - qtde_digitos_numero_linha > 1) {
                numero_espacos = numero_espacos + (qtde_digitos_numero_final - qtde_digitos_numero_linha - 1) * 2;
            }

            for(k = 1; k <= numero_espacos; k++) {
                cout << "-";
            }

            cout << numero_linha;
        }
        cout << endl;
    }

    return 0;
}