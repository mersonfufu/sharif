#include <stdio.h>
#include "Cubo.h"

int main(){
	float lado;
	stCubo *cuboptr = NULL;
	
	printf("Insira lado... ");
	scanf("%f", &lado);
	printf("\n");
	cuboptr = criarCubo(lado);
	
//	alterarLado(cuboptr, 5);
	
	printf("Lado = %.2f\nPerimetro = %.2f\nArea = %.2f\nVolume = %.2f\n",
		acessarLado(cuboptr), calcularPerimetro(cuboptr), calcularArea(cuboptr), calcularVolume(cuboptr)
	);
	
	cuboptr = destruirCubo(cuboptr);
	
	return 0;
}