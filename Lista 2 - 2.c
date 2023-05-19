#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(int vetor[], int tamanho) {
    int x, y, atual;
    for (x = 1; x < tamanho; x++) {
        atual = vetor[y];
        for (y = x - 1; y >= 0 && atual > vetor[y]; y--) {
            vetor[y + 1] = vetor[y];
        }
        vetor[y + 1] = atual;
    }
}

int le_valida_num() {
    int num;
    do {
        printf("Digite numeros de 1 a 99 - ");
        scanf("%d", &num);
        if (num < 1 || num > 99) {
            printf("O numero deve estar entre 1 e 99.\n");
        } else if (num % 2 == 0) {
            printf("O numero deve ser impar.\n");
        } else if (num % 3 == 0) {
            printf("O numero nao pode ser multiplo de 3.\n");
        }
    } while (num < 1 || num > 99 || num % 2 == 0 || num % 3 == 0);
    return num;
}

int main() {
    int nums[20], n;
    printf("Digite de 10 a 20 numeros.\n");
    for (int x = 0; x < 20; x++) {
        if (x == 10) {
            printf("\nVoce digitou 10 numeros.\nDeseja encerrar(s/n)?");
            char sair;
            scanf(" %c", &sair);
            if (sair == 's' || sair == 'S') {
                n = x;
                break;
            }
        }
        nums[x] = le_valida_num();
        n = x + 1;
        if (n >= 10) {
            printf("", 20 - n);
        } else {
            printf("Digite o %dÂ° numero.", n, 10 - n);
        }
    }

    insertionSort(nums, n);

    printf("\nNumeros ordenados em ordem decrescente: ");
    for (int x = 0; x < n; x++) {
        printf("%d ", nums[x]);
    }

    return 0;
}