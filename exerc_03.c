//Giulia de Oliveira Machado
//11202130151
#include <stdio.h>
#include <stdlib.h>

void entrada_conteudo_endereco(int *v, int n){
    for(int i = 0; i<n; i++){
        printf("entrada: %d, ", i);
        printf("conteudo: %d, ", v[i]);
        printf("endereco: %p, ", &v[i]);
        printf("\n");
    }
}

int main(){
    int n, *v;
    printf("Digite o numero de elementos do vetor: ");
    scanf("%d ", &n);
    v = malloc( n* sizeof(int));
    if(v == NULL){
        printf("Limite de memoria excedido");
        exit(1);
    }
    printf("Digite os numeros: ");
    for(int i =0; i<n; i++){
        scanf("%d", &v[i]);
    }

    entrada_conteudo_endereco(v, n);
    free(v);

    return 0;
}