/*
ENUNCIADO

           Faça um programa que leia um número n e imprima n linhas na tela com o seguinte
    formato (exemplo se n = 6):

                1
                1 2
                1 2 3
                1 2 3 4
                1 2 3 4 5
                1 2 3 4 5 6

*/


#include <stdio.h>
#include <stdlib.h>

int main(){

    //declarar variaveis
    int n_linhas;

    //explicar o proposito
    printf("Digite um numero N para obter um print no formato ASCII de:\n\n\t1\n\t1 2\n\t1 2 3\n\t. . . . \n\t. . . . .\n\t1 . . . . n\n\n\t");

    //chamar o input
    scanf("%d", &n_linhas);

    //bloco de laco
    printf("\n\n");
    for (int i=1; i<=n_linhas; i++){
        printf("\t");
        for (int j=1; j<=i; j++){
            if(j<i){
                printf("%d ",j);
            }else{
                printf("%d \n",j);
            }
        }
    }
    printf("\n\n");

    return 0;
}
