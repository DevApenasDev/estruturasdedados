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
int buscarABB(No *raiz, int valor) {

    if (raiz == NULL)
        return 0;

    if (raiz->valor == valor)
        return 1;

    if (valor < raiz->valor)
        return buscarABB(raiz->esquerda, valor);

    return buscarABB(raiz->direita, valor);
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
    No no20 = {20, NULL, NULL};
    No no40 = {40, NULL, NULL};

    inserirABB(&raiz, &no30);
    inserirABB(&raiz, &no70);
    inserirABB(&raiz, &no20);
    inserirABB(&raiz, &no40);

    printf("ABB criada.\n");
    if (buscarABB(&raiz, 40))
        printf("Valor encontrado.\n");
    else
        printf("Valor nao encontrado.\n");
    printf("Em ordem: ");
        emOrdem(&raiz);
    return 0;
    
}