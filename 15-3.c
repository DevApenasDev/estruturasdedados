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

No* menorValor(No *raiz) {

    while (raiz->esquerda != NULL)
        raiz = raiz->esquerda;

    return raiz;
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
    No no70 = {70, NULL, NULL};
    No no60 = {60, NULL, NULL};
    No no80 = {80, NULL, NULL};

    inserirABB(&raiz, &no30);
    inserirABB(&raiz, &no70);
    inserirABB(&raiz, &no60);
    inserirABB(&raiz, &no80);

    printf("Antes da remocao:\n");
    emOrdem(&raiz);

    No *sucessor = menorValor(raiz.direita);

    raiz.valor = sucessor->valor;

    printf("\nDepois da remocao da raiz usando sucessor:\n");
    emOrdem(&raiz);

    return 0;
}