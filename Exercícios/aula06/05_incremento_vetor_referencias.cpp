#include <iostream>

using namespace std;

void incrementar_valores(int (&arr)[3], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        arr[i] += 1;
    }
}

int main() {
    int arr[] = {2, 4, 5};
    cout << "Valores iniciais: " << endl;
    cout << "arr[0]: " << arr[0] << endl;
    cout << "arr[1]: " << arr[1] << endl;
    cout << "arr[2]: " << arr[2] << endl;

    incrementar_valores(arr, 3);

    cout << "Valores incrementados: " << endl;

    cout << "arr[0]: " << arr[0] << endl;
    cout << "arr[1]: " << arr[1] << endl;
    cout << "arr[2]: " << arr[2] << endl;

    return 0;
}