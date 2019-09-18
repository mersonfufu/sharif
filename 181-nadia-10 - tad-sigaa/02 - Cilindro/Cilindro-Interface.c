#include <stdio.h>
#include "Cilindro.h"

int main(){
	float raio, altura;
	stCilindro *cilindroptr = NULL;
	
	printf("Insira raio e altura... ");
	scanf("%f %f", &raio, &altura);
	printf("\n");
	cilindroptr = criarCilindro(raio, altura);
	
//	alterarRaio(cilindroptr, 5);
//	alterarAltura(cilindroptr, 8);
	
	printf("Raio = %.2f\nAltura = %.2f\nVolume = %.2f\n",
		acessarRaio(cilindroptr), acessarAltura(cilindroptr), calcularVolume(cilindroptr)
	);
	
	cilindroptr = destruirCilindro(cilindroptr);
	
	return 0;
}