arremessos = int(input())
acertos = int(input())

percentual = 100 * acertos / arremessos

print(f'{format(percentual, ".2f")}%')
