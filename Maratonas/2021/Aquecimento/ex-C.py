import math

valor = input()
entradas = input()

# R$3.71
# 10 10 10 10

# R$1.99
# 9 19 9 1

valor_figurinhas = float(valor[2:])
moedas = list(map(int, entradas.split()))
dinheiro_total = 0.25 * moedas[0] + 0.10 * moedas[1] + 0.05 * moedas[2] + 0.01 * moedas[3]

quantidade_figurinhas_compradas = math.floor(dinheiro_total / valor_figurinhas)

total_gasto = quantidade_figurinhas_compradas * valor_figurinhas
restante_moedas = [0, 0, 0, 0]
restante_dinheiro = dinheiro_total

ultima_rodada = False

ultima_moeda = 0

while restante_dinheiro > total_gasto:
    if restante_moedas[3] < moedas[3]:
        restante_moedas[3] = restante_moedas[3] + 1
        restante_dinheiro = restante_dinheiro - 0.01
        ultima_moeda = 3
    elif restante_moedas[2] < moedas[2]:
        restante_moedas[2] = restante_moedas[2] + 1
        restante_dinheiro = restante_dinheiro - 0.05
        ultima_moeda = 2
    elif restante_moedas[1] < moedas[1]:
        restante_moedas[1] = restante_moedas[1] + 1
        restante_dinheiro = restante_dinheiro - 0.10
        ultima_moeda = 1
    elif restante_moedas[0] < moedas[0]:
        restante_moedas[0] = restante_moedas[0] + 1
        restante_dinheiro = restante_dinheiro - 0.25
        ultima_moeda = 0

# restante_moedas[ultima_moeda] = restante_moedas[ultima_moeda] - 1

print(quantidade_figurinhas_compradas)
print(restante_moedas[0] + restante_moedas[1] + restante_moedas[2] + restante_moedas[3] - 1)
