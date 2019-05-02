#include <stdio.h>
#include <stdlib.h>


double calcula(int x, int p);

int main(void){

    int numero1, numero2;
    double v;

    printf("Digite um numero: ");
    scanf("%d %d", &numero1, &numero2);

    v = calcula(numero1, numero2);

    printf("O calculo de %d eh %d == %.01f \n", numero1, numero2, v);

    system("pause");

    return 0;

}

double calcula(int x, int p){

    double resultado;

    if(x == 0)
        return(1);
    else{
        resultado = x * calcula(p,x-1);
        return(resultado);
    }

}
