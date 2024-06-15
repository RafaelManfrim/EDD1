#!/bin/bash

# Entrar no diretório build
cd build

# Executar o cmake para configurar o projeto (apenas necessário se novos arquivos foram adicionados)
cmake ..

# Compilar o projeto
make

# Executar o jogo
./meu_jogo

# Voltar ao diretório original
cd ..