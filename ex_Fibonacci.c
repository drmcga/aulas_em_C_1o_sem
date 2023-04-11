/*
ENUNCIADO

    Digitar n valores da sequencia de Fibonacci.
        A serie Fibonacci:
        1 1 2 3 5 8 13 21 34 55
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    //bloco de declacores.
    //nesse modelo, o valor A sempre esta na frente do valor B.
    int valor_a=1,    valor_b=1,    valor_n,    valor_temp=0;
    
    //bloco de explicacao
    printf("Digite quantos digitos Fibonacci gostaria de imprimir.\n");

    //bloco de chamamento
    scanf("%d",&valor_n);

    //for loop
    for (int i=1    ; i<=valor_n    ; i++){
      
        printf("%2d : %10d\n",i,valor_b);

        valor_temp=valor_a;
        valor_a +=valor_b;
        valor_b  =valor_temp;
    }

    return 0;
}
