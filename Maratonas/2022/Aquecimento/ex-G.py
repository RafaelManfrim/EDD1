numero = int(input())

soma_pares = 0
soma_impares = 0

while(numero > 0):
  resto = numero % 10
  numero = numero // 10

  if resto % 2 == 0:
    soma_pares += resto
  else:
    soma_impares += resto

if soma_pares % 3 == 0:
  print("S")
else:
  print("N")

if soma_impares % 3 == 0:
  print("S")
else:
  print("N")
