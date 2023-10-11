#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct SPilha {
    int topo;
    int dados[TAM];
} TPilha;

// Inicializa a pilha
TPilha inicializarPilha() {
    TPilha pilha;
    pilha.topo = -1;
    return pilha;
}

// Verifica se a pilha está cheia
int estaCheia(TPilha pilha) {
    return pilha.topo == TAM - 1;
}

// Verifica se a pilha está vazia
int estaVazia(TPilha pilha) {
    return pilha.topo == -1;
}

// Insere um elemento na pilha (push)
TPilha empilhar(TPilha pilha, int dado) {
    if (estaCheia(pilha)) {
        printf("\nA pilha está cheia\n");
        return pilha;
    } else {
        pilha.topo++;
        pilha.dados[pilha.topo] = dado;
        return pilha;
    }
}

// Remove um elemento da pilha (pop)
TPilha desempilhar(TPilha pilha) {
    if (estaVazia(pilha)) {
        printf("\nA pilha está vazia\n");
        return pilha;
    } else {
        pilha.topo--;
        return pilha;
    }
}

// Lista os elementos da pilha
void listarPilha(TPilha pilha) {
    printf("\nListando a pilha:\n");
    for (int i = pilha.topo; i >= 0; i--) {
        printf("%d\n", pilha.dados[i]);
    }
}

// Busca um elemento na pilha
int buscarElemento(TPilha pilha, int chave) {
    for (int i = pilha.topo; i >= 0; i--) {
        if (pilha.dados[i] == chave) {
            return i;
        }
    }
    return -1;
}

int main(int argc, char **argv) {
    TPilha pilha = inicializarPilha();

    int leitura, key;

    while (1) {
        printf("Informe o valor (0 para sair): ");
        scanf("%d", &leitura);
        if (leitura == 0)
            break;
        pilha = empilhar(pilha, leitura);
    }

    listarPilha(pilha);
    pilha = desempilhar(pilha);
    pilha = desempilhar(pilha);
    listarPilha(pilha);

    printf("Informe a chave da busca: ");
    scanf("%d", &key);
    int posicao = buscarElemento(pilha, key);

    if (posicao == -1) {
        printf("\nChave não encontrada!\n");
    } else {
        printf("\nChave encontrada na posição %d\n", posicao);
    }

    return (EXIT_SUCCESS);
}
