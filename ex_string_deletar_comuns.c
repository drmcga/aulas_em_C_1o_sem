/*
 *       ENUNCIADO
 *
 *      Faça um programa que leia duas strings e elimine, da segunda string, todas as ocorrências
 *      dos caracteres da primeira string.
 *
*/
#include <stdio.h>
#include <stdlib.h>

int main(){

    //enunciacao das variaveis das palavras
    char palavra_a[99], palavra_b[99];

    //variaveis auxiliares
    int cont_a=0, cont_b=0, deletes=0;

    //anuncio da funcao do codigo
    printf("\n Esse codigo permite eliminar todas as ocorrencias de caracteres de uma string para outra");
    printf("\n Sua primeira string e o elemento de delecao, a segunda string e o seu alvo para delecao.\n\n");

    //input das strings
    //achei essa solucao interessante
    for (int i=0;i<2;i++){
        printf("\t- Sua %da string: ",i+1);
        if (!i) gets(palavra_a);
        else gets(palavra_b);
    }

    //contador automatico de comprimento de strings
    for (cont_a; palavra_a[cont_a]!='\0'; cont_a++){}
    for (cont_b; palavra_b[cont_b]!='\0'; cont_b++){}


    //loop principal
    //ele percorre A, e a cada etapa de A, percorre B inteiro
        //se B tiver elementos igual a etapa de A, sao substituidos por ' '.
        //e soma-se a deletes, para contabilizar no final.
    for (int i=0;i<cont_a;i++){
        for (int j=0;j<cont_b;j++){
            if (palavra_a[i]==palavra_b[j]&&palavra_a[i]!=' '){
                palavra_b[j]=' ';
                deletes++;
            }
        }
    }

    //print final
    printf("\n Apos deletarmos todos os caracteres comuns sobrou:\n\n");
    for (int i=0;i<2;i++){
        printf("\t- Sua %da string: ",i+1);
        if (!i) printf("%s\n",palavra_a);
        else printf("%s\n",palavra_b);
    }
  
    //floreio ascii para visualizar o tamanho da string original e o quanto foi deletado.
    printf("        |-regua- - - - - 1");
    for (int i=1;i<=cont_b;i++){
        if (i==5) printf("   5");
        if (i==10) printf("   10");
        if (i>10&&i%10==0) printf("        %2d",i);
        if (i==cont_b){
            for (int j=0;j<(cont_b%10)-1;j++) printf(" ");
            printf("|\n Por sinal, deletamos %2d caracteres!, de %2d da 2a string.\n\n",deletes, cont_b+1);
        }

    }

    return 0;
}
