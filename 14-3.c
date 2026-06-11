#include <stdio.h>

typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

void inserirABB(No *raiz, No *novo) {

    if (novo->valor < raiz->valor) {

        if (raiz->esquerda == NULL)
            raiz->esquerda = novo;
        else
            inserirABB(raiz->esquerda, novo);

    } else {

        if (raiz->direita == NULL)
            raiz->direita = novo;
        else
            inserirABB(raiz->direita, novo);
    }
}

No* removerUmFilho(No *no) {

    if (no->esquerda != NULL)
        return no->esquerda;

    return no->direita;
}

void emOrdem(No *raiz) {

    if (raiz == NULL)
        return;

    emOrdem(raiz->esquerda);
    printf("%d ", raiz->valor);
    emOrdem(raiz->direita);
}

int main() {

    No raiz = {50, NULL, NULL};

    No no30 = {30, NULL, NULL};
    No no20 = {20, NULL, NULL};

    inserirABB(&raiz, &no30);
    inserirABB(&raiz, &no20);

    printf("Antes da remocao:\n");
    emOrdem(&raiz);

    raiz.esquerda = removerUmFilho(&no30);

    printf("\nDepois da remocao:\n");
    emOrdem(&raiz);

    return 0;
}