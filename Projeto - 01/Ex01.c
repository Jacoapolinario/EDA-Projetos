//autor: 
// Jacó Apolinário da Silva - 16/0126177


#include<stdio.h>
#include<stdlib.h>
#define QUANTIDADE 10

void fneuronio(float *entrada, float *peso, int vetores_tamanhos, float limiar, int *agitacao);

int main() {

  	float entrada[QUANTIDADE];
  	float peso[QUANTIDADE];
  	float limiar_T;
  	int conta = 0;
  	int niveis_agitacao = 0; 
  	int *Pniveis_agitacao = &niveis_agitacao;

for(conta = 0; conta < QUANTIDADE; conta++) {
	
    printf("Digite o valor da %dº entrada: ", (conta + 1) );
    
    scanf("%f", &entrada[conta]);
   }

  	printf("\n");

for(conta = 0; conta < QUANTIDADE; conta++) {
	
    printf("Digite o valor do %dº peso: ", (conta + 1));
    
    scanf("%f", &peso[conta]);
   }

  	printf("\n");

  	printf("Escreva o valor do limiar T: ");
  
  	scanf("%f", &limiar_T);

  	printf("\n" );

fneuronio(entrada, peso, QUANTIDADE, limiar_T, Pniveis_agitacao);

  	if(niveis_agitacao == 1)
  
    	printf("Neuronio ativado!\n");
    
  	else
  
    	printf("Neuronio inibido!\n");

  	return 0;
  	
   }

void fneuronio (float *entrada, float *peso, int vetores_tamanhos, float limiar, int *agitacao) {

  int conta = 0;
  float soma_p = 0.0;

  for(conta = 0; conta < vetores_tamanhos; conta++) {
  	
    soma_p += *(entrada + conta) * *(peso + conta);
    
  }

  if(soma_p > limiar) {
  	
    *agitacao = 1;
  }


}
