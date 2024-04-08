#include <iostream>

using namespace std;

int main(){
    float a, an, r, n, s;
    cout << "Digite o primeiro termo da P.A (a): " << endl;
    cin >> a;
    cout << "Digite a razão (r): " << endl;
    cin >> r;
    cout << "Digite o número de termos (n): " << endl;
    cin >> n;
    an = a + (n - 1) * r;
    s = (n * (a + an)) / 2;
    cout << "A soma dos " << n << " termos da P.A. é: " << s << endl;
    return 0;
}

