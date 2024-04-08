#include <iostream>

using namespace std;

void calc_fatorial(int &x) {
    int i = x;
    x = 1;

    while(i >= 1) {
        x *= i;
        i--;
    }
}

void fatorial_vetor(int *vetor) {
    for (int i = 0; i <= sizeof(*vetor); i++)
        calc_fatorial(vetor[i]);
}

void imprimir_vetor(int *vetor) {
    for (int i = 0; i <= sizeof(*vetor); i++)
        cout << vetor[i] << " ";
    cout << endl;
}

int main() {
    int vetor[] = {3, 6, 5, 4, 1};
    imprimir_vetor(vetor);
    fatorial_vetor(vetor);
    imprimir_vetor(vetor);

    return 0;
}