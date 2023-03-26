/*
ENUNCIADO
    Implemente um programa que compute todas as soluções de equações do tipo
                    x1 + x2 + x3 + x4 = C
    onde todas as variáveis x1,...,x4 são inteiras não negativas e C > 0 é uma constante
    inteira. Melhore o seu programa com as seguinte idéias.
                • Fixado x1, os valores possíveis para x2 são 0,...,C -x1. Fixado x1 e x2, os valores
                possíveis para x3 são 0,...,C -x1 -x2. Fixados x1, x2, e x3, então x4 é unicamente
                determinado.

*/


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x1=0,x2=0,x3=0,x4=0,valor_c,quant_valores,i=1;

    printf("Selecione o valor de C que deseja analisar.\n");
    scanf("%d",&valor_c);

    printf("\n\nAgora selecione quantos valores (de 1 a 3) gostaria de ser preenchidos.\n");
    scanf("%d",&quant_valores);



    if (quant_valores ==1){
        printf("\n\nSelecione seu X1; para obter X2\n");
        scanf("%d",&x1);
    }else if (quant_valores ==2){
        printf("\n\nSelecione seus X1 e X2; para obter X3\n");
        scanf("%d %d",&x1, &x2);
    }else if (quant_valores ==3){
        printf("\n\nSelecione seus X1 , X2 e X3; para obter X4\n");
        scanf("%d %d %d",&x1, &x2, &x3);
    }
    for (i=0; i<valor_c;i++){
        if (quant_valores ==1){
            if(i==(valor_c-x1)){
                x2=i;
            }
        }else if (quant_valores ==2){
            if(i==(valor_c-(x1+x2))){
                x3=i;
            }
        }else if (quant_valores ==3){
            if(i==(valor_c-(x1+x2+x3))){
                x4=i;
            }
        }

    }

    printf("Os valores finais de X1,\tX2,\tX3,\tX4:\t %d,\t%d,\t%d,\t%d.", x1,x2,x3,x4);

}
