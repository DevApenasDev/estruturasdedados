#include <stdio.h>

typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

void inserirEsquerda(No *pai, No *filho) {
    pai->esquerda = filho;
}

void inserirDireita(No *pai, No *filho) {
    pai->direita = filho;
}

int main() {

    No raiz = {10, NULL, NULL};
    No no20 = {20, NULL, NULL};
    No no30 = {30, NULL, NULL};

    inserirEsquerda(&raiz, &no20);
    inserirDireita(&raiz, &no30);

    printf("Raiz: %d\n", raiz.valor);

    if (raiz.esquerda != NULL)
        printf("Esquerda: %d\n", raiz.esquerda->valor);

    if (raiz.direita != NULL)
        printf("Direita: %d\n", raiz.direita->valor);

    return 0;
}