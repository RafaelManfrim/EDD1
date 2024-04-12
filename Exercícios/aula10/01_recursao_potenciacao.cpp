#include <iostream>

using namespace std;

int pot(int base, int expoente) {
    if(expoente==0) {
        return 1;
    }

    return base * pot(base, expoente-1);
}

int main() {
    cout << pot(4, 3);
    return 0;
}
