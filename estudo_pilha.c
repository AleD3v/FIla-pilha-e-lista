#include <stdio.h>

#define TAM 5

typedef struct SPilha{
    int topo;
    int dados[TAM];
} TPilha;

TPilha inicializar(){
    TPilha pilha;
    pilha.topo = -1;
    return pilha;
}

int full(TPilha pilha){
    return pilha.topo == TAM -1;
}

int empty(TPilha pilha){
    return pilha.topo == -1;
}

TPilha empilhar(TPilha pilha, int dado){
    if(full(pilha)){
        printf("\nA pilha está cheia!\n");
        return pilha;
    }
    pilha.dados[++pilha.topo] = dado;
    return pilha;
}

TPilha pop(TPilha pilha){
    if(empty(pilha)){
        printf("\nA pilha está vazia!\n");
        return pilha;
    }
    pilha.topo--;
    return pilha;
}

void listar(TPilha pilha){
    printf("\nListando...\n");
    for(int i = pilha.topo; i >= 0; i--){
        printf("%d\n", pilha.dados[i]);
    }
}

int buscar(TPilha pilha, int key){
    for(int i = pilha.topo; i >= 0; i--){
        if(pilha.dados[i] == key){
            return i;
        }
    }
    return -1;
}

int main(){
    TPilha pilha = inicializar();

    int dado, chave;

    while(1){
        printf("\nDigite um valor para adicionar na pilha: \n");
        scanf("%d", &dado);
        if(dado == 0){
            break;
        }
        pilha = empilhar(pilha, dado);
    }

    listar(pilha);
    pilha = pop(pilha);
    pilha = pop(pilha);
    listar(pilha);

    printf("Digite um valor para buscar: \n");
    scanf("%d", &chave);
    int posicao = buscar(pilha, chave);
    if(posicao == -1){
        printf("Valor não encontrado!\n");
    }else{
        printf("Valor encontrado na posição: %d \n", posicao);
    }
}