/*
ENUNCIADO
    Desenvolva um analisador de lancamento de 6 Icosaedros (dados de 20 lados)
    que forneca os lancamentos que contenham apenas numeros primos, desconsiderando repeticoes.
*/

#include <stdio.h>
#include <stdlib.h>

//ve se o numero inserido e primo
int is_primo(int valor_n){

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

    int cont=0;

    /*     //bloco de teste de primos
    for (int i=1; i<=20;i++){
        printf("%d : %d\n",i,is_primo(i));
    }
    */

    printf("  Todas as possibilidades de lancamentos para 6 Icosaedros,\n em que todos os valores obtidos sao primos e distintos entre si:\n\n[");
    for (int i=1; i<=20; i++){
        for (int j=i+1; j<=20; j++){
            for (int m=j+1; m<=20; m++){
                for (int n=m+1; n<=20; n++){
                    for (int r=n+1; r<=20; r++){
                        for (int s=r+1; s<=20; s++){

                            if(is_primo(i) && is_primo(j) &&
                               is_primo(m) && is_primo(n) &&
                               is_primo(r) && is_primo(s)) {

                                if ((cont%4)==0 && cont!=0){
                                    printf("\n\t");
                                }else {
                                    printf("\t");
                                }

                                printf("%2d %2d %2d %2d %2d %2d,",i,j,m,n,r,s);
                                cont++;
                                }
                        }
                    }
                }
            }
        }
    }

    printf("\b ]\n");




    return 0;
}
