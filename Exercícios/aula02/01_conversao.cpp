#include <iostream>

using namespace std;

int main(){
    float medida;
    cout << "Digite a medida em metros: " << endl;
    cin >> medida;
    cout << medida << " metros equivalem a " << static_cast <int>(medida * 100) << " centímetros.";
    return 0;
}
