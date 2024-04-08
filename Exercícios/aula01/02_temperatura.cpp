#include <iostream>

using namespace std;

int main(){
    float temperatura_celcius, temperatura_fahrenheit;
    cout << "Digite a temperatura em Celsius: " << endl;
    cin >> temperatura_celcius;
    temperatura_fahrenheit = temperatura_celcius * 1.8 + 32;
    cout << temperatura_celcius << " graus Celcius equivalem a " << temperatura_fahrenheit << " graus fahrenheit" << endl;
    return 0;
}

