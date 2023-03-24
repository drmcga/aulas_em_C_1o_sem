/*

ENUNCIADO

    Faça um programa em C que calcule o máximo divisor comum de dois números m, n. Você
    deve utilizar a seguinte regra do cálculo do mdc com m >= n

                    1    mdc(m, n) = m se n = 0
             2   mdc(m, n) = mdc(n, m%n) se n > 0
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valor_m,valor_n,temp,i,mdc=1,original_m,original_n;

    printf("\tDigite dois numeros, M e N, para encontrar seu MAXIMO DIVISOR COMUM\n\n\t\t");
    scanf("%d %d", &valor_m,&valor_n);

    //usados para o print final:
    original_m=valor_m;
    original_n=valor_n;

    //certificar de que M > N:
    if (valor_m<valor_n){
        temp=valor_n;
        valor_n=valor_m;
        valor_m=temp;
    }
    //regra numero 2
    while (valor_n!=0){
        temp=valor_n;
        valor_n=valor_m%valor_n;
        valor_m=temp;
    }
    //regra numero 1, que é uma consequencia da regra 2
    mdc=valor_m;

    printf("\n\tO Maior Divisor Comum entre %d e %d e: %d\n\n",original_m,original_n,mdc);

    return 0;
}
