/*
ENUNCIADO

     Dada uma sequencia de n numeros, imprimi-la na ordem inversa à da leitura.

*/


#include <stdio.h>
#include <stdlib.h>



int main(){

    //declaracao de variaveis iniciais
    int comp_n,temp;
    printf("\nEscolha um tamanho para sua lista\n\t\t");

    
    //declaracao da lista
    scanf("%d",&comp_n);
    int lista[comp_n];
    putchar('\n');

    //loop para obtencao dos elementos da lista
    for (int i=0;i<comp_n;i++){
        printf("\tEscolha agora o item [%2d] da lista: ",i);
        scanf("%d",&temp);
        lista[i]=temp;
    }

    
    //loop para realizacao da inversao da lista
    printf("\nEis sua lista: [ ");
    for (int i=comp_n-1; i>=0; i--){
        printf("%2d, ", lista[i]);
    }
    printf("\b\b ]\n");


    return 0;
}

