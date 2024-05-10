#include <iostream>

using namespace std;

#define COMPRIMENTO_TOTAL_FILA 256

typedef struct {
    int valor;
    int prioridade;
} Elemento;

typedef struct {
    Elemento vetor[COMPRIMENTO_TOTAL_FILA];
    int tamanho; // Tamanho atual da fila
} FilaDePrioridade;

FilaDePrioridade* criarFilaDePrioridade() {
    FilaDePrioridade* fila = new FilaDePrioridade;
    fila->tamanho = 0;
    return fila;
}

int enfileirar(FilaDePrioridade* fila, int valor, int prioridade) {
    if(fila->tamanho >= COMPRIMENTO_TOTAL_FILA) {
        cout << "Erro: Fila de prioridade cheia." << endl;
        return -1;
    }
    int i = fila->tamanho;
    // Encontra a posição correta para inserir o novo elemento
    while(i > 0 && fila->vetor[i - 1].prioridade < prioridade) {
        fila->vetor[i] = fila->vetor[i - 1];
        i--;
    }
    // Insere o novo elemento
    fila->tamanho++;
    fila->vetor[i].valor = valor;
    fila->vetor[i].prioridade = prioridade;

    return 0;
}

Elemento desinfileirar(FilaDePrioridade* fila) {
    if(fila->tamanho <= 0) {
        cout << "Erro: Fila de prioridade vazia." << endl;
        Elemento elementoVazio = {0, 0};
        return elementoVazio;
    }
    // Remove o elemento de maior prioridade (primeiro do vetor)
    Elemento maiorPrioridade = fila->vetor[0];
    // Desloca os elementos restantes para preencher a lacuna
    for(int i = 1;i < fila->tamanho;i++) {
        fila->vetor[i - 1] = fila->vetor[i];
    }
    fila->tamanho--;
    return maiorPrioridade;
}

void imprimir_fila(FilaDePrioridade* fila) {
    if(fila->tamanho == 0) {
        cout << "Fila vazia!" << endl;
        return;
    }

    for(int i = 0; i < fila->tamanho; i++) {
        cout << "Valor: " << fila->vetor[i].valor << " e Prioridade: " << fila->vetor[i].prioridade << endl;
    }
}

int main() {
    FilaDePrioridade* fila_prioridade = criarFilaDePrioridade();

    enfileirar(fila_prioridade, 10, 3);
    enfileirar(fila_prioridade, 5, 4);
    enfileirar(fila_prioridade, 15, 2);
    enfileirar(fila_prioridade, 20, 1);
    enfileirar(fila_prioridade, 25, 5);

    imprimir_fila(fila_prioridade);

    cout << endl;

    Elemento e1 = desinfileirar(fila_prioridade);
    cout << "Elemento desinfileirado - Valor: " << e1.valor << " e Prioridade: " << e1.prioridade << endl << endl;

    imprimir_fila(fila_prioridade);

    cout << endl;

    desinfileirar(fila_prioridade);
    desinfileirar(fila_prioridade);
    desinfileirar(fila_prioridade);
    desinfileirar(fila_prioridade);

    imprimir_fila(fila_prioridade);
    return 0;
}