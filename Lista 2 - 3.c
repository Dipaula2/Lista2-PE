#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int vetor[], int tamanho) {
    int x, y, min;
    for (x = 0; x < tamanho-1; x++) {
        min = x;
        for (y = x+1; y < tamanho; y++) {
            if (vetor[y] < vetor[min]) {
                min = y;
            }
        }
        trocar(&vetor[min], &vetor[x]);
    }
}

void selectionSortDecr(int vetor[], int tamanho) {
    int x, y, max;
    for (x = 0; x < tamanho - 1; x++) {
        max = x;
        for (y = x + 1; y < tamanho; y++) {
            if (vetor[y] > vetor[max]) {
                max = y;
            }
        }
        trocar(&vetor[max], &vetor[x]);
    }
}


int le_valida_num() {
    int num;
    do {
        printf("Digite numeros de 1 a 99 - ");
        scanf("%d", &num);
        if (num < 1 || num > 99) {
            printf("O numero deve estar entre 1 e 99.\n");
        } else if (num % 2 != 0) {
            printf("O numero deve ser par.\n");
        } else if (num % 5 == 0) {
            printf("O numero nao pode ser multiplo de 5.\n");
        }
    } while (num < 1 || num > 99 || num % 2 != 0 || num % 5 == 0);
    return num;
}

int main() {
    int nums[10], n;
    printf("Digite de 2 a 10 numeros.\n");
    for (int x = 0; x < 10; x++) {
        if (x == 2) {
            printf("\nVoce digitou 2 numeros.\nDeseja encerrar(s/n)?");
            char sair;
            scanf(" %c", &sair);
            if (sair == 's' || sair == 'S') {
                n = x;
                break;
            }
        }
        nums[x] = le_valida_num();
        n = x + 1;
        if (n >= 2) {
            printf("", 10 - n);
        } else {
            printf("Digite o %dÂ° numero.", n, 2 - n);
        }
    }

    selectionSort(nums, n);

    printf("\nNumeros ordenados em ordem crescente: ");
    for (int x = 0; x < n; x++) {
        printf("%d ", nums[x]);
    }
    
    selectionSortDecr(nums, n);
    
    printf("\nNumeros ordenados em ordem decresente: ");
    for (int x = 0; x < n; x++) {
        printf("%d ", nums[x]);
    }

    return 0;
}