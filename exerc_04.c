//Giulia de Oliveira Machado
//11202130151
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int a, b;
    printf("Digite um numero: ");
    scanf("%d", &a);
    printf("Digite outro numero: ");
    scanf("%d", &b);
    printf("\n");
    printf("Valor de a declarado: %d\n", a);
    printf("Valor de b declarado: %d\n", b);
    swap(&a, &b);
    printf("\n");
    printf("\nValor de a apos a troca: %d\n", a);
    printf("Valor de b apos a troca: %d", b);
    
    return 0;
}