/*
ENUNCIADO

    Desenvolva um analisador de lancamento de 6 Icosaedros (dados de 20 lados)
    que forneca os lancamentos que contenham apenas numeros primos, desconsiderando repeticoes.

*/

#include <stdio.h>
#include <stdlib.h>

//ve se o numero inserido e primo
int is_primo(valor_n){

    if (valor_n==1) return 0;

    for (int i=2; i<valor_n; i++){
        if (valor_n%i==0) {
            //divisor encontrado
            return 0;
        }
    }
    return 1;
}


int main()
{

    for (int i=1; i<=20;i++){
        printf("%d : %d\n",i,is_primo(i));
    }





    return 0;
}



