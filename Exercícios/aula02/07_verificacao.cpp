#include <iostream>

using namespace std;

int main()
{
  int n;
  cout << "Insira um número: " << endl;
  cin >> n;

  if (n >= 0 && n % 3 != 0)
  {
    cout << "O número é positivo e não é múltiplo de 3!" << endl;
  }
  else if (n < 0 && n % 3 == 0)
  {
    cout << "O número é negativo e é multiplo de 3!" << endl;
  }
  else if (n < 0)
  {
    cout << "O número é negativo!" << endl;
  }
  else
  {
    cout << "O número é multiplo de 3!" << endl;
  }

  return 0;
}