#include <iostream>

using namespace std;

#define COMPRIMENTO_TOTAL_FILA 256

typedef struct {
    int valor;
} Elemento;

typedef struct {
    Elemento vetor[COMPRIMENTO_TOTAL_FILA];
    int tamanho; // Tamanho atual da fila
} Fila;

Fila* criarFila() {
    Fila* fila = new Fila;
    fila->tamanho = 0;
    return fila;
}

int enfileirar(Fila* fila, int valor) {
    if(fila->tamanho >= COMPRIMENTO_TOTAL_FILA) {
        cout << "Erro: Fila cheia." << endl;
        return -1;
    }

    fila->vetor[fila->tamanho++].valor = valor;

    return 0;
}

Elemento desinfileirar(Fila* fila) {
    if(fila->tamanho <= 0) {
        cout << "Erro: Fila vazia." << endl;
        Elemento elementoVazio = {0};
        return elementoVazio;
    }

    Elemento elemento = fila->vetor[0];

    for(int i = 1;i < fila->tamanho;i++) {
        fila->vetor[i - 1] = fila->vetor[i];
    }

    fila->tamanho--;

    return elemento;
}

void imprimir_fila(Fila* fila) {
    if(fila->tamanho == 0) {
        cout << "Fila vazia!" << endl;
        return;
    }

    for(int i = 0; i < fila->tamanho; i++) {
        cout << "Valor: " << fila->vetor[i].valor << " - ";
    }
}

int main() {
    Fila* fila = new Fila();

    enfileirar(fila, 10);
    enfileirar(fila, 5);
    enfileirar(fila, 15);
    enfileirar(fila, 20);
    enfileirar(fila, 25);

    imprimir_fila(fila);

    cout << endl;

    Elemento e1 = desinfileirar(fila);
    cout << "Elemento desinfileirado - Valor: " << e1.valor << endl << endl;

    imprimir_fila(fila);

    cout << endl;

    desinfileirar(fila);
    desinfileirar(fila);
    desinfileirar(fila);
    desinfileirar(fila);

    imprimir_fila(fila);
    return 0;
}