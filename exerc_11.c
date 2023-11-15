//Giulia de Oliveira Machado
//11202130151
#include <stdio.h>
#include <stdlib.h>

 struct VectorIntS {
    int* data;
    int capacity;
    int nelements;
} ;

typedef struct VectorIntS* VectorInt;

VectorInt vectorint(void) {
    VectorInt v = (VectorInt)malloc(sizeof(struct VectorIntS));
    if (v == NULL) {
        printf("Não foi possivel alocar memória");
        exit(1);
    }
    v->data = (int*)malloc(sizeof(int));
    if (v->data == NULL) {
        printf("Não foi possivel alocar memória");
        exit(1);
    }
    v->capacity = 1;
    v->nelements = 0;
    return v;
}

void vectorint_insert(VectorInt v, int a) {
    if (v->nelements == v->capacity) {
        v->capacity *= 2;
        int* new_data = (int*)malloc(v->capacity * sizeof(int));
        if (new_data == NULL) {
            printf("Não foi possivel alocar memória");
            exit(1);
        }
        for (int i = 0; i < v->nelements; i++) {
            new_data[i] = v->data[i];
        }
        free(v->data);
        v->data = new_data;
    }
    v->data[v->nelements] = a;
    v->nelements++;
}

void vectorint_remove(VectorInt v, int a) {
    int i, j;
    for (i = j = 0; i < v->nelements; i++) {
        if (v->data[i] != a) {
            v->data[j] = v->data[i];
            j++;
        }
    }
    v->nelements = j;

    if (v->nelements < v->capacity / 2) {
        v->capacity /= 2;
        int* new_data = (int*)malloc(v->capacity * sizeof(int));
        if (new_data == NULL) {
            printf("Não foi possivel alocar memória");
            exit(1);
        }
        for (int i = 0; i < v->nelements; i++) {
            new_data[i] = v->data[i];
        }
        free(v->data);
        v->data = new_data;
    }
}

int vectorint_at(VectorInt v, int i) {
    if (i >= 0 && i < v->nelements) {
        return v->data[i];
    } else {
        printf("Erro: Índice fora dos limites do vetor.\n");
        exit(1);
    }
}

int vectorint_contains(VectorInt v, int a) {
    int i;
    for (i = 0; i < v->nelements; i++) {
        if (v->data[i] == a) {
            return 1;
        }
    }
    return 0;
}

int vectorint_size(VectorInt v) {
    return v->nelements;
}

void vectorint_destroy(VectorInt v) {
    free(v->data);
    free(v);
}

int main() {
    VectorInt v = vectorint();
    int escolha, elemento;

    do {
        printf("\n1. Inserir elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Imprimir vetor\n");
        printf("4. Ver tamanho do vetor\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &elemento);
                vectorint_insert(v, elemento);
                break;
            case 2:
                printf("Digite o elemento a ser removido: ");
                scanf("%d", &elemento);
                vectorint_remove(v, elemento);
                break;
            case 3:
                printf("Elementos no vetor: ");
                for (int i = 0; i < vectorint_size(v); i++) {
                    printf("%d ", vectorint_at(v, i));
                }
                printf("\n");
                break;
            case 4:
                printf("Tamanho do vetor: ");
                    printf("%d", vectorint_size(v));
                
            case 0:
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (escolha != 0);

    vectorint_destroy(v);

    return 0;
}
