#include <iostream>

using namespace std;

int main() {
    int intVar = 1;
    int *ptr1 = &intVar;
    int **ptr2 = &ptr1;

    cout << "Valor inicial de intVar: " << intVar << endl;
    **ptr2 = 2;
    cout << "Novo valor de intVar: " << intVar << endl;

    return 0;
}
