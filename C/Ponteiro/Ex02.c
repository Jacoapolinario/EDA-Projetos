#include <stdio.h>

int main(void){

    int entradas[3];
    int pesos[3];
    int *ponteiro, *ponteiro2;
    int i, fneuronio = 0;
    int valor_peso1, valor_peso2;

    ponteiro = &entradas[0];
    ponteiro2 = &pesos[0];
    printf("fneuroniv = ");

    for( i = 0; i < 3; i++){
        scanf("%d", &valor_peso1, &valor_peso2);
        entradas[valor_peso1];
        pesos[valor_peso2];
    }

    for (i = 0; i < 3; i++){

        printf("%d * %d + ", ponteiro[i], ponteiro2[i]);
        fneuronio = + ponteiro[i] * ponteiro2[i];

    }
    printf("Resultado: %d", fneuronio);




return 0;

}
