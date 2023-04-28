/*
ENUNCIADO

    Implemente um codigo que pode calcular o vetor de 5 valores, 
    resultado da multiplicacao dos valores de outros 2 vetores de 5.
    os outros vetores usam numeros do usuario.

*/


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetor_a[5], vetor_b[5], vetor_temp[5], vetor_final[5], elemento;

    //introducao de um loop que: le valores para uma temporaria depois distribui.
    //o interessante desse loop e que inclui os prints adequados.
    for (int j=1;j<=2; j++){
        printf("Selecione 5 valores para o vetor %c\n\n",j+64);
         for (int i=0; i<5; i++) {
                
            printf("Valor %d do Vetor %c : ", i, j+64);
            scanf("%d", &elemento);
            vetor_temp[i]= elemento;
         }
    
    //print e assignment do quadrado do vetor
    printf("\nVetor Concluido:\n[");
    if (j==1)
        for (int s=0; s<5;s++){
            vetor_a[s] = vetor_temp[s];
            printf("%3d, ", vetor_a[s]);
        }
    
    if (j==2)
        for (int s=0; s<5;s++) {
            vetor_b[s] = vetor_temp[s];
            printf("%3d, ", vetor_b[s]);
        }
        
    //print que fecha o quadrado do vetor
    puts("\b\b]\n");
    }
    
    //print final, com o calculo incluido.
    printf("O vetor final e: \n[");
    for (int i=0;i<5; i++){
        vetor_final[i]= vetor_a[i] * vetor_b[i];
        printf("%3d, ",vetor_final[i]);
    }
    printf("\b\b]");


    return 0;
}
