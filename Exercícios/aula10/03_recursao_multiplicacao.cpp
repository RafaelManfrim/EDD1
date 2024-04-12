#include <iostream>

using namespace std;

int multiplicacao(int n1, int n2) {
    if (n2 == 0) {
        return 0;
    }

    if(n2 == 1) {
        return n1;
    }

    return n1 + multiplicacao(n1, n2 - 1);
}

int main() {
    cout << multiplicacao(4, 3);
    return 0;
}
