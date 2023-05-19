#include <stdio.h>

int main() {
    int valor = 42;
    int* ponteiro = &valor; 

    printf("Valor: %d\n",valor);
    printf("EndereÃ§o: %p\n", &valor);
    printf("Valor atravÃ©s do ponteiro: %d\n", *ponteiro);
    printf("EndereÃ§o do ponteiro: %p\n", ponteiro);

    *ponteiro = 100; 

    printf("Novo valor: %d\n", valor);

    return 0;
}