#include <stdio.h>
#include <conio.h>


int main(void){
    //Valor � a variavel que
    //ser� apontada pelo ponteiro
    int valor = 30;

    //declara��o de variavel ponteiro
    int *ptr;

    //atribuindo o endere�o da variavel valor ao ponteiro
    ptr = &valor;

    printf("Utilizando ponteiro\n\n");
    printf("Conteudo da variavel valor: %d\n", valor);
    printf("Endere�o da variavel valor: %x \n", &valor);
    printf("Conteudo da variavel ponteiro: %x", ptr);

    getch();
    return 0;

}
