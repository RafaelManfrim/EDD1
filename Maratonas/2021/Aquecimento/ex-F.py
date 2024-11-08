jogada_p1 = input()
jogada_p2 = input()

if jogada_p1.lower() == 'tesoura':

    if jogada_p2.lower() == 'tesoura':
        print('Empate')
    elif jogada_p2.lower() == 'papel':
        print('Jogador 1')
    elif jogada_p2.lower() == 'pedra':
        print('Jogador 2')

elif jogada_p1.lower() == 'papel':

    if jogada_p2.lower() == 'tesoura':
        print('Jogador 2')
    elif jogada_p2.lower() == 'papel':
        print('Empate')
    elif jogada_p2.lower() == 'pedra':
        print('Jogador 1')


elif jogada_p1.lower() == 'pedra':

    if jogada_p2.lower() == 'tesoura':
        print('Jogador 1')
    elif jogada_p2.lower() == 'papel':
        print('Jogador 2')
    elif jogada_p2.lower() == 'pedra':
        print('Empate')
