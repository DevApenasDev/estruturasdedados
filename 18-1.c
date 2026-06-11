#include <stdio.h>

typedef struct No {
    int valor;
    struct No *primeiroFilho;
    struct No *proximoIrmao;
} No;

void inserirFilho(No *pai, No *filho) {

    if (pai->primeiroFilho == NULL) {
        pai->primeiroFilho = filho;
    }
    else {

        No *aux = pai->primeiroFilho;

        while (aux->proximoIrmao != NULL) {
            aux = aux->proximoIrmao;
        }

        aux->proximoIrmao = filho;
    }
}

int main() {

    No raiz = {10, NULL, NULL};
    No filho1 = {20, NULL, NULL};
    No filho2 = {30, NULL, NULL};
    No filho3 = {40, NULL, NULL};

    inserirFilho(&raiz, &filho1);
    inserirFilho(&raiz, &filho2);
    inserirFilho(&raiz, &filho3);

    printf("Raiz: %d\n", raiz.valor);

    No *aux = raiz.primeiroFilho;

    while (aux != NULL) {
        printf("Filho: %d\n", aux->valor);
        aux = aux->proximoIrmao;
    }

    return 0;
}