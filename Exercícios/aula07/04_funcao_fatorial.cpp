#include <iostream>

using namespace std;

int calc_fatorial(int x) {
    int fatorial = 1;

    while(x >= 1) {
        fatorial *= x;
        x--;
    }

    return fatorial;

}

int main() {
    int x = 5;
    int fatorial = calc_fatorial(x);
    cout << "O fatorial de " << x << " é: " << fatorial;
    return 0;
}