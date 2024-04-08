#include <iostream>

using namespace std;

void elevar_quadrado(int &numero) {
    numero *= numero;
}

void quadrado_vetor(int *vetor) {
    for (int i = 0; i <= sizeof(*vetor); i++)
        elevar_quadrado(vetor[i]);
}

void imprimir_vetor(int *vetor) {
    for (int i = 0; i <= sizeof(*vetor); i++)
        cout << vetor[i] << " ";
    cout << endl;
}

int main() {
    int vetor[] = {3, 2, 4, 6, 5};
    imprimir_vetor(vetor);
    quadrado_vetor(vetor);
    imprimir_vetor(vetor);

    return 0;
}