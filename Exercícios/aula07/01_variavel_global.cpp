#include <iostream>

using namespace std;

int qtde_execucoes_hello_world = 0;

void hello_world() {
    qtde_execucoes_hello_world++;
    cout << "Hello World!" << endl;
}

int main() {
    hello_world();
    hello_world();
    hello_world();
    hello_world();
    hello_world();

    cout << "Quantidade de execuções hello_world: " << qtde_execucoes_hello_world;
    return 0;
}
