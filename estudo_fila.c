#include <stdio.h>

#define TAM 5

typedef struct SFila{
    int inicio;
    int fim;
    int dados[TAM];
} TFila;

TFila inicializar(){
    TFila fila;
    fila.inicio = 0;
    fila.fim = -1;
    return fila;
}

int full(TFila fila){
    return fila.fim != -1 && fila.inicio == (fila.fim + 1) % TAM;
}

int empty(TFila fila){
    return fila.fim == -1;
}

TFila enqueue(TFila fila, int dado, int tamanho){
    if(full(fila)){
        printf("\nValor não inserido, a fila está cheia!\n");
        return fila;
    }
    fila.fim = (fila.fim + 1) % tamanho;
    fila.dados[fila.fim] = dado;
    return fila;
}

void listar(TFila fila, int tamanho){
    printf("\nListando...\n");
    int i = fila.inicio;
    do {
        printf("%d ",fila.dados[i]);
        i = (i + 1) % tamanho;
    }while (i != (fila.fim + 1) % tamanho );
}

int buscar(TFila fila, int key, int tamanho){
    int i = fila.inicio;
    do{
        if(key == fila.dados[i]){
            return -1;
        }
        i = (i + 1) % tamanho;
    }while (i != (fila.fim +1) % tamanho);
    return -1;
}

TFila dequeue(TFila fila, int tamanho){
    if(!empty){
       fila.inicio = (fila.inicio + 1) % tamanho;
    }
    return fila;
}