/*

ENUNCIADO

    Escreva um programa para ler n de números do tipo float e imprimir quantos deles estão
    nos seguintes intervalos: [0 ... 25], [26 ... 50], [51 ... 75] e [76 ... 100]. Por exemplo, para
    n = 10 e os seguintes dez números 2.0, 61.5, 1.0, 0.0, 88.7, 94.5, 55.0, 3.1415, 25.5, 75.0,
    seu programa deve imprimir:

        Intervalo [0..25]: 3
        Intervalo [26..50]: 0
        Intervalo [51..75]: 3
        Intervalo [76..100]: 2

*/


#include <stdio.h>
#include <stdlib.h>

int main()
{

    int quantidade_valores, valor_atual, inter_25=0, inter_50=0,inter_75=0,inter_100=0;

    printf("\nInsira quantos valores deseja analisar");
    scanf("%d",&quantidade_valores);

    for (int i=1;i<=quantidade_valores;i++){
        printf("\nInsira o %do valor: \t\n",i);
        scanf("%d",&valor_atual);
        if(valor_atual<=25&&valor_atual>0){
            inter_25++;
        }else if(valor_atual>25&&valor_atual<=50){
            inter_50++;
        }else if(valor_atual>50&&valor_atual<=75){
            inter_75++;
        }else if(valor_atual>75&&valor_atual<=100){
            inter_100++;
        }

    }
    printf("\nIntervalo [0..25]: %d\nIntervalo [26..50]: %d\nIntervalo [51..75]: %d\nIntervalo [76..100]: %d",inter_25,inter_50,inter_75,inter_100);

    return 0;
}