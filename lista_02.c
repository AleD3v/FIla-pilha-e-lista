#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int lista[TAM];

void adicionar(int l[], int posicao, int dado, int tamanho){
    if ((posicao < 0) || (posicao >= tamanho)){
        printf("\n\nPosição inválida\n\n");
        return;
    }
    l[posicao] = dado;
}

void listar(int l[], int tamanho){
    int i;
    printf("\n\nListando a pilha \n\n");
    for (i = 0; i < tamanho;i++){
            printf("%d\n",l[i]);
    }
}

int buscar(int p[], int tamanho, int chave){
    int i;
    for (i = tamanho - 1; i >= 0; i--){
        if (p[i] == chave){
            return i;
        }
    }

    return -1;
}

void remover(int l[], int posicao, int tamanho){
    if ((posicao < 0) || (posicao >= tamanho)){
        printf("\n\nPosição inválida\n\n");
        return;
    }
    l[posicao] = 0;
}


int main(int argc, char** argv) {
    int pos,leitura, key;

    while (1){
        printf("Informe o valor e a posicao: ");
        scanf("%d %d",&leitura, &pos);
        if (leitura == 0)
            break;
        adicionar(lista,pos,leitura,TAM);
    }

    listar(lista,TAM);
    printf("Informe a posição que deseja remover: ");
    scanf("%d",&pos);
    remover(lista, pos, TAM);
    listar(lista,TAM);

    printf("\nInforme a chave da busca: ");
    scanf("%d",&key);
    int posicao = buscar(lista,TAM, key);

    if (posicao == -1){
        printf("\nChave não encontrada!");
    }else{
        printf("\n Chave encontrada na posição %d", posicao);
    }
    return (EXIT_SUCCESS);
}

