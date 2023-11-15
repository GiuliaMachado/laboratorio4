//Giulia de Oliveira Machado
//11202130151
#include <stdio.h>
#include <stdlib.h>

int *cartesiano(int *v1, int *v2, int n1, int n2){
    int *resultado = NULL;
    int cont =0;
    resultado = (int *)malloc(n1 * n2 * sizeof(int));
    if(resultado == NULL){
        printf("Nao foi possivel alocar memoria.");
        exit(1);
    }
    for(int i = 0; i< n1; i++){
        for(int j = 0; j < n2; j++){
            resultado[cont] = v1[i] * v2[j];
            cont++;
        }
    }
    return resultado;
}
int main(){
    int *v1, *v2, *resultado, n1, n2;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n1);
    v1 = (int *) malloc(n1 * sizeof(int));
    if(v1 == NULL){
        printf("Nao foi possivel alocar memoria.");
        exit(1);
    }
    printf("Digite os elementos do primeiro vetor: ");
    for(int i = 0; i < n1; i++){
        scanf("%d", &v1[i]);
    }

    printf("Digite o tamanho do segundo vetor: ");
    scanf("%d", &n2);
    v2 = (int *) malloc(n2 * sizeof(int));
    if(v2 == NULL){
        printf("Nao foi possivel alocar memoria.");
        exit(1);
    }
    printf("Digite os elementos do primeiro vetor: ");
    for(int i = 0; i < n2; i++){
        scanf("%d", &v2[i]);
    }

    printf("Produto Cartesiano: ");
    resultado = cartesiano(v1, v2, n1, n2);
    for(int i =0; i < n1 * n2; i++){
        printf("%d ", resultado[i]);
    }

    free(v1);
    free(v2);
    free(resultado);
    return 0;
}