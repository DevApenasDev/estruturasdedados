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

int contarNos(No *raiz) {

    if (raiz == NULL) {
        return 0;
    }

    int total = 1;

    No *aux = raiz->primeiroFilho;

    while (aux != NULL) {
        total += contarNos(aux);
        aux = aux->proximoIrmao;
    }

    return total;
}

int altura(No *raiz) {

    if (raiz == NULL) {
        return -1;
    }

    int maior = -1;

    No *aux = raiz->primeiroFilho;

    while (aux != NULL) {

        int h = altura(aux);

        if (h > maior) {
            maior = h;
        }

        aux = aux->proximoIrmao;
    }

    return maior + 1;
}

int contarFolhas(No *raiz) {

    if (raiz == NULL) {
        return 0;
    }

    if (raiz->primeiroFilho == NULL) {
        return 1;
    }

    int total = 0;

    No *aux = raiz->primeiroFilho;

    while (aux != NULL) {
        total += contarFolhas(aux);
        aux = aux->proximoIrmao;
    }

    return total;
}

int existeValor(No *raiz, int valor) {

    if (raiz == NULL) {
        return 0;
    }

    if (raiz->valor == valor) {
        return 1;
    }

    No *aux = raiz->primeiroFilho;

    while (aux != NULL) {

        if (existeValor(aux, valor)) {
            return 1;
        }

        aux = aux->proximoIrmao;
    }

    return 0;
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

    printf("Total de nos: %d\n", contarNos(&raiz));
    printf("Altura da arvore: %d\n", altura(&raiz));
    printf("Quantidade de folhas: %d\n", contarFolhas(&raiz));

    if (existeValor(&raiz, 30)) {
        printf("Valor 30 encontrado.\n");
    } else {
        printf("Valor 30 nao encontrado.\n");
    }

    return 0;
}