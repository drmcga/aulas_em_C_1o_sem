/*
    ENUNCIADO

    Desenvolva uma funcao que realiza uma troca entre os dois inteiros inseridos.


*/
#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b){

    int temp=*a;
    *a=*b;
    *b=temp;

}


int main()
{

    int valor_a, valor_b;

    printf("\nPara realizar a troca, insira dois numeros inteiros:\n\t\t");
    scanf("%d %d",&valor_a,&valor_b);
    putchar('\n');

    printf("Valores inseridos antes da troca: \tA=%4d e B=%4d\n",valor_a, valor_b);
    troca(&valor_a, &valor_b);
    printf("Valores inseridos apos a troca: \tA=%4d e B=%4d\n",valor_a, valor_b);

    return 0;
}
