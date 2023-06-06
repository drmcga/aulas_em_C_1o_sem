/*
 *      ENUNCIADO
 *
 *       Historicamente César foi o primeiro a codificar mensagens. Ele reorganizava o texto de
 *       suas mensagens de maneira que o texto parecia não ter sentido. Cada mensagem sempre
 *       possuía uma contagem de letras cujo total equivalia a um quadrado perfeito, dependendo
 *       de quanto César tivesse que escrever. Assim, uma mensagem com 16 caracteres usava
 *       um quadrado de quatro por quatro; se fossem 25 caracteres, seria cinco por cinco; 100
 *       caracteres requeriam um quadrado de dez por dez, etc. Seus oficiais sabiam que deviam
 *       transcrever o texto preenchendo as casas do quadrado sempre que uma mensagem aleatória
 *       chegasse. Ao fazerem isso, podiam ler a mensagem na vertical e seu sentido se tornaria
 *       claro.
 *
 *       Escreva um programa que lê o tamanho de uma string e em seguida uma string. Depois o
 *       programa escreve a mensagem decifrada.
 *       Exemplo:
 *
 *       36
 *       MEEUMOCSHMSC1T*AGU0A***L2****T*****A
 *
 *       Esta mensagem pode ser transcrita em um quadrado perfeito 6x6.
 *
 *       M E E U M O
 *       C S H M S C
 *       1 T * A G U
 *       0 A * * * L
 *       2 * * * * T
 *       * * * * * A
 *
 *       Lendo cada coluna da matriz (desconsiderando o caractere ’*’), a saída deve ser:
 *
 *           MC102 ESTA EH UMA MSG OCULTA.
 *
*/

/*

Codigos interessantes para decifrar e seus respectivos formatos em matriz:
    1-
    input:
        16
        naeso**esqf*sua*
    formato matriz (nao usado)
        n a e s
        o * * e
        s q f *
        s u a *
    output:
        nossa que fase

    2-
    input:
        49
        ed**smvsi*iseisgmnasueoutnm!**ieto!cetre*!o*oe***
    formato matriz (nao usado)
        e d * * s m v
        s i * i s e i
        s g m n a s u
        e o u t n m !
        * * i e t o !
        c e t r e * !
        o * o e * * *
    output:
        esse codigo e muito interessante mesmo viu!!!

    3-
    input:
        9
        *laqel*g*
    formato matriz (nao usado)
        * l a
        q e l
        * g *
    output:
        q legal

*/


#include <stdio.h>
#include <stdlib.h>

int main(){

    //variavel de pontape
    int quad_i=0;
    char enter;

    //explicacao sobre a funcao do programa
    printf("\n  Esse programa lhe permite descodificar mensagens ocultas.");
    printf("\nPara tanto, insira o tamanho, em quadrado perfeito, da sua mensgem:\n\n -->> ");

    //obtencao do tamanho do codigo
    scanf("%d",&quad_i);
    fflush(stdin);


    //obtencao do codigo
    char codigo[9999];
    int simp_i;
    printf("\nDigite agora a sua mensagem em codigos para que ela seja transcrita!\n\n-->> ");

    fgets(codigo,9999,stdin);

    //analise da raiz quadrada do quadrado perfeito
    //analise da raiz quadrada do quadrado perfeito
    for (int i=1;i<=(quad_i/2);i++){
        if (i*i==quad_i) {
            simp_i=i;
            break;
        }
    }

    char resposta[quad_i];
    int espc_rec=1, k=0;

    //loop mprincipal de decodificacao:
        //percorremos o codigo inteiro,
            //fazemos as quebras nas medidas de simp_i
        //verificamos se e uma palavra valida ou *
            //criamos uma string resposta com base apenas nas palavras
    for (int i=0;i<simp_i;i++){                     //roda os topos de coluna
        for (int j=i;j<quad_i;j+=simp_i){           //desce cada coluna

            if (codigo[j]!='*'){                    //se encontrar um caractere util
                resposta[k]=codigo[j];              //adiciona-se ao vetor resposta
                k++;
                espc_rec=0;                         //libera a possibilidade de criar outro espaco

            }else if (!espc_rec){                   //caso seja um caractere inutil, E caso possamos colocar espacos
                resposta[k]=' ';                    //adiciona-se espaco ao vetor
                espc_rec=1;
                k++;
            }
        }
    }

    //acertando o ultimo caractere do codigo.
    if (resposta[k-1]==' ') resposta[k-1]='\0';
    else resposta[k]='\0';

    //printf final
    printf("\n\nSeu codigo foi transcrito!!! A mensagem oculta e:\n-->> '");
    printf("%s'\n\n",resposta);


    return 0;
}
