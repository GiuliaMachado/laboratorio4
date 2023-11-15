//Giulia de Oliveira Machado
//11202130151
#include <stdio.h>
#include <stdlib.h>

 struct VectorI {
    void** data;
    int capacity;
    int nelements;
};
typedef struct VectorI* Vector;

Vector vector(void) {
    Vector v = (Vector)malloc(sizeof(struct VectorI));
    if (v == NULL) {
        printf("Nao foi possivel alocar memória");
        exit(1);
    }
    v->data = (void**)malloc(sizeof(void*));
    if (v->data == NULL) {
        printf("Nao foi possivel alocar memória");
        exit(1);
    }
    v->capacity = 1;
    v->nelements = 0;
    return v;
}

void vector_insert(Vector v, void* e) {
    if (v->nelements == v->capacity) {
        v->capacity *= 2;
        void** new_data = (void**)malloc(v->capacity * sizeof(void*));
        if (new_data == NULL) {
            printf("Nao foi possivel alocar memória");
            exit(1);
        }
        for (int i = 0; i < v->nelements; i++) {
            new_data[i] = v->data[i];
        }
        free(v->data);
        v->data = new_data;
    }
    v->data[v->nelements] = e;
    v->nelements++;
}

void vector_remove(Vector v, void* e) {
    int i, j;
    for (i = j = 0; i < v->nelements; i++) {
        if (v->data[i] != e) {
            v->data[j] = v->data[i];
            j++;
        }
    }
    v->nelements = j;

    if (v->nelements < v->capacity / 2) {
        v->capacity /= 2;
        void** new_data = (void**)malloc(v->capacity * sizeof(void*));
        if (new_data == NULL) {
            printf("Nao foi possivel alocar memória");
            exit(1);
        }
        for (int i = 0; i < v->nelements; i++) {
            new_data[i] = v->data[i];
        }
        free(v->data);
        v->data = new_data;
    }
}

void* vector_at(Vector v, int i) {
    if (i >= 0 && i < v->nelements) {
        return v->data[i];
    } else {
        printf("Erro: Índice fora dos limites do vetor.\n");
        exit(1);
    }
}

void vector_destroy(Vector v) {
    free(v->data);
    free(v);
}

int main() {
    // tipo inteiros
    int* a = malloc(sizeof(int));
    printf("Insira um numero: ");
    scanf("%d", a);
    int* b = malloc(sizeof(int));
    printf("Insira outro numero: ");
    scanf("%d", b);

    Vector v = vector();
    vector_insert(v, (void*)a);
    vector_insert(v, (void*)b);

    int* c = (int*)vector_at(v, 0);
    printf("Elemento na posição 0: %d\n", *c);

    vector_remove(v, (void*)a);

    printf("Elementos no vetor após remover o primeiro numero: %d\n", *(int*)vector_at(v, 0));

    vector_destroy(v);

    // tipo struct _ponto
    typedef struct {
        int x;
        int y;
    } PontoStruct;

    PontoStruct* p = malloc(sizeof(PontoStruct));
    p->x = 10;
    p->y = 11;

    Vector v_ponto = vector();
    vector_insert(v_ponto, (void*)p);

    PontoStruct* p_result = (PontoStruct*)vector_at(v_ponto, 0);
    printf("Ponto: x=%d, y=%d\n", p_result->x, p_result->y);

    vector_destroy(v_ponto);

    return 0;
}
