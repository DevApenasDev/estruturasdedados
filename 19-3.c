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

void emOrdem(No *raiz) {

    if (raiz == NULL)
        return;

    emOrdem(raiz->esquerda);
    printf("%d ", raiz->valor);
    emOrdem(raiz->direita);
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

int validarABB(No *raiz, int min, int max) {

    if (raiz == NULL)
        return 1;

    if (raiz->valor <= min || raiz->valor >= max)
        return 0;

    return validarABB(raiz->esquerda, min, raiz->valor) &&
           validarABB(raiz->direita, raiz->valor, max);
}

int altura(No *raiz) {

    if (raiz == NULL)
        return -1;

    int esq = altura(raiz->esquerda);
    int dir = altura(raiz->direita);

    if (esq > dir)
        return esq + 1;

    return dir + 1;
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

    int opcao;

    do {

        printf("\n===== MENU ABB =====\n");
        printf("1 - Mostrar em ordem\n");
        printf("2 - Menor valor\n");
        printf("3 - Maior valor\n");
        printf("4 - Validar ABB\n");
        printf("5 - Contar niveis\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:
                printf("ABB em ordem: ");
                emOrdem(&raiz);
                printf("\n");
                break;

            case 2:
                printf("Menor valor: %d\n", menor(&raiz));
                break;

            case 3:
                printf("Maior valor: %d\n", maior(&raiz));
                break;

            case 4:

                if (validarABB(&raiz, -9999, 9999))
                    printf("A arvore e uma ABB valida.\n");
                else
                    printf("A arvore NAO e uma ABB valida.\n");

                break;

            case 5:
                printf("Quantidade de niveis: %d\n", altura(&raiz) + 1);
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}