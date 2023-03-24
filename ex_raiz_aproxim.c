/*

ENUNCIADO

    Escreva um programa em C para computar a raiz quadrada de um número positivo. Use
    a idéia abaixo, baseada no método de aproximações sucessivas de Newton. O programa
    deverá imprimir o valor da vigésima aproximação.

        Seja Y um número, sua raiz quadrada é raiz da equação

            f(x) = x^2 - Y.

        A primeira aproximação é X<1> = (Y/2)   . A <n+1>-ésima aproximação é

                                f( X<n> )
            X<n+1>  =    X<n> - __________
                                f'( X<n> )

.
*/


#include <stdio.h>
#include <stdlib.h>

int main()
{
    float valor_Y, valor_anterior, temp;

    printf("Escolha um valor Y que deseja obter a raiz quadrada.");
    scanf("%f"&valor_Y);

    valor_anterior=valor_Y/2;

    for(int i=1;i<20;i++){
        temp=valor_anterior - (valor_anterior)/(valor_anterior*2);




}
