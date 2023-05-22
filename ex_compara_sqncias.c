/*
 *       ENUNCIADO
 *
 *      Dadas duas sequências de n e m valores
 *      inteiros, onde n <= m, escreva um programa
 *      que verifica quantas vezes a primeira ocorre na segunda.
 *          Exemplo:
 *              primeira sequência:     1 0 1
 *              segunda sequência:      1 1 0 1 0 1 0 0 1 1 0 1 0
 *              Resultado: 3
 *
*/
#include <stdio.h>
#include <stdlib.h>

int main(){

    //declaracoes de variaveis relacionadas as listas
    int sqcia_m[99], sqcia_n[99],  qnt_m, qnt_n;
    //declaracoes de variaveis auxiliares
    int oks, rptcoes=0;

    //bloco introdutorio
    printf("  Esse programa pode verificar quantas vezes uma sequencia\n");
    printf("  de inteiros se repete em outra sequencia distinta, para\n");
    printf("  tanto, insira aqui os tamanhos M e N, obedecendo: M >= N\n\n\t---->>");

    //insercao dos tamanhos
    scanf("%d %d",&qnt_m, &qnt_n);

    //aqui e uma dummy-proof, caso invertam a ordem e mandem o maior depois.
    if (qnt_m<qnt_n){
        int aux=qnt_m;
        qnt_m=qnt_n;
        qnt_n=aux;
        printf("\nOs numeros estavam invertidos!!!, refazendo a ordem M >= N:\n\t---->>%d %d\n\n",qnt_m,qnt_n);
    }

    //anuncio da primeira sequencia
    printf("\tAgora comecamos as sequencias,\n");

    for (int i=0;i<qnt_m;i++){
        printf("  Digite o %2d valor da sequencia M:  ",i+1); //bloco de texto alinhado e formatado
        scanf("%d", &sqcia_m[i]);
    }

    //segunda sequencia
    printf("\n\tAgora para a proxima,\n");
    for (int i=0;i<qnt_n;i++){
        printf("  Digite o %2d valor da sequencia N:  ",i+1);
        scanf("%d", &sqcia_n[i]);
    }

    //bloco de prints da sequencias m
    printf("\nSequencia M:\n [");   //eu uso muito esse formato de colchetes
    for (int i=0;i<qnt_m;i++){      //com duplo \b\b ao final do loop.
        printf("%3d, ",sqcia_m[i]); //acho estilo, para falar a verdade.
    }
    printf("\b\b ]\n");

    //bloco de prints da sequencia n
    printf("\nSequencia N:\n [");
    for (int i=0;i<qnt_n;i++){
        printf("%3d, ",sqcia_n[i]);
    }
    printf("\b\b ]\n\n");

    //verificacoes das repeticoes:
    for (int i=0;i<qnt_m-qnt_n+1;i++){
        
        //o ok e um contador interno que avalia quantas numeros repetidos
        //de cada recorte de segmentos da M sao iguais aos valores
        //da sequencia integral N.
        oks=0;

        for (int j=0;j<qnt_n;j++){                  //aqui diz caso esse valor de um recorte M seja
            if (sqcia_m[i+j]==sqcia_n[j]) oks++;    // igual ao recorte equivalente de N
        }                                           //devemos contar essa igualdade em OKS.

        if (oks==qnt_n) rptcoes++;                  //se tivermos oks para todos os segmentos, 
                                                    //significa que N se repetiu por completo!
    }
    
    //printf, com f de final.
    printf("Repeticoes: %2d\n\n",rptcoes);

    return 0;
}
