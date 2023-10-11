#include <stdio.h>

#define TAM 5

int lista[TAM];

void adicionar(int l[], int dado, int posicao, int tamanho){
    if(posicao < 0 || posicao >= tamanho){
        printf("\nPosição inválida\n");
        return;
    }
    l[posicao] = dado;
}

void remover(int l[], int posicao, int tamanho){
    if(posicao < 0 || posicao >= tamanho){
        printf("\nPosição inválida");
        return;
    }
    l[posicao] = 0;
}

void listar(int l[], int tamanho){
    printf("\nListando...\n");
    for(int i = tamanho; i >= 0; i--){
        printf("%d\n", l[i]);
    }
}

int buscar(int l[], int key, int tamanho){
    for(int i = tamanho; i >= 0; i--){
        if(l[i] == key){
            return i;
        }
    }
    return -1;
}