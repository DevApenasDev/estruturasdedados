/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

typedef struct No {
    int valor;
    struct No *primeiroFilho;
    struct No *proximoIrmao;
} No;

No* inicializarArvore() {
    return NULL;
}

int main() {

    No *raiz;

    raiz = inicializarArvore();

    return 0;
}