import math

entrada = input()

tamanho_percurso, velocidade, horas = map(int, entrada.split())

tamanho_percurso_km = tamanho_percurso / 1000

resultado = math.floor(velocidade * horas / tamanho_percurso_km)

print(resultado)
