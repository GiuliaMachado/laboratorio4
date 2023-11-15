//Giulia de Oliveira Machado
//11202130151
#include <stdio.h>
#include <stdlib.h>

int* matriz(int n, int m){
    int *mat;  
    int tam = n * m;
    mat = (int *) malloc(tam * sizeof(int));
    if(mat == NULL){
        printf("Nao tem memoria suficiente");
        exit(1);
    }

    for(int i = 0; i < tam; i++){
            scanf("%d", &mat[i]);     
    }
    return mat;
}
void imprime(int *mat, int n, int m){
    printf("Matriz: \n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            //aritmetica de ponteiros
            printf("%d ", mat[i * m + j]);
        }
        printf("\n");
    }
}

int main(){
    int *mat;
    int n, m;
    printf("Digite o numero de linhas: ");
    scanf("%d", &n);
    printf("Digite o numero de colunas: ");
    scanf("%d", &m);
    mat = matriz(n, m);
    imprime(mat, n, m);

    free(mat);

    return 0;
}