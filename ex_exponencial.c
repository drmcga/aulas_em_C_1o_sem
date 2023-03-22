/*
    ENUNCIADO

    Faça um programa que lê dois números inteiros positivos a e b. Utilizando laços, o seu
    programa deve calcular e imprimir o valor a^b.

    utilizando somente loops
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int base, valor_a, valor_b,i;

    printf("Escolha 2 valores, separados por " ", o primeiro sera a BASE NUMERICA INTEIRA, e o segundo sera o EXPOENTE\n\n");

    scanf("%d %d",&valor_a,&valor_b);
    base=valor_a;

    for (i=1;i<valor_b;i++){

        valor_a*=base;

    }

    printf("%d",valor_a);

    return 0;
}