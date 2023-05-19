#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int vetor[], int tamanho) {
    for (int x = 0; x < tamanho - 1; x++) {
        for (int y = 0; y < tamanho - x - 1; y++) {
            if (vetor[y] > vetor[y + 1]) {
                trocar(&vetor[y], &vetor[y + 1]);
            }
        }
    }
}

int le_valida_num() {
    int num;
    do {
        printf("Digite numeros de 1 a 99 - ");
        scanf("%d", &num);
        if (num < 1 || num > 99) {
            printf("O numero deve estar entre 1 e 99.\n");
        }
    } while (num < 1 || num > 99);
    return num;
}


int main() {
    
    int nums[20], n;
    
    printf("Digite de 10 a 20 numeros\n");
    for (int x = 0; x < 20; x++) {
        if (x == 10) {
            printf( "\nVoce digitou 10 numeros.\nDeseja encerra?");
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
            printf("Digite mais numeros ou digite 's' para encerrar. ", 20-n);
        } else {
            printf("Digite o numero  %d°. ", 10-n);
        }
    }

    bubbleSort(nums, 20);
   
    printf("Numeros ordenados: ");
    for (int x = 0; x < 20; x++) {
        printf("%d ", nums[x]);
    }
   

    return 0;
}
