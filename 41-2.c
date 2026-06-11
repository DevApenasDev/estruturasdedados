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

int contarNos(No *raiz) {

    if (raiz == NULL)
        return 0;

    return 1 +
           contarNos(raiz->esquerda) +
           contarNos(raiz->direita);
}


int main() {

    No raiz = {10, NULL, NULL};

    No no20 = {20, NULL, NULL};
    No no30 = {30, NULL, NULL};
    No no40 = {40, NULL, NULL};
    No no50 = {50, NULL, NULL};

    inserirEsquerda(&raiz, &no20);
    inserirDireita(&raiz, &no30);

    inserirEsquerda(&no20, &no40);
    inserirDireita(&no20, &no50);

    printf("Numero de nos: %d\n", contarNos(&raiz));


    return 0;
}