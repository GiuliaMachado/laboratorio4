//Giulia de Oliveira Machado
//11202130151
#include <stdio.h>
#include <stdlib.h>

void inc(int *x){
    (*x) = *x +1;
}

int main(){
    int a;
    printf("Digite um número: ");
    scanf("%d", &a);
    inc(&a);
    printf("Valor do numero incrementado: %d", a);
    return 0;
}