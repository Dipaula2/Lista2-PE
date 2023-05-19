#include <stdio.h>
#include <stdlib.h>

// funcao que recebe um parametro por valor
void passarValor(int num) {
    num += 10;  // Modifica apenas o valor local da variavel num
    printf("Dentro da funcao (por valor): %d\n", num);
}

// funcao que recebe um parametro por referencia
void passarReferencia(int *list) {
    list[3] = 4;  // Modifica o objeto referenciado pela lista
    printf("Dentro da funcao (por referencia): %d\n", list[3]);
}

int main() {
    // Exemplo de passagem por valor
    int x = 5;
    printf("Antes da funcao (por valor): %d\n", x);
    passarValor(x);
    printf("Depois da funcao (por valor): %d\n", x);
    printf("\n");

    // Exemplo de passagem por referencia
    int *lista = (int *) malloc(4 * sizeof(int));
    lista[0] = 1;
    lista[1] = 2;
    lista[2] = 3;
    printf("Antes da funcao (por referencia): %d\n", lista[3]);
    passarReferencia(lista);
    printf("Depois da funcao (por referencia): %d\n", lista[3]);
    free(lista);
    return 0;
}