#include <iostream>

using namespace std;

int main(){
    int n1, n2, n3;
    cout << "Digite um número: " << endl;
    cin >> n1;
    cout << "Digite outro número: " << endl;
    cin >> n2;
    cout << "Digite mais um número: " << endl;
    cin >> n3;
    
    if (n1 > n2 && n1 > n3) {
        cout << "n1 é o maior" << endl;

        if (n2 == n3) {
            cout << "n2 e n3 são iguais";
        } else if (n2 < n3) {
            cout << "n2 é o menor";
        } else {
            cout << "n3 é o menor";
        }
    } else if (n2 > n1 && n2 > n3) {
        cout << "n2 é o maior" << endl;

        if (n1 == n3) {
            cout << "n1 e n3 são iguais";
        } else if (n1 < n3) {
            cout << "n1 é o menor";
        } else {
            cout << "n3 é o menor";
        }
    } else if (n3 > n1 && n3 > n2) {
        cout << "n3 é o maior" << endl;

        if (n2 == n1) {
            cout << "n2 e n1 são iguais";
        } else if (n1 < n2) {
            cout << "n1 é o menor";
        } else {
            cout << "n2 é o menor";
        }
    } else if (n1 == n2 && n1 == n3) {
        cout << "todos são iguais" << endl;
    } else if (n1 == n2) {
        cout << "n1 e n2 são iguais";

        if (n3 < n1) {
            cout << "n3 é menor que os outros";
        } else {
            cout << "n3 é maior que os outros";
        }
    } else if (n1 == n3) {
        cout << "n1 e n3 são iguais" << endl;

        if (n2 < n1) {
            cout << "n2 é menor que os outros";
        } else {
            cout << "n2 é maior que os outros";
        }
    } else if (n2 == n3) {
        cout << "n2 e n3 são iguais" << endl;

        if (n1 < n2) {
            cout << "n1 é menor que os outros";
        } else {
            cout << "n1 é maior que os outros";
        }
    }

    return 0;
}
