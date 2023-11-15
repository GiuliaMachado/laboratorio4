//Giulia de Oliveira Machado
//11202130151
#include <stdio.h>
#include <stdlib.h>

void swap(int **p1, int **p2){
    int *t;
    t = *p1;
    *p1 = *p2;
    *p2 = t;

}
int *aloca_vetor(int n){
    int *v = (int *) malloc(n * sizeof(int));
    if(v == NULL){
        printf("Não conseguiu alocar memoria");
        exit(1);
    }
    return v;
}
void le_vetor(int *v, int n){
    printf("Digite os elementos do vetor: ");
    for(int i = 0; i< n;i++){
        scanf("%d", &v[i]);
    }
}

void imprime_vetor(int *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(){
    int *a, *b;
    int n, m;
    //1 vetor
    printf("Digite o tamanho do primeiro vetor: ");
    scanf("%d", &n);
    a = aloca_vetor(n);
    le_vetor(a, n);
    printf("Vetor a: ");
    imprime_vetor(a, n);

    //2 vetor   
    printf("Digite o tamanho do primeiro vetor: ");
    scanf("%d", &m);
    b = aloca_vetor(m);
    le_vetor(b, m);
    printf("Vetor b: ");
    imprime_vetor(b, m);

    //troca
    swap(&a, &b);
    printf("\n");
    printf("Vetor a trocado com valor de b: ");
    imprime_vetor(a, m);
    printf("Vetor b trocado com valor de a: ");
    imprime_vetor(b, n);

    free(a);
    free(b);

    return 0;
}