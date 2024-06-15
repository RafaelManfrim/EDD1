#include <iostream>

using namespace std;

/*Escreva um programa que solicite ao usuário que insira três números: os dois
primeiros definirão um intervalo, e o terceiro número será verificado para
determinar se está dentro deste intervalo. O programa utilizará operadores
lógicos conectando condições.*/

int main()
{
  int n1, n2, n3;
  cout << "Insira o primeiro número: " << endl;
  cin >> n1;
  cout << "Insira o segundo número: " << endl;
  cin >> n2;
  cout << "Insira o terceiro número: " << endl;
  cin >> n3;

  // if (n1 == n2 && n1 == n3) {
  //     cout << "Todos são iguais!" << endl;
  // } else if (n1 > n2){
  //     while (n2 <= n1) {
  //         if (n3 == n2) {
  //             cout << "O número está dentro do intervalo!" << endl;
  //             return 0;
  //         }
  //         n2++;
  //     }
  // } else {
  //     while (n1 <= n2) {
  //         if (n3 == n1) {
  //             cout << "O número está dentro do intervalo!" << endl;
  //             return 0;
  //         }
  //         n1++;
  //     }
  // }
  // cout << "O número está fora do intervalo!" << endl;

  if (n1 == n2 && n1 == n3)
  {
    cout << "Todos são iguais!" << endl;
  }
  else if ((n3 >= n1 && n3 <= n2) || (n3 >= n2 && n3 <= n1))
  {
    cout << "O número está dentro do intervalo!" << endl;
  }
  else
  {
    cout << "O número está fora do intervalo!" << endl;
  }

  return 0;
}