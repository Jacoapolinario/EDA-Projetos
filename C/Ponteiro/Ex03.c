#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int main (int argc, char *argv[]){

    int i, x[MAX];
    int valores;

    printf("Digite os valores: ");
    scanf("%d", &valores);

    printf("Endereco\t conteudo\t \n");

    x[MAX] = valores;

    for (i = 0; i<MAX; i++)
        printf("%d\t\t %d\t \n", &x[i], x[i]);

}
