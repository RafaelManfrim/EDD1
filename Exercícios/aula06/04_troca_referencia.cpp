#include <iostream>

using namespace std;

void trocar_valores(float &v1, float &v2) {
    float temp = v1;
    v1 = v2;
    v2 = temp;
}

int main() {
    float v1 = 5.50, v2 = 9.99;
    cout << "Valores iniciais:" << endl;
    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;

    trocar_valores(v1, v2);

    cout << "Valores trocados:" << endl;
    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;

    return 0;
}