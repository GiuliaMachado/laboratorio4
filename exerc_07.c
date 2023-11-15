//Giulia de Oliveira Machado
//11202130151
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *aloca_vetor(int n);
char *strcat_m(char *a, char *b);

char *strcat_m(char *a, char *b){
    int tam_a = strlen(a);
    int tam_b = strlen(b);
    int tam_c = tam_a + tam_b +1;
    char *c = aloca_vetor(tam_c);

    for(int i = 0; i <tam_a;i++){
        c[i] = a[i];
    }

    for(int i = 0; i < tam_b; i++){
        c[tam_a + i] = b[i];
    }
    c[tam_c - 1] = '\0';
    return c;
}
char *aloca_vetor(int n){
    char *a = (char *)malloc((n+1) * sizeof(char));
    if(a == NULL){
        printf("Não conseguiu alocar memoria");
        exit(1);
    }
    return a;
}

int main(){
    char *a, *b, *resultado;
    int n, m;
    //primeira string
    printf("Digite o tamanho de sua string: ");
    scanf("%d", &n);
    getchar();
    a = aloca_vetor(n);
    printf("Digite a string: ");
    fgets(a, n+1, stdin);

    //segunda string
    printf("Digite o tamanho de sua string: ");
    scanf("%d", &m);
    getchar();
    b = aloca_vetor(m);
    printf("Digite a string: ");
    fgets(b, m+1, stdin);

    resultado = strcat_m(a, b);

    printf("%s", resultado);

    free(a);
    free(b);
    free(resultado);

    return 0;
}