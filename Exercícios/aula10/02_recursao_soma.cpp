#include <iostream>

using namespace std;

int soma(int n1, int n2) {
    if(n2 == 0) {
        return n1;
    }

    return soma(n1 + 1, n2 - 1);
}

int main() {
    cout << soma(0, 13);
    return 0;
}
