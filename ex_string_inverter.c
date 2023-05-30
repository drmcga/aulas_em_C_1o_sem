/*
 *       ENUNCIADO
 *
 *      Faca um inversor de strings que faca alteracoes na proria string.
 *
*/
#include <stdio.h>
#include <stdlib.h>

int main(){

    //enunciacao das variaveis da string
    char palavra[99], primeira, ultima;
    
    //variavel auxiliar
    int cont=0;

    //anuncio da funcao do codigo
    printf("\nInsira aqui uma string que deseja inverter:\n\n\t\t---->>> ");
    
    //coleta o input
    gets(palavra);

    //loop para obter o tamanho da string que independe do strlen()
    for (int i=0;palavra[i]!='\0';i++){
        cont++;
    }

    //loop para inverter as duas letras
    //guardamos a primeira e a ultima letra/caractere
    //depois invertemos o valor, no mesmo loop.
    for (int i=0;i<cont/2;i++){
        //guardar
        primeira=palavra[i];
        ultima=palavra[cont-i-1];
    
        //inverter
        palavra[i]=ultima;
        palavra[cont-i-1]=primeira;
    }
    
    //printf final
    printf("\nSua palavra invertida e: %s",palavra);

    return 0;
}

