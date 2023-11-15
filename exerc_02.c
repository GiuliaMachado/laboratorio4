//Giulia de Oliveira Machado
//11202130151
#include <stdio.h>
#include <stdlib.h>

void entrada_conteudo_endereco(char *c, int n){
    for(int i =0; i<n;i++){
        printf("entrada: %d, ", i);
        printf("conteudo: %c ", c[i]);
        //imprimir ponteiro em decimal %llu
        printf("endereco: %p ", &c[i]);
        printf("\n");
        //quando der enter cancela o loop, se a entrada for maior que conteudo
        if(c[i] == '\n'){
            break;
        }
    } 
}

int main(){
    int n;
    char *palavras;
    printf("Qual o tamanho de sua string? ");
    scanf("%d", &n);
    //limpa o buffer da string
    while(getchar() != '\n');

    palavras = (char *)malloc((n+1)* sizeof(char));
    if(palavras == NULL){
        printf("Limite de memória excedido!");
        exit(1);
    }
    printf("Digite uma palavra: ");
    fgets(palavras, n+1, stdin);

    entrada_conteudo_endereco(palavras, n);
      
    free(palavras);
    return 0;
}