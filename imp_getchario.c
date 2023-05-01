/*
    ENUNCIADO

    Implemente char getchario() <-- uma funcao equivalente a utilizar getchar(), com nome trocado


*/
#include <stdio.h>
#include <stdlib.h>

char getchario(){
    
    char letra;
    scanf("%c",&letra);
    return letra;
}



int main()
{
    char alfa;
    alfa=getchario();
    printf("%c",alfa);

    return 0;
}
