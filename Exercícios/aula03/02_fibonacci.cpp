#include <iostream>
#include <string>

using namespace std;

void fib(int value, int n1, int n2){
    if(n1 > value) {
        return;
    }

    cout << n1 << ", ";
    
    fib(value, n2, n1 + n2);
}

int main() {
    int value;
    cout << "Digite um número e encontre a sequência de fibonacci: " << endl;
    cin >> value;
    fib(value, 0, 1);
    return 0;
}
