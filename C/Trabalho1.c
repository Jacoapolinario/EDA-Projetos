#include <stdio.h>
#include <stdlib.h>
#define  VALORES 10

void func_fneuronio(float *entradas, float *vetor_pesos, int valor_limiar, int *resultado);

    int main(){

        float entradas[VALORES], peso[VALORES], limiar_T;
        int contador = 0, resultado_agitacao;

    for(contador = 0; contador < VALORES; contador ++){

        printf("Digite a %dº entrada: ", (contador + 1));
        scanf("%f", &entradas[contador]);

    }

    for(contador = 0; contador < VALORES; contador++){

        printf("Digite o %dº peso: ", (contador + 1));
        scanf("%f", &peso[contador]);

    }

        printf("Digite o Limiar T: ");
        scanf("%f", &limiar_T);

fneuronio(entradas, &peso, VALORES, limiar_T, &resultado_agitacao);

        if(resultado_agitacao == 1)

           printf("Neuronio Ativado!\n");
        else

            printf("Neuronio Inibido!\n");

        return 0;
}

void func_fneuronio(float *entradas, float *vetor_pesos, int max, int valor_limiar, int *resultado_agitacao){

    int contador = 0;
    float somap;

    for(contador = 0; contador < max; contador++){

        somap += entradas[contador] * vetor_pesos[contador];

    }

    if(somap > valor_limiar){

        *resultado_agitacao = 1;
    }else{

        *resultado_agitacao = 0;

    }

}

