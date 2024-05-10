#include <iostream>
#define COMPRIMENTO_TOTAL_HEAP 256

using namespace std;

typedef struct No {
    int chave; // Chave do nó
} No;

typedef struct Heap {
    No Nos[COMPRIMENTO_TOTAL_HEAP];
    int tamanho; // Tamanho atual do heap
} Heap;

void troca(No *x, No *y) {
    No temp = *x;
    *x = *y;
    *y = temp;
}

void maxHeapify(No* A, int tamanho, int i) {
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;
    int maior = i;
    if(esquerda < tamanho && A[esquerda].chave > A[maior].chave)
        maior = esquerda;
    if(direita < tamanho && A[direita].chave > A[maior].chave)
        maior = direita;
    if(maior != i) {
        troca(&A[i], &A[maior]);
        maxHeapify(A, tamanho, maior);
    }
}

int insereHeap(Heap *heap, int valor) {
    if(heap->tamanho >= COMPRIMENTO_TOTAL_HEAP) {
        printf("Heap cheio. Não é possível inserir mais elementos.\n");
        return -1;
    }
    int i = heap->tamanho;
    heap->Nos[i].chave = valor;
    heap->tamanho++;
    // Ajuste para manter a propriedade do heap
    while(i > 0 && heap->Nos[(i-1)/2].chave < heap->Nos[i].chave) {
        troca(&heap->Nos[i], &heap->Nos[(i-1)/2]);
        i = (i-1)/2;
    }
    return 0;
}

No extraiMaximo(Heap *heap) {
    No raiz;
    if(heap->tamanho <= 0) {
        printf("Heap vazio. Não é possível extrair máximo.\n");
        raiz.chave = -1;
        return raiz;
    }
    // Salvar a raiz removida
    raiz = heap->Nos[0];
    // Substituir a raiz pelo último nó do heap
    heap->Nos[0] = heap->Nos[--heap->tamanho];
    // Aplicar Max-Heapify para restaurar a propriedade do heap
    maxHeapify(heap->Nos, heap->tamanho, 0);
    return raiz;
}

void imprimir_fila(Heap *fila) {
    if(fila->tamanho == 0) {
        cout << "Fila vazia!" << endl;
        return;
    }

    for(int i = 0; i < fila->tamanho; i++) {
        cout << "Valor: " << fila->Nos[i].chave << " e Prioridade: " << fila->Nos[i].chave << endl;
    }
}

int main() {
    Heap* heap = new Heap;
    heap->tamanho = 0;

    insereHeap(heap, 4);
    insereHeap(heap, 2);
    insereHeap(heap, 9);
    insereHeap(heap, 7);
    insereHeap(heap, 5);
    insereHeap(heap, 13);
    insereHeap(heap, 11);

    imprimir_fila(heap);
    cout << endl;

    No no = extraiMaximo(heap);
    cout << "Elemento extraído - " << no.chave;

    cout << endl << endl;

    imprimir_fila(heap);
    cout << endl;

    extraiMaximo(heap);

    imprimir_fila(heap);
    cout << endl;

    extraiMaximo(heap);

    imprimir_fila(heap);

    return 0;
}