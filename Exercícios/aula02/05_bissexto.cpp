#include <iostream>

using namespace std;

int main()
{
  int ano;
  cout << "Digite um ano: " << endl;
  cin >> ano;

  if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
  {
    cout << "Esse ano é bissexto!" << endl;
  }
  else
  {
    cout << "Esse ano não é bissexto!" << endl;
  }
  return 0;
}