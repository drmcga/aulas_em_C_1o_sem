/*

ENUNCIADO

        Escreva um programa que lê um número n, e então imprime o menor número primo que é
        maior ou igual n, e imprime o maior primo que é menor ou igual a n.

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valor_n,primo_maior=0,primo_menor=1,i,j,fator;

    printf("\tDigite um numero N, para obter o ultimo numero primo anterior a ele, ou ele mesmo, e o primeiro que o sucede\n\n\t\t");
    scanf("%d", &valor_n);

    //verificacao do anterior
    for (i=1;i<=valor_n;i++){
        fator=0;
        for (j=1;j<=i;j++){
            if (i%j==0){
                fator++;
            }
        }

        if (fator==2){
            primo_menor=i;
        }

    }
    
    //verificacao do proximo
    i=valor_n+1;

    while (primo_maior==0){
        fator=0;
        for (j=1;j<=i;j++){
            if (i%j==0){
                fator++;
            }
        }
        
        if (fator==2){
            primo_maior=i;
        }
        i++;
    }

    printf("\n\tO primo anterior: %d\tO numero: %d\tO proximo primo: %d",primo_menor,valor_n,primo_maior);

    return 0;
}
