#include <iostream>

using namespace std;

struct Cordenada {
    float x;
    float y;
};

struct Retangulo {
    Cordenada superior_esquerdo;
    Cordenada inferior_direito;
};

float calcular_area(Retangulo &retangulo) {
    float altura = retangulo.superior_esquerdo.y - retangulo.inferior_direito.y;
    float base = retangulo.inferior_direito.x - retangulo.superior_esquerdo.x;

    return base * altura;
}

float calcular_perimetro(Retangulo &retangulo) {
    float altura = retangulo.superior_esquerdo.y - retangulo.inferior_direito.y;
    float base = retangulo.inferior_direito.x - retangulo.superior_esquerdo.x;
    return base * 2 + altura * 2;
}

string calcular_centro_massa(Retangulo &retangulo) {
    float x = retangulo.inferior_direito.x / 2;
    float y = retangulo.superior_esquerdo.y / 2;

    return "(" + to_string(x) + "," + to_string(y) + ")";
}

int main() {
    Retangulo retangulo;

    cout << "Digite o x do canto superior esquerdo: ";
    cin >> retangulo.superior_esquerdo.x;

    cout << "Digite o y do canto superior esquerdo: ";
    cin >> retangulo.superior_esquerdo.y;

    cout << "Digite o x do canto inferior direito: ";
    cin >> retangulo.inferior_direito.x;

    cout << "Digite o y do canto inferior direito: ";
    cin >> retangulo.inferior_direito.y;

    cout << "A área desse retângulo é: " << calcular_area(retangulo) << endl;
    cout << "O perímetro desse retângulo é: " << calcular_perimetro(retangulo) << endl;
    cout << "O centro de massa desse retângulo é: " << calcular_centro_massa(retangulo);

    return 0;
}