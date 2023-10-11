#include <stdio.h>


#define TAM 5

typedef struct SFila {
    int inicio;
    int fim;
    int dados[TAM];
} TFila;

TFila inicializarFila() {
    TFila fila;
    fila.inicio = 0;
    fila.fim = -1;
    return fila;
}

int estaCheia(TFila fila) {
    return (fila.fim != -1) && (fila.inicio == ((fila.fim + 1) % TAM));
}

int estaVazia(TFila fila) {
    return (fila.fim == -1);
}

TFila enqueue(TFila fila, int dado) {
    if (estaCheia(fila)) {
        printf("\nValor não inserido, a fila está cheia\n");
        return fila;
    }

    fila.fim = (fila.fim + 1) % TAM;
    fila.dados[fila.fim] = dado;
    return fila;
}

void listar(TFila fila) {
    int i = fila.inicio;

    printf("\n\nListando a fila\n\n");
    while (i != (fila.fim + 1) % TAM) {
        printf("%d ", fila.dados[i]);
        i = (i + 1) % TAM;
    }
}

int buscar(TFila fila, int chave) {
    int i = fila.inicio;
    while (i != (fila.fim + 1) % TAM) {
        if (chave == fila.dados[i])
            return i;
        i = (i + 1) % TAM;
    }

    return -1;
}

TFila dequeue(TFila fila) {
    if (!estaVazia(fila)) {
        fila.inicio = (fila.inicio + 1) % TAM;
    }
    return fila;
}

int main() {
    TFila fila;
    int leitura, key;

    fila = inicializarFila();

    while (1) {
        printf("Informe o valor: ");
        scanf("%d", &leitura);
        if (leitura == 0)
            break;
        fila = enqueue(fila, leitura);
    }

    listar(fila);
    fila = dequeue(fila);
    fila = dequeue(fila);
    listar(fila);

    printf("Informe a chave da busca: ");
    scanf("%d", &key);
    int posicao = buscar(fila, key);

    if (posicao == -1) {
        printf("\nChave não encontrada!");
    } else {
        printf("\n Chave encontrada na posição %d", posicao);
    }
    
}
