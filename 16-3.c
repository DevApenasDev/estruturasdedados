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

int menor(No *raiz) {

    while (raiz->esquerda != NULL)
        raiz = raiz->esquerda;

    return raiz->valor;
}

int maior(No *raiz) {

    while (raiz->direita != NULL)
        raiz = raiz->direita;

    return raiz->valor;
}

int main() {

    No raiz = {50, NULL, NULL};

    No no30 = {30, NULL, NULL};
    No no70 = {70, NULL, NULL};
    No no20 = {20, NULL, NULL};
    No no40 = {40, NULL, NULL};
    No no60 = {60, NULL, NULL};
    No no80 = {80, NULL, NULL};

    inserirABB(&raiz, &no30);
    inserirABB(&raiz, &no70);
    inserirABB(&raiz, &no20);
    inserirABB(&raiz, &no40);
    inserirABB(&raiz, &no60);
    inserirABB(&raiz, &no80);

    printf("Menor valor: %d\n", menor(&raiz));
    printf("Maior valor: %d\n", maior(&raiz));

    return 0;
}