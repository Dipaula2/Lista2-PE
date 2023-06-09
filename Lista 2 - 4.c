#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 4
#define MAX_TURMA 4

typedef struct Aluno {
    char nome[100];
    int notas[3];
    char turma[3];
} Aluno;

int main() {
    Aluno alunos[MAX_ALUNOS];
    int i, j;
    for (i = 0; i < MAX_ALUNOS; i++) {
    printf("Informacoes do aluno %d:\n", i+1);
    printf("Nome: ");
    scanf("%s", alunos[i].nome);
    for (j = 0; j < 3; j++) {
        while (1) {
            printf("Nota %d: ", j+1);
            if (scanf("%d", &alunos[i].notas[j]) != 1) {
                printf("Digite um valor numÃŠrico.\n");
                while (getchar() != '\n');
                continue;
            }
            if (alunos[i].notas[j] < 1 || alunos[i].notas[j] > 10) {
                printf("Digite uma nota entre 1 e 10.\n");
            } else {
                break;
            }
        }
    }
    printf("Turma (A1, B2, C3 ou D4): ");
    scanf("%s", alunos[i].turma);
}

    int maior_nota = 0;
    for (i = 0; i < MAX_ALUNOS; i++) {
        int media = 0;
        for (j = 0; j < 3; j++) {
            media += alunos[i].notas[j];
        }
        media /= 3;
        if (media > maior_nota) {
            maior_nota = media;
        }
    }
    printf("Alunos com a maior nota (%d):\n", maior_nota);
    for (i = 0; i < MAX_ALUNOS; i++) {
        int media = 0;
        for (j = 0; j < 3; j++) {
            media += alunos[i].notas[j];
        }
        media /= 3;
        if (media == maior_nota) {
            printf("%s\n", alunos[i].nome);
        }
    }
    char turmas_maior_nota[MAX_TURMA][3];
    int quantidade_turma_maior_nota[MAX_TURMA];
    int k = 0;
    for (i = 0; i < MAX_ALUNOS; i++) {
        int media = 0;
        for (j = 0; j < 3; j++) {
            media += alunos[i].notas[j];
        }
        media /= 3;
        if (media == maior_nota) {
            int existe = 0;
            for (j = 0; j < k; j++) {
                if (strcmp(turmas_maior_nota[j], alunos[i].turma) == 0) {
                    existe = 1;
                    break;
                }
            }
            if (!existe) {
                strcpy(turmas_maior_nota[k], alunos[i].turma);
                quantidade_turma_maior_nota[k] = 1;
                k++;
            } else {
                quantidade_turma_maior_nota[j]++;
            }
        }
    }
    printf("Turmas com alunos de maior nota: ");
    for (i = 0; i < k; i++) {
        printf("%s", turmas_maior_nota[i]);
        if (i < k-1) {
            printf(", ");
        }
    }
    printf("\n");
    for (i = 0; i < k; i++) {
        printf("Quantidade de alunos com a maior nota na turma %s: %d\n", turmas_maior_nota[i], quantidade_turma_maior_nota[i]);
    }
    return 0;
}
 
#