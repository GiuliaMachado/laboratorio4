//Giulia de Oliveira Machado
//11202130151
#include <stdio.h>
#include <stdlib.h>

int media(int *v, int n){
    int media = 0;
    for(int i = 0; i<n; i++){
        media += v[i];
    }
    return media/n;
}
int main(){
    int n, *v;
    printf("Digite o numero de elementos do vetor: ");
    scanf("%d", &n);

    v = malloc(n * sizeof(int));
    if(v == NULL){
        printf("Limite de memória excedido!");
        exit(1);
    }

    printf("Digite os elementos do vetor: ");
    for(int i = 0; i<n; i++){
        scanf("%d", &v[i]);
    }
    printf("%d", media(v, n));
    free(v);
    return 0; 
}
