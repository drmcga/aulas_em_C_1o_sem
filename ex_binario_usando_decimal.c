/*
ENUNCIADO

        Na transformação decimal para binário, modifique o programa para que este obtenha o
    valor binário em uma variável inteira, ao invés de imprimir os dígitos um por linha na
    tela. Dica: Suponha n = 7 (111 em binário), e você já computou x = 11, para "inserir"o
    último dígito 1 em x você deve fazer x = x + 100. Ou seja, você precisa de uma variável
    acumuladora que armazena as potências de 10: 1, 10, 100, 1000 etc.

*/


#include <stdio.h>
#include <stdlib.h>

int main()
{

    //declarar as variaveis
    int valor_n, ultima_pot, casa_decimal, soma_binaria=0, j;

    //chamar o input
    printf("Digite o valor n para converte-lo em binario\n");
    scanf("%d",&valor_n);

    printf("\nO valor binario de %d e: ",valor_n);

    /*aqui e um sistema interesante:
        1: verifica se o numero ainda e transformavel
            a: extrai valores binarios do numero inicial ou transformado
            b: incrementa uma variavel J, multipla de 10, para dar valores de dezenas no numero 'binario'
        encerra os processos, transforma o valor original e recomeca o loop se possivel, ate acabar.
    */

    while (valor_n>0){
        j=1;
        casa_decimal=0;

        
        for (int i=1;i<=valor_n;i*=2){
            ultima_pot=i;
            casa_decimal++;

            
        }for (int i=1;i<=casa_decimal;i++){
            if (i==casa_decimal) {soma_binaria+=j;}
            j*=10;
            
        }
        valor_n-=ultima_pot;
    }
    //segunda parte do printf
    printf("%d\n",soma_binaria);

    return 0;

}
