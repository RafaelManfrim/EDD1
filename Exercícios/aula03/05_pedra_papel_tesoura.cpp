#include <iostream>
#include <random>

using namespace std;

int main() {
   int vitorias_usuario = 0, vitorias_computador = 0, empates = 0;
   int escolha_computador = 4, escolha_jogador = 4;

   while(true) {
       cout << "MENU ==> (1 - Pedra, 2 - Papel, 3 - Tesoura, e 0 - Sair): ";
       cin >> escolha_jogador;

       if (escolha_jogador == 0) {
           cout << "Vitórias usuário: " << vitorias_usuario << endl;
           cout << "Vitórias computador: " << vitorias_computador << endl;
           cout << "Empates: " << empates << endl;
           return 0;
       } else if (escolha_jogador > 3 || escolha_jogador < 0) {
           cout << "Opção inválida, escolha novamente!" << endl;
           continue;
       }

       random_device generator;
       uniform_int_distribution<int> distribution(1,3);
       escolha_computador = distribution(generator);

       cout << "Escolha do computador: " << escolha_computador << endl;

       if (escolha_jogador == escolha_computador) {
           empates++;
           cout << "O jogo deu empate!" << endl;
       } else if (
               (escolha_jogador == 2 && escolha_computador == 1)
               || (escolha_jogador == 3 && escolha_computador == 2)
               || (escolha_jogador == 1 && escolha_computador == 3)
               ) {
           vitorias_usuario++;
           cout << "O usuário venceu!" << endl;
       } else {
           vitorias_computador++;
           cout << "O computador venceu!" << endl;
       }
   }
}