#include <iostream>

using namespace std;

int main() {
    int intVar1 = 1;
    int *ptrIntVar1 = &intVar1;
    int **pPtrIntVar1 = &ptrIntVar1;

    int intVar2 = 2;
    int *ptrIntVar2 = &intVar2;
    int **pPtrIntVar2 = &ptrIntVar2;

    cout << "Valor inicial de intVar1: " << intVar1 << endl;
    cout << "Valor inicial de intVar2: " << intVar2 << endl;

    int temp = **pPtrIntVar1;
    **pPtrIntVar1 = **pPtrIntVar2;
    **pPtrIntVar2 = temp;

    cout << "Novo valor de intVar1: " << intVar1 << endl;
    cout << "Novo valor de intVar2: " << intVar2 << endl;

    return 0;
}
