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

int altura(No *raiz) {

    if (raiz == NULL)
        return -1;

    int altEsq = altura(raiz->esquerda);
    int altDir = altura(raiz->direita);

    if (altEsq > altDir)
        return altEsq + 1;

    return altDir + 1;
}

int contarFolhas(No *raiz) {

    if (raiz == NULL)
        return 0;

    if (raiz->esquerda == NULL &&
        raiz->direita == NULL)
        return 1;

    return contarFolhas(raiz->esquerda) +
           contarFolhas(raiz->direita);
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

    printf("Altura da arvore: %d\n", altura(&raiz));

    printf("Quantidade de folhas: %d\n", contarFolhas(&raiz));

    return 0;
}