//Giulia de Oliveira Machado
//11202130151
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _aluno {
    int ra;
    char nome[1000];
    char sexo;
    int idade;
} AlunoStruct;

typedef AlunoStruct* Aluno;

int aluno_cmp(Aluno a, Aluno b) {
    //comparacao de strings
    if (a->ra == b->ra && strcmp(a->nome, b->nome) == 0 && a->sexo == b->sexo && a->idade == b->idade) {
        return 1; // igual
    } else {
        return 0; // diferente
    }
}

int main() {
    Aluno aluno1 = (Aluno)malloc(sizeof(AlunoStruct));
    if(aluno1 == NULL){
        printf("Nao foi possivel alocar memoria");
        exit(1);
    }
    printf("Digite o RA do aluno 1: ");
    scanf("%d", &(aluno1->ra));
    getchar();
    printf("Digite o nome do aluno 1: ");
    fgets(aluno1->nome, sizeof(aluno1->nome), stdin);
    printf("Digite o Sexo do aluno 1 (M/F): ");
    scanf("%c", &(aluno1->sexo));
    printf("Digite a idade do aluno 1: ");
    scanf("%d", &(aluno1->idade));

    Aluno aluno2 = (Aluno)malloc(sizeof(AlunoStruct));
    printf("Digite o RA do aluno 2: ");
    scanf("%d", &(aluno2->ra));
    getchar();
    printf("Digite o nome do aluno 2: ");
    fgets(aluno2->nome, sizeof(aluno2), stdin);
    printf("Digite o Sexo do aluno 2 (M/F): ");
    scanf("%c", &(aluno2->sexo));
    printf("Digite a idade do aluno 2: ");
    scanf("%d", &(aluno2->idade));

    if (aluno_cmp(aluno1, aluno2)) {
        printf("Os alunos são iguais.\n");
    } else {
        printf("Os alunos são diferentes.\n");
    }

    free(aluno1);
    free(aluno2);

    return 0;
}
