# Trabalho 2 - Ed

O jogo será um RPG onde um herói, controlado pelo usuário, explorará um ou mais
labirintos encontrando tesouros e inimigos.

Em T1 vocês tiveram que pensar em como modelar o torneio (qual estrutura de dados utilizar, como utilizar), como modelar a lista de inimigos derrotados, como modelar os arquétipos, etc. Neste trabalho, pensem em como modelarão o jogo utilizando as estruturas de dados aprendidas.

Implementar em C++ de acordo com as seguintes instruções:

- [ ] O jogo deve possuir um componente gráfico usando SFML. Ou seja, deverá exibir o personagem se movimentando e interagindo com o ambiente do jogo.
- [ ] Na tela inicial o usuário deve escolher o nome e a classe do personagem, os arquétipos criados para T1 poderão ser utilizados para serem as classes selecionadas pelo usuário ou dos inimigos no labirinto..
- [ ] O usuário irá controlar o personagem com o teclado e/ou mouse enquanto explora o labirinto e luta contra os inimigos.
- [ ] O combate pode possuir a mesma implementação de T1 ou pode permitir que o usuário tome decisões durante o combate.
- [ ] Terá as mesmas mecânicas de ataque especial e sangramento, como implementadas em T1.
- [ ] O personagem deve possuir um inventário, onde guardará itens e tesouros encontrados no labirinto.
- [ ] Os itens devem prover bônus para o personagem durante os combates. Por exemplo, um escudo pode prover aumento da defesa.
- [ ] O labirinto deve ter um fim onde o personagem lutará com um boss para finalizar o jogo.
- [ ] Ao fim, o jogo deve apresentar uma pontuação de acordo com os tesouros acumulados durante a exploração do labirinto.
- [ ] Musiquinha de vitória ao final do game

## Algumas sugestões:
- Filas podem ser utilizadas em sistemas de turnos.
- Filas de prioridade permitem o gerenciamento de eventos de diferentes prioridades.
- Listas ligadas podem ser utilizadas para gerenciar inventário, inimigos, etc.
- Pilhas permitem o gerenciamento de bônus de equipamentos ou de bônus temporários causados por itens que expiram como poções, ou seja, utilize uma pilha de bônus.
- Pilhas também podem ser utilizadas para armazenar ações e permitir desfazer ações efetuadas.

Estruturas de dados permitem armazenar, organizar e gerenciar conjuntos dinâmicos de dados. Utilizem-as para este fim, considerando os dados existentes em seu jogo.

## O que resta a ser feito:

- Finalizar Menus
- Adicionar menus para a criação do nome de personagem/classe do personagem (opcional)
- Identificar a distância certa entre o player e o inimigo e iniciar uma batalha
- Realizar a batalha, em caso de vitória do jogador, remover o inimigo da fila
- Adicionar sistema de inventário como uma lista encadeada, realizar cálculo de drop de itens após o combate com um inimigo
- Adicionar música de fundo no game e música de vitória/derrota
- Descobrir onde colocar pilha e fila de prioridade
