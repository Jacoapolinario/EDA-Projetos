//autor: 
// Jacó Apolinário da Silva - 16/0126177

#include <stdio.h>
#include <stdlib.h>
#define QUANTIDADE 10

	void recebe_notas (float *notas, int *AP, int quantidade);
	void conta_notas (int *AP, int quantidade, int *aluno_aprovado, int *aluno_reprovado);
	int percent_aprov (int *aluno_aprovado, int *aluno_reprovado, float *perc_aprov, float *perc_reprov);

int main () {

    int conta = 0;
    float notas[QUANTIDADE];
    int AP[QUANTIDADE];
    int aluno_aprovado = 0;
    int aluno_reprovado = 0;
    float perc_aprov = 0.0;
    float perc_reprov = 0.0;

    for (conta = 0; conta < QUANTIDADE; conta++) {
    	
        printf("Escreva a %dº nota: ", conta + 1);
        
        scanf("%f", &notas[conta]);
    }

    recebe_notas(notas, AP, QUANTIDADE);
    
    conta_notas(AP, QUANTIDADE, &aluno_aprovado, &aluno_reprovado);

    printf("\n");

    printf("Quantidade de aprovados: %d \n",aluno_aprovado);

    printf("Quantidade de reprovados: %d \n",aluno_reprovado);

    printf("\n");

    percent_aprov (&aluno_aprovado, &aluno_reprovado, &perc_aprov, &perc_reprov);

    printf("Percentual de aprovados: %.1f%%\n", perc_aprov);

    printf("Percentual de reprovados: %.1f%%\n", perc_reprov);

    printf("\n");

    if (percent_aprov (&aluno_aprovado, &aluno_reprovado, &perc_aprov, &perc_reprov) == 1)
    
        printf("Mais da metade da turma foi APROVADA!\n");
        
    else
        printf("Mais da metade da turma foi REPROVADA!\n");

    printf("\n");

    return 0;
}

void recebe_notas ( float *notas, int *AP, int quantidade) {
    int conta = 0;

    for(conta = 0; conta < quantidade; conta++){
        if (*(notas + conta) >= 6.0)
            *(AP + conta) = 1;
        else
        
            *(AP + conta) = 0;
    }

}

void conta_notas (int *AP, int quantidade, int  *aluno_aprovado, int *aluno_reprovado) {
	
    int conta = 0;

    for (conta = 0; conta < quantidade; conta++){
    	
        if(*(AP + conta) == 1)
        
            *aluno_aprovado += 1;

        else if(*(AP + conta) == 0)
        
            *aluno_reprovado += 1;

    }

}

int percent_aprov (int *aluno_aprovado, int *aluno_reprovado, float *perc_aprov, float *perc_reprov) {
	
    *perc_aprov = ((*aluno_aprovado) / 10.00) * 100.00 ;
    *perc_reprov = ((*aluno_reprovado ) / 10.00) * 100.00;

    if (*aluno_aprovado > 5)
    
        return 1;
    else
    
        return 0;
}
