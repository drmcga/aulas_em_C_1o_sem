/*

ENUNCIADO

Considere o programa para determinar se uma sequência de n números digitados pelo
usuário está ordenada ou não. Faça o programa usando uma variável contadora.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_de_valores,num_atual,num_anterior,i,crescente=0;
    
    
    printf("Digite o numero de valores que gostaria de verificar se estão na ordem crescente ou nao.\n\n");
    scanf("%d",&num_de_valores);
    num_anterior=-2147483647;
    
    
    for (i=1;i<=num_de_valores;i++){
        
        printf("\nDigite agora o %do valor\t\t",i);
        scanf("%d",&num_atual);

        if (num_anterior>num_atual){
            crescente++;
            
        }
        num_anterior=num_atual;
    }
    
    if(crescente>0){
        printf("\nMe parece que nao esta na ordem! Pelo menos %d elementos estao fora de ordem aparente", crescente);
    }else{
        printf("\nMe parece que esta em ordem, parabens");
    }

    return 0;
}