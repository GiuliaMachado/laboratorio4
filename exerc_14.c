//Giulia de Oliveira Machado
//11202130151
#include <stdio.h>
#include <stdlib.h>
//explicacao das funcoes: soma um elemento do indice da frente com o anterior
int multiplicacao(int a, int b){
    return a * b;
}
int soma(int a, int b){
    return a + b;
}
int sub(int a, int b){
    return a - b;
}

int* aloca_vetor(int n) {
    int* v = (int*)malloc(n * sizeof(int));
    if (v == NULL) {
        printf("Não conseguiu alocar memoria");
        exit(1);
    }
    return v;
}

int* map(int array[], int n, int func(int, int)) {
    int* v;
    v = aloca_vetor(n);
    for (int i = 0; i < n - 1; i++) {
        v[i] = func(array[i], array[i + 1]);
    }
    return v;
}

int main() {
    int* v, * resultado, n, escolha;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    v = aloca_vetor(n);

    printf("Digite os elementos do vetor: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    
    printf("1. Soma\n");
    printf("2. Multiplicacao\n");
    printf("3. Subtracao\n");
    printf("Escolha a operacao: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            resultado = map(v, n, soma);
            printf("Apos usar a funcao de soma:\n");
            break;
        case 2:
            resultado = map(v, n, multiplicacao);
            printf("Apos usar a funcao de multiplicacao:\n");
            break;
        case 3:
            resultado = map(v, n, sub);
            printf("Apos usar a funcao de subtracao:\n");
            break;
        default:
            printf("Opcao invalida.\n");
            return 1;
    }

    for (int i = 0; i < n - 1; i++) {
        printf("Resultado da posicao %d com %d : %d\n", i, i + 1, resultado[i]);
    }

    free(v);
    free(resultado);

    return 0;
}