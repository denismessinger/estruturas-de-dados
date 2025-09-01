#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int itens[MAX];
    int topo;
} Stack;

void inicializar(Stack *s) {
    s->topo = -1;
}

int estaVazia(Stack *s) {
    return (s->topo == -1);
}

int estaCheia(Stack *s) {
    return (s->topo == MAX - 1);
}

void push(Stack *s, int valor) {
    if (estaCheia(s)) {
        printf("\n");
        printf("Pilha cheia! Nao foi possivel adicionar %d.\n", valor);
    } else {
        s->itens[++(s->topo)] = valor;
        printf("\n");
        printf("Inserido: %d\n", valor);
    }
}

int pop(Stack *s) {
    if (estaVazia(s)) {
        printf("\n");
        printf("Pilha vazia! Nao ha elementos para remover.\n");
        return -1;
    } else {
        return s->itens[(s->topo)--];
    }
}

int peek(Stack *s) {
    if (estaVazia(s)) {
        printf("\n");
        printf("Pilha vazia!\n");
        return -1;
    } else {
        return s->itens[s->topo];
    }
}

void mostrar(Stack *s) {
    if (estaVazia(s)) {
        printf("\n");
        printf("Pilha vazia!\n");
    } else {
        printf("Conteudo da pilha (topo -> base):\n");
        for (int i = s->topo; i >= 0; i--) {
            printf("[%d]\n", s->itens[i]);
        }
    }
}

int main() {
    Stack pilha;
    inicializar(&pilha);

    int opcao, valor;

    do {
        printf("\n--- MENU PILHA ---\n");
        printf("1 - Inserir (push)\n");
        printf("2 - Remover (pop)\n");
        printf("3 - Mostrar topo (peek)\n");
        printf("4 - Mostrar pilha\n");
        printf("0 - Sair\n");
        printf("\n");
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
                    printf("\n");
                    printf("Removido: %d\n", valor);
                break;
            case 3:
                valor = peek(&pilha);
                if (valor != -1)
                    printf("\n");
                    printf("Topo: %d\n", valor);
                break;
            case 4:
                mostrar(&pilha);
                break;
            case 0:
                printf("\n");
                printf("Encerrando...\n");
                break;
            default:
                printf("\n");
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
