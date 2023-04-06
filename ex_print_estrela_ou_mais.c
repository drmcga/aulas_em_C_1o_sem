/*
ENUNCIADO

            Faça um programa que leia um número n e imprima n linhas na tela com o seguinte
        formato (exemplo se n = 6):

                                    +*****
                                    *+****
                                    **+***
                                    ***+**
                                    ****+*
                                    *****+


*/


#include <stdio.h>
#include <stdlib.h>

int main()
{
    //declarar variaveis
    int n_linhas;

    //apresentar o programa
    printf("Digite um valor N para imprimir um bloco ASCII no seguinte formato:\n\n\t\t+***\n\t\t*+**\n\t\t**+*\n\t\t***+\n\n\t(EXEMPLO N=4)\n\n\t");

    //puxar o input
    scanf("%d",&n_linhas);

    //logica matricial simples
    for (int i=1;i<=n_linhas;i++){
        for (int j=1;j<=n_linhas;j++){
            if(j==i){
                printf("+");
            }else{
                printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}
