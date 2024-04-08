#include <iostream>

using namespace std;

int retorna_minimo_vetor(int *vetor) {
    int menor;

    for(int i = 0; i <= sizeof(*vetor); i++) {
        if (i == 0) {
            menor = vetor[i];
        }

        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }

    return menor;
}

int main() {
    int vetor[] = {5, 2, 15, 1, 25};
    cout << "O valor mínimo do vetor é: " << retorna_minimo_vetor(vetor);

    return 0;
}