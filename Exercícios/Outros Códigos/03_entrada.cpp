#include <iostream>
#include <string>

using namespace std;

int main()
{
    int x, y, soma;
    cout << "Digite dois números" << endl;
    cin >> x;
    cin >> y;
    soma = x + y;
    cout << "A soma é: " << soma << endl;
    string palavra, linha;
    cout << "Digite uma palavra" << endl;
    cin >> palavra;
    cout << "Você digitou: " << palavra << endl;
    cout << "Digite uma linha de texto" << endl;
    getline(cin, linha);
    cout << "Você escreveu: " << linha << endl;
    return 0;
}