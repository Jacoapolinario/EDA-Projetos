//autor: 
// Jacó Apolinário da Silva - 16/0126177

#include <stdio.h>
#include <stdlib.h>

int hanoi( int numero,char origem, char destino, char auxiliar) {
	
	if( numero == 1) {
 	
		printf("\n""Mover disco 1 da torre  %c para  %c ", origem,destino);
		
	return 0;
	
 }
 
	hanoi( numero-1, origem, auxiliar,destino);
 
		printf("\n""Mover disco %i da torre %c para %c", numero,origem, destino);
 
	hanoi( numero-1, auxiliar,destino,origem);
 
}

void main() {
 
	int numero = 0;
 		
		printf("\n""Quantidade de Discos: ");
		
	scanf("%i",&numero);
 
		hanoi(numero, 'A','B','C');
		
		printf("\n");
 
 		printf(" Fim Da Torre! ");
 
 	scanf("%");


}
