#include <stdio.h>
#include <conio.h>


int main(void){
    //Valor é a variavel que
    //será apontada pelo ponteiro
    int valor = 30;

    //declaração de variavel ponteiro
    int *ptr;

    //atribuindo o endereço da variavel valor ao ponteiro
    ptr = &valor;

    printf("Utilizando ponteiro\n\n");
    printf("Conteudo da variavel valor: %d\n", valor);
    printf("Endereço da variavel valor: %x \n", &valor);
    printf("Conteudo da variavel ponteiro: %x", ptr);

    getch();
    return 0;

}
