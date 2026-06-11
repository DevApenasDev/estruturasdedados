#include <stdio.h>

typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

int main() {

    No raiz = {10, NULL, NULL};

    printf("Raiz: %d\n", raiz.valor);

    return 0;
}