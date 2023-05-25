/*
 *       ENUNCIADO
 *
 *      Implemente a funcao pot_de(float *num, int exp), que fornece
 *      a potencia EXP de uma certa base NUM.
*/
#include <stdio.h>
#include <stdlib.h>

//sem pre-load da funcao porque quero dar enfase para ela
//e porque nao sei enunciar as funcoes direito ainda.

//usamos um void porque nao me interessa o return
//usamos um float para trabalhar com todos os reais, nao so naturais ou inteiros.
//e usamos um int no expoente porque nao sei implementar raiz quadrada ainda
void pot_de(float *num, int exp){

    float origem=*num;
    for (int i=1;i<exp;i++){
        *num*=origem;
    }
}

int main(){

    //declaracoes de variaveis
    float base;
    int expoente=4;
    
    //print de apresentacao
    printf(" Insira um numero real e a potencia desejada, no formato:\n\t< BASE+ESPACO+EXPOENTE>\n\n\t\t-->> ");

    //registro dos valores desejados
    scanf("%f %d",&base, &expoente);

    //inicio do print final
    //ele vem antes porque usamos a mesma variavel,
    //como alteramos sem valor sem salva-la, e mais facil so puxar o print pra agora mais cedo.
    printf("\n  BASE: %3.2f //", base);
    
    //chamada da funcao, com direito a ponteiro e registro pra mudar o valor original
    pot_de(&base, expoente);

    //final do print final
    printf(" EXPOENTE: %3d // RESULTADO: %3.2f\n\n",expoente, base);


    return 0;
}
