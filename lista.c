#include <stdio.h>

#define MAX_SIZE 100 // Tamanho máximo da lista

typedef struct {
    int data[MAX_SIZE]; // Array para armazenar os elementos da lista
    int size;           // Tamanho atual da lista
} Lista;

// Função para inicializar a lista
void inicializarLista(Lista *lista) {
    lista->size = 0;
}

// Função para adicionar um elemento à lista
void adicionar(Lista *lista, int posicao, int valor) {
    if (posicao < 0 || posicao >= MAX_SIZE) {
        printf("Posição inválida!\n");
        return;
    }

    if (lista->size >= MAX_SIZE) {
        printf("A lista está cheia. Não é possível adicionar mais elementos.\n");
        return;
    }

    if (lista->data[posicao] == 0) {
        // A posição selecionada está vazia, podemos adicionar o valor diretamente
        lista->data[posicao] = valor;
    } else {
        // A posição selecionada já está ocupada, encontramos a posição vazia mais próxima
        int i;
        for (i = 1; i < MAX_SIZE; i++) {
            if (posicao - i >= 0 && lista->data[posicao - i] == 0) {
                lista->data[posicao - i] = valor;
                break;
            }
            if (posicao + i < MAX_SIZE && lista->data[posicao + i] == 0) {
                lista->data[posicao + i] = valor;
                break;
            }
        }
        if (i == MAX_SIZE) {
            printf("Não foi possível encontrar uma posição vazia próxima.\n");
            return;
        }
    }

    lista->size++;
}

// Função para imprimir a lista
void imprimirLista(Lista *lista) {
    printf("Lista: ");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (lista->data[i] != 0) {
            printf("%d ", lista->data[i]);
        }
    }
    printf("\n");
}

int main() {
    Lista minhaLista;
    inicializarLista(&minhaLista);

    adicionar(&minhaLista, 2, 10);
    adicionar(&minhaLista, 5, 20);
    adicionar(&minhaLista, 2, 30);
    adicionar(&minhaLista, 10, 40);

    imprimirLista(&minhaLista);

    return 0;
}
