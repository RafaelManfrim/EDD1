#include <iostream>

using namespace std;

int main(){
    float base, altura, area;
    cout << "Digite a base do triângulo: " << endl;
    cin >> base;
    cout << "Digite a altura do triângulo: "  << endl;
    cin >> altura;
    area = base * altura / 2;
    cout << "A área do triângulo é: " << area;
    return 0;
}

