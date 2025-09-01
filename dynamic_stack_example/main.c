#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

No* novoNo(int valor) {
    No *n = (No*) malloc(sizeof(No));
    if (n == NULL) {
        printf("Erro de alocacao!\n");
        exit(1);
    }
    n->valor = valor;
    n->prox = NULL;
    return n;
}

void push(No **topo, int valor) {
    No *n = novoNo(valor);
    n->prox = *topo;
    *topo = n;
    printf("Inserido: %d\n", valor);
}

int pop(No **topo) {
    if (*topo == NULL) {
        printf("Pilha vazia!\n");
        return -1;
    }
    No *temp = *topo;
    int valor = temp->valor;
    *topo = temp->prox;
    free(temp);
    return valor;
}

int peek(No *topo) {
    if (topo == NULL) {
        printf("Pilha vazia!\n");
        return -1;
    }
    return topo->valor;
}

void mostrar(No *topo) {
    if (topo == NULL) {
        printf("Pilha vazia!\n");
        return;
    }
    printf("Conteudo da pilha (topo -> base):\n");
    while (topo != NULL) {
        printf("[%d]\n", topo->valor);
        topo = topo->prox;
    }
}

void liberar(No **topo) {
    No *atual = *topo;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    *topo = NULL;
    printf("Memoria liberada.\n");
}

int tamanho(No *topo) {
    int tamanho_pilha = 0;
    while (topo != NULL) {
        tamanho_pilha++;
        topo = topo->prox;
    }
    return tamanho_pilha;
}

int main() {
    No *pilha = NULL;
    int opcao, valor;

    do {
        printf("\n--- MENU PILHA DINAMICA ---\n");
        printf("1 - Inserir (push)\n");
        printf("2 - Remover (pop)\n");
        printf("3 - Mostrar topo (peek)\n");
        printf("4 - Mostrar pilha\n");
        printf("5 - Tamanho da pilha\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                push(&pilha, valor);
                break;
            case 2:
                valor = pop(&pilha);
                if (valor != -1)
                    printf("Removido: %d\n", valor);
                break;
            case 3:
                valor = peek(pilha);
                if (valor != -1)
                    printf("Topo: %d\n", valor);
                break;
            case 4:
                mostrar(pilha);
                break;
            case 5:
                valor = tamanho(pilha);
                if (valor != -1)
                    printf("Tamanho: %d\n", valor);
                break;
            case 0:
                liberar(&pilha);
                printf("Encerrando...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
