#include <stdio.h>

int main() {
    int valor = 42;
    int* ponteiro = &valor; 

    printf("Valor: %d\n",valor);
    printf("Endereco: %p\n", &valor);
    printf("Valor atraves do ponteiro: %d\n", *ponteiro);
    printf("Endereco do ponteiro: %p\n", ponteiro);

    *ponteiro = 100; 

    printf("Novo valor: %d\n", valor);

    return 0;
}
