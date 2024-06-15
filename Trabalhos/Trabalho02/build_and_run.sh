#!/bin/bash

# Entrar no diretório build
cd build

# Executar o cmake para configurar o projeto (apenas necessário se novos arquivos foram adicionados)
cmake ..

# Compilar o projeto
make

# Executar o jogo
./rpg-sfml-ed

# Voltar ao diretório original
cd ..