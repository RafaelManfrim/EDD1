#include <iostream>

using namespace std;

int main(){
    float n1, n2, n3, media;
    cout << "Digite o primeiro número: " << endl;
    cin >> n1;
    cout << "Digite o segundo número: "  << endl;
    cin >> n2;
    cout << "Digite o terceiro número: "  << endl;
    cin >> n3;
    media = (n1 + n2 + n3) / 3;
    cout << "A média dos números é: " << media;
    return 0;
}

